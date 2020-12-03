#include "Systick_Q.h"

void Systick_Delay_ms(uint32_t time)
{
	uint32_t i;
	SysTick_Config(72000);
	for(i=0;i<time;i++)
	{
		while(!((SysTick->CTRL) & (1<<16)));
	}
	
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
}
