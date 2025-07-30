#include "stm32f10x.h"

//LED_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_12,GPIO_Speed_50MHz);
void LED_Init(uint32_t APB2_peripheral,GPIO_TypeDef *Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed)
{
	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(APB2_peripheral,ENABLE);

//	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	GPIO_Init(Peripheral_declaration,&GPIO_InitStructure);
}

//LED_Set(GPIOB,GPIO_Pin_12,0)
void LED_Set(GPIO_TypeDef *Peripheral_declaration,uint16_t GPIO_Pin,uint8_t LED_Status)
{
	if(LED_Status==0)
		//GPIO_SetBits(GPIOA,GPIO_Pin_12);
		GPIO_ResetBits(Peripheral_declaration,GPIO_Pin);
	else
		GPIO_SetBits(Peripheral_declaration,GPIO_Pin);
}
