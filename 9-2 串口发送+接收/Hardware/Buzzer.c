#include "stm32f10x.h"
/***************************************************************
*  @brief:	 	初始化Buzzer    
*  @param:	 	uint32_t 			APB2_peripheral
*  @param:	 	GPIO_TypeDef*		Peripheral_declaration
*  @param:	 	GPIOMode_TypeDef 	GPIO_Mode
*  @param:	 	uint16_t 			GPIO_Pin
*  @param:	 	GPIOSpeed_TypeDef 	GPIO_Speed
*  @note:		无
*  @return:		无
*  @sample: 	Buzzer_Init(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Mode_Out_PP,GPIO_Pin_12,GPIO_Speed_50MHz);
 **************************************************************/
void Buzzer_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(APB2_peripheral,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	GPIO_Init(Peripheral_declaration,&GPIO_InitStructure);
}
/***************************************************************
*  @brief:     	设置Buzzer状态
*  @param:  	GPIO_TypeDef*		Peripheral_declaration
*  @param:  	uint16_t 			GPIO_Pin
*  @param:  	BitAction 			BitVal
*  @note:		BitVal，Bit_RESET为低电平，Bit_SET为高电平
*  @return:		无
*  @sample: 	Buzzer_Set(GPIOA,GPIO_Pin_12,Bit_RESET)
 **************************************************************/
void Buzzer_Set(GPIO_TypeDef* Peripheral_declaration,uint16_t GPIO_Pin,BitAction BitVal)
{
	if(BitVal == Bit_RESET)
		//GPIO_SetBits(GPIOA,GPIO_Pin_12);
		GPIO_ResetBits(Peripheral_declaration,GPIO_Pin);
	if(BitVal == Bit_SET)
		GPIO_SetBits(Peripheral_declaration,GPIO_Pin);
}

/***************************************************************
*  @brief:	翻转Buzzer状态
*  @param:  GPIO_TypeDef* 	Peripheral_declaration
*  @param:  uint16_t 		GPIO_Pin
*  @note:	None
*  @sample: Buzzer_Switch(GPIOA,GPIO_Pin_0)
 **************************************************************/
void Buzzer_Switch(GPIO_TypeDef* Peripheral_declaration,uint16_t GPIO_Pin)
{
	if(GPIO_ReadOutputDataBit(Peripheral_declaration,GPIO_Pin) == 0)
		GPIO_ResetBits(Peripheral_declaration,GPIO_Pin);
	if(GPIO_ReadOutputDataBit(Peripheral_declaration,GPIO_Pin) == 1)
		GPIO_SetBits(Peripheral_declaration,GPIO_Pin);
}
