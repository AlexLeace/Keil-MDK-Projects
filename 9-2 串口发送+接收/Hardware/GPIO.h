#ifndef __GPIO_H__
#define __GPIO_H__

void LED_Init(uint32_t APB2_peripheral,GPIO_TypeDef *Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed);

#endif