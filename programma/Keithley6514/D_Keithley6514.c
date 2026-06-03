#include <stdio.h>
#include "D_keithley_gpib.h"
#include <math.h>
#include "K6514_Agt.h"
#include <string.h>

//extern int GPIB_SendCommand(int addr, const char *cmd, int len);
//extern int GPIB_Read(int addr, char * Buff, int MaxLen);

const int PosK6514 = 14;
static const float a[11] = { 0.0f, 20e-12f, 200e-12f, 2e-9f, 20e-9f, 200e-9f, 2e-6f, 20e-6f, 200e-6f, 2e-3f, 20e-3f };
static const char as[11][8] = { "200e-12", "200e-12", "20e-9", "20e-9", "200e-9", "2e-6", "20e-6", "200e-6", "2e-3", "20e-3" };
static int LowLimit = 9;
static int HiLimit = 10;

void InitIK6514()
{
    char buf[256] = "*rst";
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "syst:zch on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "func \"curr\"");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "form:elem read");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "curr:rang ");
    strcat_s(buf, as[10]);
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "curr:nplc 1");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));
}

float GetIK6514()
{
    char read[256];
    float I;
    int n;

    char buf[256] = "syst:zch off";
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "read?");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    GPIB_Read(PosK6514, read, 256);

    I = (float)atof(read);

    if (I == 0)
        do {
            LowLimit++;
            HiLimit++;

            strcpy_s(buf, "curr:rang ");
            strcat_s(buf, as[HiLimit]);
            GPIB_SendCommand(PosK6514, buf, strlen(buf));

            strcpy_s(buf, "read?");
            GPIB_SendCommand(PosK6514, buf, strlen(buf));

            GPIB_Read(PosK6514, read, 256);

            I = (float)atof(read);

        } while (I == 0);

    if ((a[LowLimit] > fabs(I)) || (fabs(I) >= 1.05 * a[HiLimit]))
    {
        do {
            n = -1;
            do {
                n++;
            } while ((a[n] > fabs(I)) || (fabs(I) >= 1.05 * a[n + 1]));

            LowLimit = n;
            HiLimit = n + 1;

            strcpy_s(buf, "curr:rang ");
            strcat_s(buf, as[HiLimit]);
            GPIB_SendCommand(PosK6514, buf, strlen(buf));

            strcpy_s(buf, "read?");
            GPIB_SendCommand(PosK6514, buf, strlen(buf));

            GPIB_Read(PosK6514, read, 256);

            I = (float)atof(read);

        } while (I == 0);
    }

    return I;
}

void InitVK6514()
{
    char buf[256] = "*rst";
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "syst:zch on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "func \"volt\"");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "form:elem read");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "volt:rang:auto on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "volt:nplc 1");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "syst:zch off");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));
}

void InitVGK6514()
{
    char buf[256] = "*rst";
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "syst:zch on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "func \"volt\"");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "volt:guar on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "form:elem read");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "volt:rang:auto on");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "volt:nplc 1");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));

    strcpy_s(buf, "syst:zch off");
    GPIB_SendCommand(PosK6514, buf, strlen(buf));
}

float GetVK6514()
{
    char read[256];
    char buf[] = "read?";

    GPIB_SendCommand(PosK6514, buf, strlen(buf));
    GPIB_Read(PosK6514, read, 256);

    return (float)atof(read);
}

void CloseK6514()
{
    char buf[] = "syst:zch on";
    GPIB_SendCommand(PosK6514, buf, strlen(buf));
}

void SetVSpeedK6514(float NPLC)
{
    char NPLCStr[256];

    sprintf_s(NPLCStr, "sens:volt:nplc %e", NPLC);
    GPIB_SendCommand(PosK6514, NPLCStr, strlen(NPLCStr));
}

BOOL FindK6514()
{
    char buf[] = "*IDN?";
    char responce[256];

    GPIB_SendCommand(PosK6514, buf, strlen(buf));
    GPIB_Read(PosK6514, responce, 256);

    if (strstr(responce, "6514") != NULL) return TRUE;
    else return FALSE;
}