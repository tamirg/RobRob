################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MapLibraries/lodepng.cpp \
../MapLibraries/pngUtil.cpp 

OBJS += \
./MapLibraries/lodepng.o \
./MapLibraries/pngUtil.o 

CPP_DEPS += \
./MapLibraries/lodepng.d \
./MapLibraries/pngUtil.d 


# Each subdirectory must supply rules for building sources it contributes
MapLibraries/%.o: ../MapLibraries/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


