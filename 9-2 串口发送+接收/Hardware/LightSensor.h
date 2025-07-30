#ifndef __LIGHTSENSOR_H
#define __LIGHTSENSOR_H

void LightSensor_Init(uint32_t APB2_peripheral,GPIO_TypeDef* Peripheral_declaration,GPIOMode_TypeDef GPIO_Mode,uint16_t GPIO_Pin,GPIOSpeed_TypeDef GPIO_Speed);
uint8_t LightSensor_Get(GPIO_TypeDef* Peripheral_declaration,int16_t GPIO_Pin);

#endif
