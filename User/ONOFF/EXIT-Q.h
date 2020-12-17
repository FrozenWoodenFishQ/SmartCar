#ifndef __EXIT
#define __EXIT
#include "stm32f10x.h"

#define KEY_INT_1_PIN   GPIO_Pin_8
#define KEY_INT_1_PACK  GPIOG
#define KEY_INT_1_CLK   RCC_APB2Periph_GPIOG

static void EXTI_NVIC_Config(void);
void EXIT_KEY_Config(void);

#endif /* __EXIT */
