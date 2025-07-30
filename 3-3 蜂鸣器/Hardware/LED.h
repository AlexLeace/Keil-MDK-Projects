#ifndef __LED_H__
#define __LED_H__

void LED_Init(uint32_t APB2_peripheral,GPIO_TypeDef *Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed);
void LED_Set(GPIO_TypeDef *Peripheral_declaration,uint16_t GPIO_Pin,uint8_t LED_Status);

#endif