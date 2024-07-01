/**
 * Gpio.h
 *
 *  Edited on: Apr 22, 2024
 *  Author    : Salma Ashraf and Yassmeen Tarek
 */

#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"

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


/*Data*/
#define LOW  0x00
#define HIGH 0x01

/*Status*/
#define OK 0
#define NOK 1


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);

int Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);



#endif /* GPIO_H */
