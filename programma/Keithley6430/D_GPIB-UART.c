#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "gpib.h"

// ================= KONSTANTA =================
const int Keithley6430 = 24;

// internal state
static char buf[256];
static char response[256];

// ================= RESET =================
void Reset_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "*rst", 4);
}

// ================= OUTPUT CONTROL =================
void OutputON_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "outp 1", 6);
}

void OutputOFF_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "outp 0", 6);
}

int OutputStat_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "outp?", 5);
    GPIB_Read(Keithley6430, response, 256);

    return (response[0] == '1') ? 1 : 0;
}

// ================= SOURCE VOLTAGE =================
void InitV_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "sour:func volt", 14);
    GPIB_SendCommand(Keithley6430, "sour:volt:mode fix", 19);
    GPIB_SendCommand(Keithley6430, "sens:func \"curr\"", 17);
    GPIB_SendCommand(Keithley6430, "sens:curr:rang:auto 1", 22);
}

void SetV_Keithley6430(float V)
{
    sprintf(buf, "sour:volt %e", V);
    GPIB_SendCommand(Keithley6430, buf, strlen(buf));
}

// ================= SOURCE CURRENT =================
void InitI_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "sour:func curr", 14);
    GPIB_SendCommand(Keithley6430, "sour:curr:mode fix", 19);
    GPIB_SendCommand(Keithley6430, "sens:func \"volt\"", 17);
    GPIB_SendCommand(Keithley6430, "sens:volt:rang:auto 1", 22);
}

void SetI_Keithley6430(float I)
{
    sprintf(buf, "sour:curr %e", I);
    GPIB_SendCommand(Keithley6430, buf, strlen(buf));
}

// ================= MEASUREMENT =================
float GetV_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "read?", 5);
    GPIB_Read(Keithley6430, response, 256);

    return (float)atof(response);
}

float GetI_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "read?", 5);
    GPIB_Read(Keithley6430, response, 256);

    return (float)atof(response);
}

// ================= GAIN (I/V) =================
float GetG_Keithley6430(float* Curr)
{
    float V, I;

    GPIB_SendCommand(Keithley6430, "read?", 5);
    GPIB_Read(Keithley6430, response, 256);

    V = (float)atof(response);

    // second read (SMU real mode)
    GPIB_Read(Keithley6430, response, 256);
    I = (float)atof(response);

    if (Curr != NULL)
        *Curr = I;

    if (V == 0)
        return 0;

    return I / V;
}

// ================= SPEED (NPLC) =================
void SetVSpeed_Keithley6430(float NPLC)
{
    sprintf(buf, "sens:volt:nplc %e", NPLC);
    GPIB_SendCommand(Keithley6430, buf, strlen(buf));
}

void SetISpeed_Keithley6430(float NPLC)
{
    sprintf(buf, "sens:curr:nplc %e", NPLC);
    GPIB_SendCommand(Keithley6430, buf, strlen(buf));
}

// ================= DEVICE CHECK =================
int Find_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "*IDN?", 5);
    GPIB_Read(Keithley6430, response, 256);

    if (strstr(response, "6430") != NULL)
        return 1;

    return 0;
}

// ================= CLEAN MODE =================
void Close_Keithley6430()
{
    GPIB_SendCommand(Keithley6430, "outp 0", 6);
}