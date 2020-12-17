#include "EXIT-Q.h"

static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO , ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_Initstruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Initstruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstruct);
}

void EXIT_KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	EXTI_NVIC_Config();
	
	RCC_APB2PeriphClockCmd( KEY_INT_1_CLK , ENABLE);
	GPIO_InitStruct.GPIO_Pin =KEY_INT_1_PIN ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY_INT_1_PACK,&GPIO_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource9);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line9;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
}
