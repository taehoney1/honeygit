################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/clock_config.c \
../board/flash_memory_drive.c \
../board/peripherals_can_pal1.c \
../board/peripherals_edma_config_1.c \
../board/peripherals_flash_FTFC.c \
../board/peripherals_lpspi_1.c \
../board/peripherals_lpspi_2.c \
../board/peripherals_lpuart_LPUART_1.c \
../board/peripherals_lpuart_LPUART_2.c \
../board/peripherals_osif1.c \
../board/pin_mux.c 

OBJS += \
./board/clock_config.o \
./board/flash_memory_drive.o \
./board/peripherals_can_pal1.o \
./board/peripherals_edma_config_1.o \
./board/peripherals_flash_FTFC.o \
./board/peripherals_lpspi_1.o \
./board/peripherals_lpspi_2.o \
./board/peripherals_lpuart_LPUART_1.o \
./board/peripherals_lpuart_LPUART_2.o \
./board/peripherals_osif1.o \
./board/pin_mux.o 

C_DEPS += \
./board/clock_config.d \
./board/flash_memory_drive.d \
./board/peripherals_can_pal1.d \
./board/peripherals_edma_config_1.d \
./board/peripherals_flash_FTFC.d \
./board/peripherals_lpspi_1.d \
./board/peripherals_lpspi_2.d \
./board/peripherals_lpuart_LPUART_1.d \
./board/peripherals_lpuart_LPUART_2.d \
./board/peripherals_osif1.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@board/clock_config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


