
# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/spi_if.c \
../src/stm32_it.c \
../src/usbd_desc.c \
../src/usbd_req.c \
../src/usbd_core.c \
../src/usb_bsp.c \
../src/usbd_dfu_core.c \
../src/usbd_ioreq.c \
../src/usb_dcd.c \
../src/usb_core.c \
../src/usbd_dfu_mal.c \
../src/usbd_flash_if.c \
../src/usbd_spi_if.c \
../src/usbd_usr.c \
../src/usbd_otp_if.c \
../src/usb_dcd_int.c

OBJS += \
./src/main.o \
./src/stm32_it.o \
./src/usbd_desc.o \
./src/usbd_req.o \
./src/usbd_core.o \
./src/usb_bsp.o \
./src/usbd_dfu_core.o \
./src/usbd_ioreq.o \
./src/usb_dcd.o \
./src/usb_core.o \
./src/usbd_dfu_mal.o \
./src/usbd_flash_if.o \
./src/usbd_spi_if.o \
./src/usbd_usr.o \
./src/usbd_otp_if.o \
./src/usb_dcd_int.o

C_DEPS += \
./src/main.d \
./src/stm32_it.d \
./src/usbd_desc.d \
./src/usbd_req.d \
./src/usbd_core.d \
./src/usb_bsp.d \
./src/usbd_dfu_core.d \
./src/usbd_ioreq.d \
./src/usb_dcd.d \
./src/usb_core.d \
./src/usbd_dfu_mal.d \
./src/usbd_flash_if.d \
./src/usbd_spi_if.d \
./src/usbd_usr.d \
./src/usbd_otp_if.d \
./src/usb_dcd_int.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DSTM32F40_41xxx -DUSE_USB_OTG_FS -I"../../core-common-lib/CMSIS/Include" -I"../../core-common-lib/CMSIS/Device/ST/STM32F4xx/Include" -I"../../core-common-lib/STM32F4xx_StdPeriph_Driver/inc" -I"../../core-common-lib/STM32_USB-FS-Device_Driver/inc" -I"../../core-common-lib/CC3000_Host_Driver" -I"../../core-common-lib/SPARK_Firmware_Driver/inc" -I"../inc" -I"../../STM32_USB_Device_Library/Class/dfu/inc" -I"../../STM32_USB_Device_Library/Core/inc" -I"../../STM32_USB_OTG_Driver/inc" -Os -ffunction-sections -Wall -Wfatal-errors -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


