#include "stm32f10x.h"
#include "Buzzer.h"
#include "LightSensor.h"
uint8_t MyArray[] = {0x42,0x43,0x44,0x45};
int main()
{
	Buzzer_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_10,GPIO_Speed_50MHz);
	LightSensor_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_IPU,GPIO_Pin_12,GPIO_Speed_50MHz);
	
	while(1)
	{
		if(LightSensor_Get(GPIOA,GPIO_Pin_12) == 1)
			Buzzer_Set(GPIOA,GPIO_Pin_10,RESET);
		else
			Buzzer_Set(GPIOA,GPIO_Pin_10,SET);
	}
}
