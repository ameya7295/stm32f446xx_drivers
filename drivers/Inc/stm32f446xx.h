/*
 * stm32f446xx.h
 *
 *  Created on: Apr 14, 2025
 *      Author: Patil
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/****************************Preprocessor specific details**************************/
/*
 * ARM cortex Mx processor NVIC register addresses
 * */

#define	NVIC_ISER0				((volatile uint32_t*)0xE000E100)
#define	NVIC_ISER1				((volatile uint32_t*)0xE000E104)
#define	NVIC_ISER2				((volatile uint32_t*)0xE000E108)
#define	NVIC_ISER3				((volatile uint32_t*)0xE000E10C)

/*ICERx Register*/
#define	NVIC_ICER0				((volatile uint32_t*)0xE000E180)
#define	NVIC_ICER1				((volatile uint32_t*)0xE000E184)
#define	NVIC_ICER2				((volatile uint32_t*)0xE000E188)
#define	NVIC_ICER3				((volatile uint32_t*)0xE000E18C)

#define NVIC_IPR_BASEADDR		((volatile uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED			4 // This is controller specific


/*
 * All the base address will be added as C Macros.
 * This contains all the microcontroller.
 * */

#define FLASHB_ADDR				0x08000000U		//You can have it as (unit32_t)0x08000000
#define SRAM1_BASEADDR			0x20000000U		//112KB
#define SRAM1 					SRAM1_BASEADDR
#define SRAM2_BASEADDR			0x2001C000U
#define SRAM2					SRAM2_BASEADDR

#define ROM						0x1FFF0000U		//System memory
#define OTP_BASEADDR			0x1FFF7800U

// Step 2, MACRO for bus domain
#define PERIPH_BASEADDR			0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASE
#define APB2PERIPH_BASEADDR		0x40010000U
#define AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR		0x50000000U

/*
 * Base address of the peripherals that are attached to AHB1 bus
 * */
#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)
/*
 *  * Base address of the peripherals that are attached to APB1 bus
 *
 * */
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)

#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)

/*
 *  * Base address of the peripherals that are attached to APB2 bus
 *
 * */
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)


/*****************************Peripheral register definition structure*****************************/

/*Note: This is specific to STM32F446RE MCU.
 * Refer to the reference manual of same MCU.
 * */

/*--------------------------GPIO Registers structure START--------------------------*/

typedef struct
{
	volatile uint32_t MODER;		/*Write the respective documentation from the RM	Address offset : 0x00*/
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDER;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];	// Lower and upper byte
} GPIO_RegDef_t;
/*--------------------------GPIO Registers structure END--------------------------*/
/*--------------------------RCC Registers structure START--------------------------*/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t ABH2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCK_CFGR;
	volatile uint32_t CK_GATENR;
	volatile uint32_t DCKCFGR2;
}RCC_RegDef_t;
/*--------------------------RCC Registers structure END--------------------------*/
/*--------------------------EXTI Registers structure START--------------------------*/
typedef struct{
	volatile uint32_t IMR;			//0x00
	volatile uint32_t EMR;			///0x04
	volatile uint32_t RTSR;			//0x08
	volatile uint32_t FTSR;			//0x0C
	volatile uint32_t SWIER;		//0x10
	volatile uint32_t PR;			//0x14

}EXTI_RegDef_t;
/*--------------------------EXTI Registers structure END--------------------------*/
/*--------------------------SYSCFG Registers structure START--------------------------*/
typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED1[2];
	volatile uint32_t CMPCR;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t CFGR;
}SYSCFG_RegDef_t;
/*--------------------------SYSCFG Registers structure END--------------------------*/



//GPIO_RegDef_t *pGPIOA = GPIOA;

#define GPIOA 					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 					((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC						((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI					((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


/*--------------------------Clock enable for Peripherals START--------------------------*/
/*
 * Clock Enable for GPIOx Peripherals
 */
#define GPIOA_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 0)) )
#define GPIOB_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 1)) )
#define GPIOC_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 2)) )
#define GPIOD_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 3)) )
#define GPIOE_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 4)) )
#define GPIOF_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 5)) )
#define GPIOG_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 6)) )
#define GPIOH_PCLK_EN()			( (RCC->AHB1ENR |= (1 << 7)) )

/*
 * Clock Enable for I2Cx Peripherals
 */

#define I2C1_PCLK_EN()			( (RCC->APB1ENR |= (1 << 21)) )
#define I2C2_PCLK_EN()			( (RCC->APB1ENR |= (1 << 22)) )
#define I2C3_PCLK_EN()			( (RCC->APB1ENR |= (1 << 23)) )

