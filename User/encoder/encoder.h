#ifndef __encoder
#define __encoder
#include "stm32f10x.h"

#define coder_1_port GPIOC
#define coder_2_port GPIOD
#define coder_1_TIM  TIM3
#define coder_2_TIM  TIM4

void Encoder_TIM_Init(void);
int Getcounter1(void);
int Getcounter2(void);
float RealSpeed(int speed,int timems);
#endif
