/**
 * Gpio.h
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#ifndef GPIO_H
#define GPIO_H
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Lib\Std_Types.h"

/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

/*PinMode*/
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

/*DefaultState*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01
#define NO_PULL_UP_DOWN 0x00
#define PULL_UP         0x01
#define PULL_DOWN       0x02
#define RESERVED        0x03

/*Data*/
#define LOW  0x00
#define HIGH 0x01

// Define OK as 0, used to indicate successful operation
#define OK 0

// Define NOK as 1, used to indicate unsuccessful operation
#define NOK 1

// Define EXTI_PR as the address of the pending register in the EXTI peripheral
// REG32 is a macro that takes the base address and offset as parameters and returns the address of the register
#define EXTI_PR REG32(0x40013C00, 0x14)


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);

uint32 Gpio_ReadPin(uint8 PortName, uint8 PinNum);

void Gpio_EnableInterrupt(uint8 PinNum);

void Gpio_SetFallingTrigger(uint8 PinNum);

void Gpio_EnableNvicInterrupt(uint8 InterruptNum);

#endif /* GPIO_H */
