#ifndef __KEY_H__
#define __KEY_H__

void Key_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed);
uint8_t Key_GetNum(void);

#endif
