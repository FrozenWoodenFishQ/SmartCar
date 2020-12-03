#include "encoder.h"

void Encoder_TIM_Init(void)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBasestruct;
	TIM_ICInitTypeDef TIM_ICInitstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD,ENABLE);
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(coder_1_port , &GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_Init(coder_2_port , &GPIO_Initstruct);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3 , ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_TIM4 , ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4,ENABLE);
	TIM_TimeBasestruct.TIM_Period = 0xFFFF;
	TIM_TimeBasestruct.TIM_Prescaler = 0;
	TIM_TimeBasestruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBasestruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(coder_1_TIM, &TIM_TimeBasestruct);
	
	TIM_EncoderInterfaceConfig(coder_1_TIM,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	TIM_ICStructInit(&TIM_ICInitstruct);
	TIM_ICInit(coder_1_TIM,&TIM_ICInitstruct);
	
	TIM_ITConfig(coder_1_TIM,TIM_IT_Update,ENABLE);
	TIM_Cmd(coder_1_TIM,ENABLE);
}

int Getcounter(void)
{
	int count,True;
	count = TIM_GetCounter(coder_1_TIM);
	TIM_SetCounter(coder_1_TIM,0);
	if(count < 32767)
		True = count;
	else
		True = count - 65535;
	return True;
}

float RealSpeed(int speed)
{
	float Ts = 1,Line = 512;
	float n;
	n = ((float)speed)/(Ts*Line);
	return n;
}
