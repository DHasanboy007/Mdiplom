#include <stdio.h>
#include "wiringRP.h"
#include "serial.h"
#include "gpib.h"
#include "K6514_Agt.h"   

int main(int argc, char *argv[])
{
    InitGPIB();
    delay(2000);

    if (FindK6514())
    {
        printf("Прибор Keithley 6514 найден\n");
    }
    else
    {
        printf("Прибор не найден\n");
        CloseGPIB();
        return 1;
    }

    InitVK6514();   

    printf("V = %f\n", GetVK6514());
    printf("V = %f\n", GetVK6514());

    CloseGPIB();

    return 0;
}