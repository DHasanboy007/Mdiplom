#include <stdio.h>
#include <windows.h>
#include "LS625_Agt.h"
#include "ni488.h"

//extern int GPIB_SendCommand(int addr, const char *cmd, int len);
//extern int GPIB_Read(int addr, char * Buff, int MaxLen);

static int LSaddr = 12;

float GetCoeffLS625()
{
    char Responce[256];
    char buf[] = "FLDS?";
    DWORD Units = 0;
    float Coeff = 0.0f;

    GPIB_SendCommand(LSaddr, buf, strlen(buf));
    GPIB_Read(LSaddr, Responce, 256);

    sscanf_s(Responce, "%u,%f", &Units, &Coeff);
    if (Units == 1) Coeff /= 10.0f; //Перевод килогауссов в теслы
    return Coeff;
}

long GetDISPLS625(DWORD* Mode, DWORD* VoltSense, DWORD* Brightness)
{
    char Responce[256];
    char buf[] = "DISP?";

    GPIB_SendCommand(LSaddr, buf, strlen(buf));
    GPIB_Read(LSaddr, Responce, 256);

    sscanf_s(Responce, "%u,%u,%u", Mode, VoltSense, Brightness);
    return ThreadIbsta();
}

long SetILS625(float I)
{
    char SI[256];
    sprintf_s(SI, "seti %f", I);
    GPIB_SendCommand(LSaddr, SI, strlen(SI));
    return ThreadIbsta();
}

long SetCoeffLS625(float Coeff)
{
    char Str[256];
    sprintf_s(Str, "FLDS 0, %f", Coeff);
    GPIB_SendCommand(LSaddr, Str, strlen(Str));
    return ThreadIbsta();
}

long SetDISPLS625(DWORD Mode, DWORD VoltSense, DWORD Brightness)
{
    char Str[256];
    sprintf_s(Str, "DISP %u, %u, %u", Mode, VoltSense, Brightness);
    GPIB_SendCommand(LSaddr, Str, strlen(Str));
    return ThreadIbsta();
}

float ReadOutputCurrLS625()
{
    char Responce[256];
    char buf[] = "rdgi?";

    GPIB_SendCommand(LSaddr, buf, strlen(buf));
    GPIB_Read(LSaddr, Responce, 256);

    return (float)atof(Responce);
}

long SetRampLS625(float R)
{
    char SR[256] = "";

    sprintf_s(SR, "rate %f", R);
    GPIB_SendCommand(LSaddr, SR, strlen(SR));
    return ThreadIbsta();
}

BOOL FindLS625()
{
    Addr4882_t AddrList[2] = { LSaddr, NOADDR };
    short ResultList[2];
    char buf[] = "*IDN?";
    char responce[256];

    FindLstn(0, AddrList, ResultList, 1);
    if (!(ThreadIbsta() & ERR))
    {
        EnableRemote(0, AddrList);

        GPIB_SendCommand(LSaddr, buf, strlen(buf));
        GPIB_Read(LSaddr, responce, 256);

        responce[13] = 0;
        if (strcmp(responce, "LSCI,MODEL625") == 0) return TRUE;
        else return FALSE;
    }
    else return FALSE;
}

void OpenLS625()
{
    Addr4882_t AddrList[2] = { LSaddr, NOADDR };
    EnableRemote(0, AddrList);
}

void CloseLS625()
{
    Addr4882_t AddrList[2] = { LSaddr, NOADDR };
    EnableLocal(0, AddrList);
}