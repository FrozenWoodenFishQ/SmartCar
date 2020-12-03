#ifndef _SERVO_H_
#define _SERVO_H_

#define	RCC_APBPeriph_TIMx_GPIOx	RCC_APB2Periph_GPIOA
#define	RCC_APBPeriph_TIMx	RCC_APB1Periph_TIM2
#define	TIM_GPIO	GPIOA
#define TIM_SERVO	TIM2
#define Servo_Mid    1480
#define Servo_Right  1325
#define Servo_Left   1620

#define Kp      100
#define Kd      0.2

extern void TIM_PWM_Init(void);
extern void Servo_open(int dir1);
extern void Servo_close(int dir2);
void protect_comp(int* command);
int Turn(int c[5]);

#endif
