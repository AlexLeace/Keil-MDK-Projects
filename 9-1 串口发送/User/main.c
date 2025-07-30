#include "stm32f10x.h"
#include "Serial.h"
#include "OLED.h"
uint8_t MyArray[] = {0x42,0x43,0x44,0x45};
int main()
{
	OLED_Init();
	Serial_Init();
	Serial_SendByte(0x41);
	while(1)
	{

//		
//		Serial_SendArray(MyArray,4);
//		
//		Serial_SendString("\r\nHello World");
//		
//		printf("Num=%d\r\n",6666);
//		
//		Serial_Printf("Num=%d\r\n",666);
	}
}
