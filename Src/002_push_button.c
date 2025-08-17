/*003_push_button*/

#include "stm32f446xx.h"
#include <stdio.h>

void delay(int ms)
{
	for(uint32_t i = 0; i <ms; i++);
}

int main(void)
{

	//LED connected to port A pin 5
	GPIO_Handle_t GpioLed, GPIO_push_button;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	//Push button Config

	GPIO_push_button.pGPIOx = GPIOC;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
//	GPIO_push_button.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_MEDIUM;
	GPIO_push_button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GPIO_push_button);


	while(1)
	{
		uint8_t state = GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13);
		if(state == 1)
		{
			delay(100);
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, 1);
//			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
			printf("LED toggled \n");
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, 0);
		}


	}

	return 0;
}


