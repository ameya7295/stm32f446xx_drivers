/*
 * stm32f446xx_i2c_driver.h
 *
 *  Created on: Sep 29, 2025
 *      Author: administrator
 */

#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_

#include "stm32f446xx.h"

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPISclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}spi_config_t;

typedef struct{
	spi_regdef_t *p_SPI_x;
	spi_config_t SPI_config;
}spi_handle_t;

/*
 * SPI Device modes
 */
#define SPI_DEVICE_MODE_MASTER			1
#define SPI_DEVICE_MODE_SLAVE			0

/*
 * SPI BUS CONFIG
 */
#define SPI_BUS_CONFIG_FD				1
#define SPI_BUS_CONFIG_HD				2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	3

/*
 * SPI CLOCK SPEED
 */

#define SPI_SCLK_SPEED_DIV2				0
#define SPI_SCLK_SPEED_DIV4				1
#define SPI_SCLK_SPEED_DIV8				2
#define SPI_SCLK_SPEED_DIV16			3
#define SPI_SCLK_SPEED_DIV32			4
#define SPI_SCLK_SPEED_DIV64			5
#define SPI_SCLK_SPEED_DIV128			6
#define SPI_SCLK_SPEED_DIV256			7

/*
 * SPI DATA FRAME FORMAT
 */
#define SPI_DFF_8BITS					0
#define SPI_DFF_16BITS					1

/*
 * SPI CPOL
 */
#define SPI_CPOL_HIGH					1
#define SPI_CPOL_LOW					0

/*
 * CPHA
 */
#define SPI_CPHA_HIGH					1
#define SPI_CPHA_LOW					0

/*
 * SPI SSM
 */
#define SPI_SSM_EN						1
#define SPI_SSM_DI						0

/*
 * SPI related status flag definitions
 */
#define SPI_FLAG_TXE    ( 1 << SPI_SR_TXE)
#define SPI_FLAG_RXNE   ( 1 << SPI_SR_RXNE)
#define SPI_FLAG_BUSY   ( 1 << SPI_SR_BSY)

/*
 * API supported by the drivers.
 */

void SPI_peri_clock_control(spi_regdef_t *p_SPI_x, uint8_t EnorDi);

void SPI_init(spi_handle_t *p_SPI_handle);
void SPI_deinit(spi_regdef_t *p_SPI_x);


/*
 * Data Send and receive
 */
void SPI_send_data(spi_regdef_t *p_SPI_x, uint8_t *p_tx_buffer, uint32_t len);
void SPI_receive_data(uint8_t *p_rx_buffer, uint32_t len);


/*
 * IRQ Configuration and ISR handling for the SPI
 */

void SPI_irq_interrupt_config(uint8_t irq_number, uint8_t enordi);
void SPI_irq_priority_config(uint8_t irq_number, uint32_t irq_priority);
void SPI_irq_handling(spi_handle_t *p_spi_handle);


/*
 * Other peripheral APIs
 */
void SPI_PeripheralControl(spi_regdef_t *pSPIx, uint8_t EnorDi);
void SPI_SSIConfig(spi_regdef_t *pSPIx, uint8_t EnorDi);



#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */




