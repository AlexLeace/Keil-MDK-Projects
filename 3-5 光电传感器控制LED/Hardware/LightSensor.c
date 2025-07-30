#include "stm32f10x.h"
#include "Delay.h"
/***************************************************************
*  @brief:	 	初始化LightSensor    
*  @param:	 	uint32_t 			APB2_peripheral
*  @param:	 	GPIO_TypeDef*		Peripheral_declaration
*  @param:	 	GPIOMode_TypeDef 	GPIO_Mode
*  @param:	 	uint16_t 			GPIO_Pin
*  @param:	 	GPIOSpeed_TypeDef 	GPIO_Speed
*  @note:		无
*  @return:		无
*  @sample: 	LightSensor_Init(RCC_APB2Periph_GPIOB,GPIOB,GPIO_Mode_IPU,GPIO_Pin_12,GPIO_Speed_50MHz);
 **************************************************************/
void LightSensor_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(APB2_peripheral,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
	GPIO_Init(Peripheral_declaration,&GPIO_InitStructure);
}

/***************************************************************
*  @brief:	获取光电传感器数据
*  @param:	GPIO_TypeDef* Peripheral_declaration
*  @param:	int16_t GPIO_Pin
*  @return:	uint8_t
*  @note:	None
*  @sample:	LightSensor_Get(GPIOB,GPIO_Pin_10)
 **************************************************************/
uint8_t LightSensor_Get(GPIO_TypeDef* Peripheral_declaration,int16_t GPIO_Pin)
{
	return GPIO_ReadInputDataBit(Peripheral_declaration,GPIO_Pin);
}
