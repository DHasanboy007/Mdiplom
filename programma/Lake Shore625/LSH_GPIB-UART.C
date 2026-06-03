#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wiringRP.h"
#include "serial.h"

int uart2_fd;

// ==================== SEND  ====================
int GPIB_SendCommand(int addr, const char *cmd, int len) {
 int cnt = 0;
 int ErrSt = 0;

    serialPrintf(uart2_fd, "$1$3#%c", addr+32);   // REN + ADDRESS
    while (serialDataAvail(uart2_fd)>0)
      if (serialGetchar(uart2_fd) == 2) ErrSt = 1;

    serialPrintf(uart2_fd, "$2");                 // DATA MODE

    for(cnt = 0; cnt < len; ++cnt)
    {
        serialPrintf(uart2_fd, "#%c", cmd[cnt]);
        while (serialDataAvail(uart2_fd)>0)
            if (serialGetchar(uart2_fd) == 2) ErrSt = 1;
    }

    serialPrintf(uart2_fd, "#\r");     // COMMAND + END
    while (serialDataAvail(uart2_fd)>0)
        if (serialGetchar(uart2_fd) == 2) ErrSt = 1;

    serialPrintf(uart2_fd, "#\n");     // COMMAND + END
    while (serialDataAvail(uart2_fd)>0)
        if (serialGetchar(uart2_fd) == 2) ErrSt = 1;

    return ErrSt;
}

// ==================== READ ====================
int GPIB_Read(int addr, char * Buff, int MaxLen) {
 int ErrSt = 0;
 char BufChar = 0;
 int cnt = 0;

    serialPrintf(uart2_fd, "$3#%c", addr+64);   // ADDRESS
    while (serialDataAvail(uart2_fd)>0)
      if (serialGetchar(uart2_fd) == 2) ErrSt = 1;

    serialPrintf(uart2_fd, "$2");

    while (BufChar != 10)
    {
        serialPrintf(uart2_fd, "$8");

        BufChar = serialGetchar(uart2_fd);

        if (BufChar == 1) {
            ErrSt = 1;
            break;
        }

        if (BufChar != 3) {
            Buff[cnt++] = BufChar;
        }

        if (cnt >= MaxLen) {
            ErrSt = 1;
            break;
        }
    }

    Buff[cnt] = 0;
    return ErrSt;
}

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

    // ================= LS625 DEVICE ADDRESS =================
    int LSaddr = 12;

    // ================= DEVICE IDENTIFY =================
    Err = GPIB_SendCommand(LSaddr, "*IDN?", 5);
    printf("*IDN? %i\n", Err);

    delay(2000);

    Err = GPIB_Read(LSaddr, Buff, 256);
    printf("Read %i\n", Err);
    printf("Buff = %s\n", Buff);

    if (strstr(Buff, "LSCI") != NULL || strstr(Buff, "625") != NULL)
        printf("LS625 FOUND\n");
    else
        printf("LS625 NOT FOUND\n");

    // ================= RESET =================
    Err = GPIB_SendCommand(LSaddr, "*RST", 4);
    printf("*RST %i\n", Err);

    delay(5000);

    // ================= FIELD MODE INIT =================
    Err = GPIB_SendCommand(LSaddr, "FLDS?", 5);
    printf("FLDS? %i\n", Err);

    delay(2000);

    // ================= CURRENT SET DEFAULT =================
    Err = GPIB_SendCommand(LSaddr, "SETI 0.0", 8);
    printf("SETI %i\n", Err);

    delay(2000);

    serialPrintf(uart2_fd, "$0");
}

// ==================== LOOP ====================
void loop() {
    // LS625 continuous read example
    /*
    char Buff[256];
    GPIB_SendCommand(12, "RDGI?", 5);
    GPIB_Read(12, Buff, 256);
    printf("I = %s\n", Buff);
    delay(1000);
    */
}

// ==================== CLEANUP ====================
ONDESTROY() {
    serialRelease(uart2_fd);
    releaseWiringRP();
    exit(0);
}

// ==================== MAIN ====================
MAIN_WIRINGRP();