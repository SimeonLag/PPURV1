################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EchoTest/EchoTest.c \
../EchoTest/FormatOutputSpy.c \
../EchoTest/unity.c 

OBJS += \
./EchoTest/EchoTest.o \
./EchoTest/FormatOutputSpy.o \
./EchoTest/unity.o 

C_DEPS += \
./EchoTest/EchoTest.d \
./EchoTest/FormatOutputSpy.d \
./EchoTest/unity.d 


# Each subdirectory must supply rules for building sources it contributes
EchoTest/%.o: ../EchoTest/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/rtrk/workspace10/CircularBuffer" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


