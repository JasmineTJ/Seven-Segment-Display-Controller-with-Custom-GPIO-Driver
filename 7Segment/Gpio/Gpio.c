/**
 * Gpio.c
 *
 *  Edited on: Apr 22, 2024
 *  Author    : Salma Ashraf and Yassmeen Tarek
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

/**
 * Configure a GPIO pin.
 *
 * @param PortName The name of the GPIO port (e.g., GPIO_A, GPIO_B, GPIO_C, GPIO_D).
 * @param PinNum The pin number to configure.
 * @param PinMode The mode to configure the pin (e.g., GPIO_INPUT, GPIO_OUTPUT).
 * @param DefaultState The default state of the pin (e.g., GPIO_PUSH_PULL, GPIO_OPEN_DRAIN).
 */
void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
		uint8 DefaultState) {
	switch (PortName) {
	case GPIO_A:
		// Configure pin mode
		GPIOA_MODER &= ~(0x03 << (PinNum * 2)); // Clear bits
		GPIOA_MODER |= (PinMode << (PinNum * 2)); // Set mode bits
		// Configure pin output type
		GPIOA_OTYPER &= ~(0x01 << PinNum); // Clear bit
		GPIOA_OTYPER |= (DefaultState << PinNum); // Set output type

		break;
	case GPIO_B:
		GPIOB_MODER &= ~(0x03 << (PinNum * 2));
		GPIOB_MODER |= (PinMode << (PinNum * 2));

		GPIOB_OTYPER &= ~(0x01 << PinNum);
		GPIOB_OTYPER |= (DefaultState << PinNum);

		break;
	case GPIO_C:
		GPIOC_MODER &= ~(0x03 << (PinNum * 2));
		GPIOC_MODER |= (PinMode << (PinNum * 2));

		GPIOC_OTYPER &= ~(0x01 << PinNum);
		GPIOC_OTYPER |= (DefaultState << PinNum);

		break;
	case GPIO_D:
		GPIOD_MODER &= ~(0x03 << (PinNum * 2));
		GPIOD_MODER |= (PinMode << (PinNum * 2));

		GPIOD_OTYPER &= ~(0x01 << PinNum);
		GPIOD_OTYPER |= (DefaultState << PinNum);

		break;
	default:
		break;
	}
}

/**
 * Write data to a specific pin of a GPIO port.
 *
 * @param PortName The name of the GPIO port (e.g., GPIO_A, GPIO_B, GPIO_C, GPIO_D).
 * @param PinNum The pin number to write data to.
 * @param Data The data to be written to the pin (HIGH or LOW).
 * @return OK if the operation is successful, NOK otherwise.
 */
int Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {
	// Check if the pin is configured as an output
	uint8 check = (GPIOA_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
	if (check == 0x01) {
		// Configure the pin based on the GPIO port
		switch (PortName) {
		case GPIO_A:
			GPIOA_ODR &= ~(0x1 << PinNum); // Clear the pin
			GPIOA_ODR |= (Data << PinNum); // Set data to the pin

			break;
		case GPIO_B:
			GPIOB_ODR &= ~(0x1 << PinNum);
			GPIOB_ODR |= (Data << PinNum);

			break;
		case GPIO_C:
			GPIOC_ODR &= ~(0x1 << PinNum);
			GPIOC_ODR |= (Data << PinNum);

			break;
		case GPIO_D:
			GPIOD_ODR &= ~(0x1 << PinNum);
			GPIOD_ODR |= (Data << PinNum);

			break;
		default:
			break;
		}

		return OK; // Return OK (OK = 0) if the operation is successful
	}
	else{
		return NOK; // Return NOK (NOK = 1) if the pin is not configured as an output
	}
}
