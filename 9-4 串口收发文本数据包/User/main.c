#include "stm32f10x.h"
#include "Serial.h"
#include "OLED.h"
#include "LED.h"
#include <String.h>
uint8_t RxData;
int main()
{
	OLED_Init();
	Serial_Init();
	LED_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_0,GPIO_Speed_50MHz);
	
	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");
	
	while(1)
	{
		if(Serial_RxFlag == 1)
		{
			OLED_ShowString(4,1,"                ");
			OLED_ShowString(4,1,Serial_RxPacket);
		
			if(strcmp(Serial_RxPacket,"LED_ON") == 0)
			{
				LED_Set(GPIOA,GPIO_Pin_0,Bit_RESET);
				Serial_SendString("LED_ON_OK\r\n");
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,"LED_ON_OK");
			}
			else if(strcmp(Serial_RxPacket,"LED_OFF") == 0)
			{
				LED_Set(GPIOA,GPIO_Pin_0,Bit_SET);
				Serial_SendString("LED_OFF_OK\r\n");
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,"LED_OFF_OK");
			}
			else
			{
				Serial_SendString("ERROR_COMMAND\r\n");
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,"ERROR_COMMAND");
			}
			Serial_RxFlag = 0;
		}
	}
}
