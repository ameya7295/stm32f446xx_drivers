/*
 * stm32f446xx_i2c_driver.c
 *
 *  Created on: Sep 29, 2025
 *      Author: administrator
 */

#include "stm32f446xx_spi_driver.h"

void SPI_peri_clock_control(spi_regdef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_EN();
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_EN();
        }
        else if(pSPIx == SPI4)
        {
            SPI4_PCLK_EN();
        }
    }
    else
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_DI();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_DI();
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_DI();
        }
        else if(pSPIx == SPI4)
        {
            SPI4_PCLK_DI();
        }
    }
}

/*
	Device mode congiguration : Slave or master
	Bus configuration : HD, FD, SIMPLEX
	Baud Rate:
	Serial clock
	DFF
	CPOL
	CPHA
	SSM
*/
void SPI_init(spi_handle_t *p_SPI_handle)
{
	/* SPI_CR1 register configuration */
	uint32_t tempreg = 0;

	/* Enable peripheral clock */
	SPI_peri_clock_control(p_SPI_handle->p_SPI_x, ENABLE);

	/* Device mode configuration */
	tempreg |= p_SPI_handle->SPI_config.SPI_DeviceMode << SPI_CR1_MSTR;

	/* Bus configuration */
	if (p_SPI_handle->SPI_config.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		/* Bidirectional mode clear */
		tempreg &= ~(1 << SPI_CR1_BIDI_MODE);
	}
	else if (p_SPI_handle->SPI_config.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		/* Bidirectional mode set */
		tempreg |= (1 << SPI_CR1_BIDI_MODE);
	}
	else if (p_SPI_handle->SPI_config.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		/* Bidirectional mode clear */
		tempreg &= ~(1 << SPI_CR1_BIDI_MODE);

		/* Rx only mode set */
		tempreg |= (1 << SPI_CR1_RX_ONLY);
	}

	/* SPI serial clock speed (baud rate) configuration */
	tempreg |= p_SPI_handle->SPI_config.SPISclkSpeed << SPI_CR1_BR;

	/* DFF configuration */
	tempreg |= p_SPI_handle->SPI_config.SPI_DFF << SPI_CR1_DFF;

	/* CPOL configuration */
	tempreg |= p_SPI_handle->SPI_config.SPI_CPOL << SPI_CR1_CPOL;

	/* CPHA configuration */
	tempreg |= p_SPI_handle->SPI_config.SPI_CPHA << SPI_CR1_CPHA;

	/* SSM configuration */
	tempreg |= p_SPI_handle->SPI_config.SPI_SSM << SPI_CR1_SSM;

	/* Save temperg in CR1 register */
	p_SPI_handle->p_SPI_x->CR1 = tempreg;
}
void SPI_deinit(spi_regdef_t *p_SPI_x)
{
	if (p_SPI_x == SPI1)
	{
		SPI1_REG_RESET();
	}
	else if (p_SPI_x == SPI2)
	{
		SPI2_REG_RESET();
	}
	else if (p_SPI_x == SPI3)
	{
		SPI3_REG_RESET();
	}
	else if (p_SPI_x == SPI4)
	{
		SPI4_REG_RESET();
	}
}

uint8_t SPI_GetFlagStatus(spi_regdef_t *pSPIX, uint32_t FlagName)
{

	if (pSPIX->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

/*
 * Data Send and receive, This is a blocking call, polling type code.
 */
void SPI_send_data(spi_regdef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Length)
{
    while(Length > 0)
    {
        /* Wait until TXE is set */
        while(SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == (uint8_t)FLAG_RESET);

        if( pSPIx->CR1 & (1 << SPI_CR1_DFF) )
        {
            /* Load data into data register */
            /* 16 bit */
            pSPIx->DR = *((uint16_t*)pTxBuffer);
            Length--;
            Length--;
            (uint16_t*)pTxBuffer++;
        }
        else
        {
            /* 8 bit */
            pSPIx->DR = *pTxBuffer;
            Length--;
            pTxBuffer++;
        }
    }
}

void SPI_receive_data(uint8_t *p_rx_buffer, uint32_t len)
{
}

/*
 * IRQ Configuration and ISR handling for the SPI
 */

void SPI_irq_interrupt_config(uint8_t irq_number, uint8_t enordi)
{
}

void SPI_irq_priority_config(uint8_t irq_number, uint32_t irq_priority)
{
}

void SPI_irq_handling(spi_handle_t *p_spi_handle)
{
}


void SPI_PeripheralControl(spi_regdef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SPE);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
    }
}



/*****************************************************************
 * @fn          - SPI_SSIConfig
 *
 * @brief       - This function sets SSI register
 *
 * @param[in]   - Base address of the SPI peripheral
 * @param[in]   - Enable or Disable command
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void SPI_SSIConfig(spi_regdef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SSI);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
    }
}
