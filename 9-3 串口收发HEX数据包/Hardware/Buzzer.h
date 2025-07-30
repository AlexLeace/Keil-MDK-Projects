#ifndef __Buzzer_H__
#define __Buzzer_H__

void Buzzer_Init(uint32_t APB2_peripheral,GPIO_TypeDef *Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed);
void Buzzer_Set(GPIO_TypeDef *Peripheral_declaration,uint16_t GPIO_Pin,uint8_t Buzzer_Status);
void Buzzer_Switch(GPIO_TypeDef* Peripheral_declaration,uint16_t GPIO_Pin);

#endif
