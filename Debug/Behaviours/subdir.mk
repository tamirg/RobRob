################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Behaviours/Behavior.cpp \
../Behaviours/GoForward.cpp \
../Behaviours/TurnInPlace.cpp \
../Behaviours/TurnLeft.cpp \
../Behaviours/TurnRight.cpp 

OBJS += \
./Behaviours/Behavior.o \
./Behaviours/GoForward.o \
./Behaviours/TurnInPlace.o \
./Behaviours/TurnLeft.o \
./Behaviours/TurnRight.o 

CPP_DEPS += \
./Behaviours/Behavior.d \
./Behaviours/GoForward.d \
./Behaviours/TurnInPlace.d \
./Behaviours/TurnLeft.d \
./Behaviours/TurnRight.d 


# Each subdirectory must supply rules for building sources it contributes
Behaviours/%.o: ../Behaviours/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


