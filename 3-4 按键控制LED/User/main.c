#include "stm32f10x.h"
#include "LED.h"
#include "Key.h"
#include "Delay.h"
uint8_t KeyNum;
uint8_t LED_Status = 0;
int main()
{
	LED_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_All,GPIO_Speed_50MHz);
	Key_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_IPU,GPIO_Pin_1|GPIO_Pin_11,GPIO_Speed_50MHz);
	
	LED_Set(GPIOA,GPIO_Pin_0,1);
	LED_Set(GPIOA,GPIO_Pin_1,1);
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
			LED_Switch(GPIOA,GPIO_Pin_0);
		if(KeyNum == 2)
			LED_Switch(GPIOA,GPIO_Pin_1);
	}
}
