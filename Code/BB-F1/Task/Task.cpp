#include "Task.h"


class
{

	uint16_t Value[4]={0};

}PWMChannel;

void initTask(void)
{
	/*��ʼ��WS2812��*/
	
	/*��ʼ��CANͨѶ*/

	/*��ʼ��������*/
	LL_TIM_EnableIT_UPDATE(TIM3);
	LL_TIM_EnableCounter(TIM3);
}


void TIM3_IRQHandler(void)
{
	static uint16_t beat = 0;
	if(++beat==1001){beat=0;}
	
	/*100Hz PWM����趨*/
	if(beat%10==1)
	{
		LL_TIM_OC_SetCompareCH1(TIM3,0);
		LL_TIM_OC_SetCompareCH2(TIM3,0);
		LL_TIM_OC_SetCompareCH3(TIM3,0);
		LL_TIM_OC_SetCompareCH4(TIM3,0);
		beat=0;
	}
	
	LL_TIM_ClearFlag_UPDATE(TIM3);
}