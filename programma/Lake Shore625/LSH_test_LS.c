#include <stdio.h>
#include "wiringRP.h"
#include "serial.h"
#include "gpib.h"
#include "LS625_Agt.h"

int main(int argc, char *argv[])
{
    InitGPIB();
    delay(2000);

    // ================= DEVICE CHECK =================
    if (FindLS625())
    {
        printf("LS625 FOUND\n");
    }
    else
    {
        printf("LS625 NOT FOUND\n");
        CloseGPIB();
        return 1;
    }

    // ================= INITIALIZATION =================
    InitCurrLS625();   // yoki InitMagLS625(), konfiguratsiyaga qarab
    delay(1000);

    // ================= MEASUREMENT =================
    printf("I = %f\n", ReadOutputCurrLS625());
    printf("I = %f\n", ReadOutputCurrLS625());

    // ================= CLOSE =================
    CloseGPIB();

    return 0;
}