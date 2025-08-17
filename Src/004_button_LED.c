/*003_push_button*/

#include "stm32f446xx.h"
#include <stdio.h>

void delay()
{
	for(uint32_t i = 0; i <500000/2; i++);
}

int main(void)
{

	//LED connected to port A pin 5
	GPIO_Handle_t GpioLed;
	GPIO_Handle_t GpioLed2, GPIO_push_button;


	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GpioLed2.pGPIOx = GPIOA;
	GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed2.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	GpioLed2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioLed2);


	//Push button Config

	GPIO_push_button.pGPIOx = GPIOB;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GPIO_push_button);


	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_12) == 0)
		{
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
			delay();

			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_12);

			delay();
			printf("LED toggled \n");
		}
		else
		{
//			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, 0);
		}


	}

	return 0;
}


