#ifndef _MORTOR_H_
#define _MORTOR_H_

#define motor_1 1
#define motor_2 2
#define motor_3 3
#define motor_4 4

#define Set     5400
#define KP      0.04
#define KI      0.008

static float lasterr = 0,movePWM = 0,evenlast = 0;

extern void tim_motor_init(void);
extern void motor_run(int motor_num,int speed_set);
void motor_forward(int speed);
extern void PIDControl(float Speed,int setting);

#endif
