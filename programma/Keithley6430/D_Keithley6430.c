#include <stdio.h>
#include <windows.h>
#include "K6430_Agt.h"
#include "ni488.h"

//extern int GPIB_SendCommand(int addr, const char *cmd, int len);
//extern int GPIB_Read(int addr, char * Buff, int MaxLen);

int smuad = 24;
bool ARFlag = true;
char responce[256], voltage[256], current[256];
long stat, limit;
DWORD len;
float VSmu, OldVSmu, ISmu;

float GetG(float* Curr)
{
    char cmd[10] = "read?";
    GPIB_SendCommand(smuad, cmd, strlen(cmd));
    GPIB_Read(smuad, responce, 256);

    for (long count = 0; count < 13; ++count)
    {
        voltage[count] = responce[count];
        current[count] = responce[count + 14];
    }
    voltage[13] = 0;
    current[13] = 0;
    VSmu = (float)atof(voltage);
    ISmu = (float)atof(current);
    if (Curr != NULL) *Curr = ISmu;
    return ISmu / VSmu;
}

void SetIsourcing(float I)
{
    char buf[256];
    strcpy_s(buf, "sour:func curr");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(buf, "sour:curr:mode fix");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    sprintf_s(buf, "sour:curr %e", I);
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void SetVsourcing(float V)
{
    char buf[256];
    strcpy_s(buf, "sour:func volt");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(buf, "sour:curr:mode fix");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    sprintf_s(buf, "sour:volt %e", V);
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

long SourcStat()
{
    char buf[256];
    strcpy_s(buf, "source:function:mode?");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    GPIB_Read(smuad, responce, 256);

    if (strcmp(responce, "VOLT") == 0) return 1;
    else if (strcmp(responce, "CURR") == 0) return 2;
    else return 0;
}

void SetVMeasuring()
{
    char buf[256];
    strcpy_s(buf, "sense:func \"volt\"");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(buf, "sense:volt:rang:auto 1");
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void SetIMeasuring()
{
    char buf[256];
    strcpy_s(buf, "sense:func \"curr\"");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(buf, "sense:curr:rang:auto 1");
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(buf, "sense:curr:prot 105e-3");
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

float GetV()
{
    char buf[] = "read?";
    GPIB_SendCommand(smuad, buf, strlen(buf));

    GPIB_Read(smuad, responce, 256);

    for (long count = 0; count < 13; ++count)
    {
        voltage[count] = responce[count];
    }
    voltage[13] = 0;
    VSmu = (float)atof(voltage);
    return VSmu;
}

float GetI()
{
    char buf[] = "read?";
    GPIB_SendCommand(smuad, buf, strlen(buf));

    GPIB_Read(smuad, responce, 256);

    for (long count = 0; count < 13; ++count)
    {
        current[count] = responce[count + 14];
    }
    current[13] = 0;
    ISmu = (float)atof(current);
    return ISmu;
}

void OutputON()
{
    char buf[] = "outp 1";
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void OutputOFF()
{
    char buf[] = "outp 0";
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

BOOL OutputStat()
{
    char buf[] = "outp?";
    GPIB_SendCommand(smuad, buf, strlen(buf));

    strcpy_s(responce, "");
    GPIB_Read(smuad, responce, 256);

    if (responce[0] == '1') return TRUE;
    else return FALSE;
}

void ResetSMU()
{
    char buf[] = "*rst";
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

BOOL FindSMU()
{
    char buf[] = "*IDN?";
    GPIB_SendCommand(smuad, buf, strlen(buf));

    GPIB_Read(smuad, responce, 256);

    if (strstr(responce, "6430") != NULL) return TRUE;
    else return FALSE;
}

void SetISpeed(float NPLC)
{
    char buf[256] = "";
    sprintf_s(buf, "sens:curr:nplc %e", NPLC);
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void SetVSpeed(float NPLC)
{
    char buf[256] = "";
    sprintf_s(buf, "sens:volt:nplc %e", NPLC);
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void AutoRangeOn()
{
    ARFlag = TRUE;
}

void AutoRangeOff()
{
    ARFlag = FALSE;
}

void RangeUp()
{
    char buf[] = "sense:volt:rang up";
    GPIB_SendCommand(smuad, buf, strlen(buf));
}

void RangeDown()
{
    char buf[] = "sense:volt:rang down";
    GPIB_SendCommand(smuad, buf, strlen(buf));
}