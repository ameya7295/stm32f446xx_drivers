/*
 * 005_button_interrupt.c
 *
 *  Created on: Aug 17, 2025
 *      Author: Patil
 */


/*005_button_interrupt*/

#include "stm32f446xx.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>

void delay()
{
	for(uint32_t i = 0; i <500000/2; i++);
}

int main(void)
{

	//LED connected to port A pin 5
	GPIO_Handle_t GpioLed;
	GPIO_Handle_t GPIO_push_button;

	memset(&GpioLed, 0, sizeof(GpioLed));
	memset(&GPIO_push_button, 0, sizeof(GPIO_push_button));

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;


	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIOl_Init(&GpioLed);

	//Push button Config
	GPIO_push_button.pGPIOx = GPIOB;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GPIO_push_button);


	GPIO_IRQInterruptConfig(EXTI15_10, ENABLE);
	GPIO_IRQPriorityConfig(EXTI15_10, 15);

	while(1);

	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandle(GPIO_PIN_12);
    GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_12);
	delay();
}


