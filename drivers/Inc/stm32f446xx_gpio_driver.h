#ifndef INC_STM32F446XX_GPIO_DRIVER_H
#define INC_STM32F446XX_GPIO_DRIVER_H

#include "stm32f446xx.h"

/* This is handle structure for  the GPIO pin
 *
 */

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSPeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
	//pointer to hold the base addr of the GPIO peripheral
	GPIO_RegDef_t *pGPIOx ;/*!< THis hold the base address of the GPIO port to which the pin belongs. >*/
	GPIO_PinConfig_t GPIO_PinConfig; //Hold the GPIO pin config settings.

}GPIO_Handle_t;

#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7
#define GPIO_PIN_8		8
#define GPIO_PIN_9		9
#define GPIO_PIN_10		10
#define GPIO_PIN_11		11
#define GPIO_PIN_12		12
#define GPIO_PIN_13		13
#define GPIO_PIN_14		14
/*
 * GPIO possible mode
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

#define GPIO_OUT_TYPE_PP 	0
#define GPIO_OUT_TYPE_OD	1

#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define	GPIO_SPEED_HIGH		3

#define GPIO_PIN_NO_PUPD		0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2


/*
 * API supported by the drivers.
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
void GPIO_IRQInterruptConfig(uint8_t IRONumber, uint8_t EnorDi);			//Configure the IRQ number
void GPIO_IRQHandle(uint8_t pinNumber);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);

#endif
