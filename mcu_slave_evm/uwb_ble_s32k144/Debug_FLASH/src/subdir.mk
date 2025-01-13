################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/commble.c \
../src/commcanoe.c \
../src/commpc.c \
../src/commuwb.c \
../src/main.c \
../src/util.c 

OBJS += \
./src/commble.o \
./src/commcanoe.o \
./src/commpc.o \
./src/commuwb.o \
./src/main.o \
./src/util.o 

C_DEPS += \
./src/commble.d \
./src/commcanoe.d \
./src/commpc.d \
./src/commuwb.d \
./src/main.d \
./src/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/commble.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


