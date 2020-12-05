
// ADC 6通道采集实验

/**
 * @note	引脚移植修改见 bsp_adc.h 和 bsp_usart.h
 *				配置移植修改见 bsp_adc.h
 */

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "Systick_Q.h"
#include "Servo.h"
#include "motor.h"
#include "encoder.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];
int conv[5];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL];        

// 软件延时
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

void turn(int con[5])
{
	if(con[1]<=10 | con[3]<=10)
		motor_forward(90);
	Servo_open(Turn(con));
}

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{		
	int i;
	float speed;
	// 配置串口
	USART_Config();
	
	// ADC 初始化
	ADCx_Init();
	TIM_PWM_Init();
	tim_motor_init();
	Encoder_TIM_Init();
	
	//printf("\r\n ----这是一个ADC多通道采集实验----\r\n");
	Servo_open(Servo_Mid);
	motor_forward(100);
	
	while (1)
	{	
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[3]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[4]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[0]/4096*3.3;
			//ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		for(i=0;i<5;i++)
		{
			conv[i]=setto_1(ADC_ConvertedValueLocal[i]);
		}
//		if(conv[0] == 0&& conv[1]==0&&conv[2]==0&&conv[3]==0&&conv[4]==0)
//		{
//			motor_forward(0);
//		}
//		 turn(conv);
//			printf("\r\n DG0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
//			printf("\r\n DG1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
//			printf("\r\n DG2 value = %f V \r\n",ADC_ConvertedValueLocal[2]);
//			printf("\r\n DG3 value = %f V \r\n",ADC_ConvertedValueLocal[3]);
//			printf("\r\n DG4 value = %f V \r\n",ADC_ConvertedValueLocal[4]);
			//printf("\r\n CH5 value = %f V \r\n",ADC_ConvertedValueLocal[5]);
//		printf("归一后的值:DG0  %d\n",DG_1);
//		printf("归一后的值:DG1  %d\n",DG_2);
//		printf("归一后的值:DG2  %d\n",DG_3);
//		printf("归一后的值:DG3  %d\n",DG_4);
//		printf("归一后的值:DG4  %d\n",DG_5);
//			printf("\r\n\r\n");
//		  vcan_sendware((uint8_t*) ADC_ConvertedValueLocal,5*4);
			speed = RealSpeed(Getcounter1(),300);
			printf("转速：%.1f\n\n\n",speed);
			Systick_Delay_ms(300);	 
	}
}
/*********************************************END OF FILE**********************/

