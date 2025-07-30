#include "stm32f10x.h"
#include "Delay.h"
int main()
{
	unsigned char i = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);	//LED 灭
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);	//LED 亮
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET); //LED 灭
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET); //LED 亮
	while(1)
	{
//		GPIO_Write(GPIOA,~0x0001);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0002);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0004);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0008);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0010);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0020);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0040);
//		Delay_ms(100);
//		GPIO_Write(GPIOA,~0x0080);
//		Delay_ms(100);
		for(i=0;i<8;i++)
		{
			GPIO_Write(GPIOA,~(0x0001 << i));
			Delay_ms(100);
		}
	}
}
