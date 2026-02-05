#include <string.h>
#include "stm32f446xx.h"

/*
 * Alternate functionality
 *
 * PB15 --> SPI2_MOSI
 * PB14 --> SPI2_MISO
 * PB13 --> SPI2_SLCK
 * PB12 --> SPI2_NSS
 * ALT function mode: AF5
 */

void SPI2_GPIOInits(void)
{
    GPIO_Handle_t SPIPins;

    SPIPins.pGPIOx = GPIOB;
    SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
    SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;
    SPIPins.GPIO_PinConfig.GPIO_PinSPeed = GPIO_SPEED_FAST;

    /* SCLK Init */
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
    GPIO_Init(&SPIPins);

    /* MOSI Init */
    SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
    GPIO_Init(&SPIPins);

    /* MISO Init */
    //SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    //GPIO_Init(&SPIPins);

    /* NSS Init */
    //SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    //GPIO_Init(&SPIPins);
}


void SPI2_Inits()
{
    spi_handle_t SPIHandle;

    SPIHandle.p_SPI_x = SPI2;
    SPIHandle.SPI_config.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPIHandle.SPI_config.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPIHandle.SPI_config.SPISclkSpeed = SPI_SCLK_SPEED_DIV2; //8MHz
    SPIHandle.SPI_config.SPI_DFF = SPI_DFF_8BITS;
    SPIHandle.SPI_config.SPI_CPOL = SPI_CPOL_LOW;
    SPIHandle.SPI_config.SPI_CPHA = SPI_CPHA_LOW;
    SPIHandle.SPI_config.SPI_SSM = SPI_SSM_EN; //SSM Enabled for NSS pin

    SPI_init(&SPIHandle);
}


int main(void)
{
    char user_data[] = "Hello World!";

    /* Initialize GPIO pins to behave as SPI2 pins */
    SPI2_GPIOInits();

    /* Initialize SPI2 peripheral parameters */
    SPI2_Inits();

    /* Makes NSS sigmal internaly high and avoids MODE error */
    SPI_SSIConfig(SPI2, ENABLE);

    /* Enable SPI2 peripheral */
    SPI_PeripheralControl(SPI2, ENABLE);

    /* Send SPI data */
    SPI_send_data(SPI2, (uint8_t *)user_data, strlen(user_data));

    // /* Confirm SPI2 not busy */
	// while( SPI_GetFlagStatus(SPI2,SPI_BUSY_FLAG) );

    /* Disable SPI2 peripheral */
    SPI_PeripheralControl(SPI2, DISABLE);

    while(1);

    return 0;
}