/*
 * Clock Enable for SPIx peripherals
 */
#define SPI1_PCLK_EN()			( (RCC->APB2ENR |= (1 << 12)) )

/*
 * Clock Enable for USARTx peripherals
 */
#define USART1_PCLK_EN()			( (RCC->APB2ENR |= (1 << 4)) )
#define USART2_PCLK_EN()			( (RCC->APB1ENR |= (1 << 17)) )
#define USART3_PCLK_EN()			( (RCC->APB1ENR |= (1 << 18)) )
#define USART6_PCLK_EN()			( (RCC->APB2ENR |= (1 << 5)) )

/*
 * CLock enable for UARTx peripherals
 */
#define UART4_PCLK_EN()			( (RCC->APB1ENR |= (1 << 19)) )
#define UART5_PCLK_EN()			( (RCC->APB1ENR |= (1 << 20)) )


/*
 * Clock enable for SYSCFG
 */

#define SYSCFG_PCLK_EN()			( (RCC->APB2ENR |= (1 << 14)) )
/*--------------------------Clock enable for Peripherals  END--------------------------*/



/*--------------------------Clock Disable for Peripherals START --------------------------*/
/*
 * Clock disable for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 0)) )
#define GPIOB_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 1)) )
#define GPIOC_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 2)) )
#define GPIOD_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 3)) )
#define GPIOE_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 4)) )
#define GPIOF_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 5)) )
#define GPIOG_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 6)) )
#define GPIOH_PCLK_DI()			( (RCC->AHB1ENR &= ~(1 << 7)) )

/*
 * Clock disable for I2Cx Peripherals
 */

#define I2C1_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 21)) )
#define I2C2_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 22)) )
#define I2C3_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 23)) )

/*
 * Clock disable for SPIx peripherals
 */
#define SPI1_PCLK_DI()			( (RCC->APB2ENR &= ~(1 << 12)) )

/*
 * Clock disable for USARTx peripherals
 */
#define USART1_PCLK_DI()			( (RCC->APB2ENR &= ~(1 << 4)) )
#define USART2_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 17)) )
#define USART3_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 18)) )
#define USART6_PCLK_DI()			( (RCC->APB2ENR &= ~(1 << 5)) )

/*
 * CLock disable for UARTx peripherals
 */
#define UART4_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 19)) )
#define UART5_PCLK_DI()			( (RCC->APB1ENR &= ~(1 << 20)) )


/*
 * Clock disable for SYSCFG
 */
#define SYSCFG_PCLK_DI()			( (RCC->APB2ENR &= ~(1 << 14)) )

#define GPIOA_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 0)); 	(RCC->APB1RSTR |= (1 << 0));}while(0)
#define GPIOB_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 1)); 	(RCC->APB1RSTR |= (1 << 1));}while(0)
#define GPIOC_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 2)); 	(RCC->APB1RSTR |= (1 << 2));}while(0)
#define GPIOD_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 3)); 	(RCC->APB1RSTR |= (1 << 3));}while(0)
#define GPIOE_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 4)); 	(RCC->APB1RSTR |= (1 << 4));}while(0)
#define GPIOF_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 5)); 	(RCC->APB1RSTR |= (1 << 5));}while(0)
#define GPIOG_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 6)); 	(RCC->APB1RSTR |= (1 << 6));}while(0)
#define GPIOH_REG_RESET()			do{(RCC->APB1RSTR |= (1 << 7)); 	(RCC->APB1RSTR |= (1 << 7));}while(0)


/*--------------------------Clock Disable for Peripherals END --------------------------*/

#define GPIO_BASEADDR_TO_PORT_CODE(x) 	(	(x == GPIOA) ? 0 :\
											(x == GPIOB) ? 1 :\
											(x == GPIOC) ? 2 :\
											(x == GPIOD) ? 3 :\
											(x == GPIOE) ? 4 :\
											(x == GPIOF) ? 5 :\
											(x == GPIOG) ? 6 :\
											(x == GPIOH) ? 7 : 0 )

/* -------------------------GENERIC MACRO-------------------------*/
#define ENABLE			1
#define DISABLE			0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_SET		SET
#define FLAG_RESET		RESET

/*-------------------------IRQ Number -------------------------*/
#define EXTI0			6
#define EXTI1			7
#define EXTI2			8
#define EXTI3			9
#define EXTI4			10
#define EXTI9_5			23
#define EXTI15_10		40

#include "stm32f446xx_gpio_driver.h"

#endif /* INC_STM32F446XX_H_ */
