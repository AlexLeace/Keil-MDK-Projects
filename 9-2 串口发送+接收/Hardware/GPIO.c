#include "stm32f10x.h"

/***************************************************************
*  @brief:	 	初始化GPIO    
*  @param:	 	uint32_t 			APB2_peripheral
*  @param:	 	GPIO_TypeDef*		Peripheral_declaration
*  @param:	 	GPIOMode_TypeDef 	GPIO_Mode
*  @param:	 	uint16_t 			GPIO_Pin
*  @param:	 	GPIOSpeed_TypeDef 	GPIO_Speed
*  @note:		LED的GPIO_Mode为GPIO_Mode_Out_PP；
*				Key的GPIO_Mode为GPIO_Mode_IPU；
*  @return:		无
*  @sample: 	my_GPIO_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_12,GPIO_Speed_50MHz);
 **************************************************************/
GPIO_InitTypeDef GPIO_InitStructure;
void my_GPIO_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed)
{
	RCC_APB2PeriphClockCmd(APB2_peripheral,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	
	GPIO_Init(Peripheral_declaration,&GPIO_InitStructure);
}
