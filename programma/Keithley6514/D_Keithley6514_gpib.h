#ifndef GPIB_H
#define GPIB_H

int InitGPIB();
int GPIB_SendCommand(int addr, const char *cmd, int len);
int GPIB_Read(int addr, char *buff, int maxLen);
int CloseGPIB();

#endif