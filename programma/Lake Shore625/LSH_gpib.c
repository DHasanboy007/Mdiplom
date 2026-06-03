#include <stdio.h>
#include <stdlib.h>
#include "wiringRP.h"
#include "serial.h"
#include "gpib.h"

int uart2_fd;
int InitGPIB()
{
        if (setupWiringRP(WRP_MODE_SUNXI) < 0) {
        printf("WIRING INIT ERROR\n");
        return 1;
    }

    uart2_fd = serialSetup(2, BAUD_115200);

    if (uart2_fd < 0) {
        printf("UART INIT ERROR\n");
        return 1;
    }
    serialFlush(uart2_fd);
    return 0;
}
int GPIB_SendCommand(int addr, const char *cmd, int len) {
    int cnt = 0;
    int ErrSt = 0;
    serialPrintf(uart2_fd, "$1$3#%c", addr+32);   // ADDRESS
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

int GPIB_Read(int addr, char * Buff, int MaxLen) {
    int ErrSt = 0;
    char BufChar0 = 0;
    char BufChar = 0;
    int cnt = 0;
//    serialFlush(uart2_fd);
    serialPrintf(uart2_fd, "$3#%c", addr+64);   // ADDRESS
    while (serialDataAvail(uart2_fd)>0)
      if (serialGetchar(uart2_fd) == 2) ErrSt = 1;
    serialPrintf(uart2_fd, "$2");
    while (serialDataAvail(uart2_fd)>0)
      if (serialGetchar(uart2_fd) == 2) ErrSt = 1;

    while (!(BufChar == 10))
    {
        serialPrintf(uart2_fd, "$8");
//      BufChar0 = BufChar;
        BufChar = serialGetchar(uart2_fd);
        if (BufChar == 1)
        {
//          printf("Ошибка!\n");
            ErrSt = 1;
            break;
        }
        if (BufChar != 3) {
            Buff[cnt] = BufChar;
            ++cnt;
        }
        if (cnt >= MaxLen)
        {
            ErrSt = 1;
            break;
        }
    }
    Buff[cnt] = 0;
    return ErrSt;
}

int CloseGPIB()
{
    serialRelease(uart2_fd);
    releaseWiringRP();
    return 0;
}
