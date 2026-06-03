#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wiringRP.h"
#include "serial.h"
#include "gpib.h"

// ================= DEVICE ADDRESS =================
#define K6514_ADDR 14

// ==================== INIT ====================
void setup() {
    char Buff[256];
    int Err;

    if (setupWiringRP(WRP_MODE_SUNXI) < 0) {
        printf("WIRING INIT ERROR\n");
        exit(1);
    }

    uart2_fd = serialSetup(2, BAUD_115200);

    if (uart2_fd < 0) {
        printf("UART INIT ERROR\n");
        exit(1);
    }

    serialFlush(uart2_fd);
    delay(2000);

    // ================= ID CHECK =================
    Err = GPIB_SendCommand(K6514_ADDR, "*IDN?", 5);
    printf("*IDN? %i\n", Err);

    delay(2000);

    Err = GPIB_Read(K6514_ADDR, Buff, 256);
    printf("Read %i\n", Err);

    delay(1000);
    printf("Buff = %s\n", Buff);

    if (strstr(Buff, "6514") != NULL)
        printf("Прибор найден\n");
    else
        printf("Прибор не найден\n");

    // ================= RESET =================
    Err = GPIB_SendCommand(K6514_ADDR, "*RST", 4);
    printf("*RST %i\n", Err);

    delay(5000);

    // ================= ZERO CHECK  =================
    Err = GPIB_SendCommand(K6514_ADDR, "SYST:ZCH OFF", strlen("SYST:ZCH OFF"));
    printf("ZERO CHECK OFF %i\n", Err);

    delay(1000);

    // ================= CURRENT MODE =================
    Err = GPIB_SendCommand(K6514_ADDR, "SENS:FUNC \"CURR\"", strlen("SENS:FUNC \"CURR\""));
    printf("CURR MODE %i\n", Err);

    delay(1000);

    Err = GPIB_SendCommand(K6514_ADDR, "SENS:CURR:RANG:AUTO ON", strlen("SENS:CURR:RANG:AUTO ON"));
    printf("AUTO RANGE %i\n", Err);

    delay(1000);

    Err = GPIB_SendCommand(K6514_ADDR, "SENS:CURR:NPLC 1", strlen("SENS:CURR:NPLC 1"));
    printf("NPLC SET %i\n", Err);

    delay(1000);

    // ================= MEASURE =================
    Err = GPIB_SendCommand(K6514_ADDR, "READ?", 5);
    GPIB_Read(K6514_ADDR, Buff, 256);

    printf("MEAS = %s\n", Buff);

    serialPrintf(uart2_fd, "$0");
}

// ==================== LOOP ====================
void loop() {
    // optional continuous measurement
}

// ==================== CLEANUP ====================
ONDESTROY() {
    serialRelease(uart2_fd);
    releaseWiringRP();
    exit(0);
}

// ==================== MAIN ====================
MAIN_WIRINGRP();