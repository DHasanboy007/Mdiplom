#include <stdio.h>
#include "wiringRP.h"
#include "serial.h"
#include "gpib.h"
#include "K6430.h"

int main(int argc, char *argv[])
{
    InitGPIB();
    delay(2000);

    if (FindSMU())
    {
        printf("Прибор Keithley 6430 найден\n");
    }
    else
    {
        printf("Прибор не найден\n");
        CloseGPIB();
        return 1;
    }

    ResetSMU();
    delay(2000);

    SetVMeasuring();
    OutputON();

    printf("V = %f\n", GetV());
    printf("I = %f\n", GetI());

    OutputOFF();
    CloseGPIB();

    return 0;
}