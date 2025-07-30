#include "stm32f10x.h"

void CountSenor_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	EXTI_InitStruct.EXTI_Line = ;
	EXTI_InitStruct.EXTI_LineCmd = ;
	EXTI_InitStruct.EXTI_Mode = ;
	EXTI_InitStruct.EXTI_Trigger = ;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	EXTI_Init()
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	
}