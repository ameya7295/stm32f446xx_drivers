/*004_main
 * This is used to demonstrate the ISR
 * */

// #include "stm32f446xx.h"
#include <stdio.h>

// void delay(int ms)
// {
// 	for(uint32_t i = 0; i <ms; i++);
// }

int main(void)
{

	return 0;
}

// void EXTI0_IRQHandler(void)
// {
// 	GPIO_IRQHandle(0);
// }

// 22:10:44 **** Build of configuration Debug for project stm32f4xx_drivers ****
// make -j4 all 
// arm-none-eabi-gcc "../drivers/Src/stm32f446xx_gpio_driver.c" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"/home/administrator/Documents/STM32/stm32f4xx_drivers/drivers/Inc" -I"/home/administrator/Documents/STM32/stm32f4xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"drivers/Src/stm32f446xx_gpio_driver.d" -MT"drivers/Src/stm32f446xx_gpio_driver.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "drivers/Src/stm32f446xx_gpio_driver.o"
// arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"/home/administrator/Documents/STM32/stm32f4xx_drivers/drivers/Inc" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f446retx.d" -MT"Startup/startup_stm32f446retx.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "Startup/startup_stm32f446retx.o" "../Startup/startup_stm32f446retx.s"
// arm-none-eabi-gcc "../Src/001_led_toggle.c" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"/home/administrator/Documents/STM32/stm32f4xx_drivers/drivers/Inc" -I"/home/administrator/Documents/STM32/stm32f4xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Src/001_led_toggle.d" -MT"Src/001_led_toggle.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "Src/001_led_toggle.o"
// arm-none-eabi-gcc -o "stm32f4xx_drivers.elf" @"objects.list"   -mcpu=cortex-m4 -T"/home/administrator/Documents/STM32/stm32f4xx_drivers/STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32f4xx_drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
// /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/hard/libc_nano.a(libc_a-closer.o): in function `_close_r':
// (.text._close_r+0xc): warning: _close is not implemented and will always fail
// /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/hard/libc_nano.a(libc_a-lseekr.o): in function `_lseek_r':
// (.text._lseek_r+0x10): warning: _lseek is not implemented and will always fail
// /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/hard/libc_nano.a(libc_a-readr.o): in function `_read_r':
// (.text._read_r+0x10): warning: _read is not implemented and will always fail
// /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/administrator/.eclipse/com.st.stm32cube.ide.mcu.rcp.product_1.19.0_139068057_linux_gtk_x86_64/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.12.3.rel1.linux64_1.1.0.202410170702/tools/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/hard/libc_nano.a(libc_a-writer.o): in function `_write_r':
// (.text._write_r+0x10): warning: _write is not implemented and will always fail
// Finished building target: stm32f4xx_drivers.elf
 
// arm-none-eabi-size  stm32f4xx_drivers.elf 
// arm-none-eabi-objdump -h -S stm32f4xx_drivers.elf  > "stm32f4xx_drivers.list"
//    text	   data	    bss	    dec	    hex	filename
//    2064	      0	   1568	   3632	    e30	stm32f4xx_drivers.elf
// Finished building: default.size.stdout
 
// Finished building: stm32f4xx_drivers.list
 

// 22:10:44 Build Finished. 0 errors, 4 warnings. (took 272ms)
