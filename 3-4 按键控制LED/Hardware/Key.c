#include "stm32f10x.h"
#include "Delay.h"
/***************************************************************
*  @brief:	 	初始化Key    
*  @param:	 	uint32_t 			APB2_peripheral
*  @param:	 	GPIO_TypeDef*		Peripheral_declaration
*  @param:	 	GPIOMode_TypeDef 	GPIO_Mode
*  @param:	 	uint16_t 			GPIO_Pin
*  @param:	 	GPIOSpeed_TypeDef 	GPIO_Speed
*  @note:		无
*  @return:		无
*  @sample: 	LED_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_12,GPIO_Speed_50MHz);
 **************************************************************/

void Key_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(APB2_peripheral,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	GPIO_Init(Peripheral_declaration,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);
		KeyNum = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0);
		KeyNum = 2;
	}
	return KeyNum;
}
