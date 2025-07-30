#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdio.h>

extern uint8_t Serial_TxPacket[];
extern uint8_t Serial_RxPacket[];

void Serial_Init();
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array,uint16_t length);
void Serial_SendString(char* String);
void Serial_Printf(char *format,...);

uint8_t Serial_GetRxFlag();
void Serial_SendPacket();

#endif
