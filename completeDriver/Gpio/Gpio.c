/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Gpio\Gpio.h"

#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Gpio\Gpio_Private.h"
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Lib\Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState)
{
    switch (PortName)
    {
    case GPIO_A:
        GPIOA_MODER &= ~(0x03 << (PinNum * 2));  // Clear the mode bits for the pin
        GPIOA_MODER |= (PinMode << (PinNum * 2));  // Set the mode bits for the pin

        if (PinMode == GPIO_INPUT) {
            GPIOA_PUPDR &= ~(0x03 << (PinNum * 2));  // Clear the pull-up/pull-down bits for the pin
            GPIOA_PUPDR |= (DefaultState << (PinNum * 2));  // Set the pull-up/pull-down bits for the pin
        } else {
            GPIOA_OTYPER &= ~(0x01 << PinNum);  // Clear the type bit for the pin
            GPIOA_OTYPER |= (DefaultState << PinNum);  // Set the type bit for the pin
        }
        break;
    case GPIO_B:
        GPIOB_MODER &= ~(0x03 << (PinNum * 2));  // Clear the mode bits for the pin
        GPIOB_MODER |= (PinMode << (PinNum * 2));  // Set the mode bits for the pin

        if (PinMode == GPIO_INPUT) {
            GPIOB_PUPDR &= ~(0x03 << (PinNum * 2));  // Clear the pull-up/pull-down bits for the pin
            GPIOB_PUPDR |= (DefaultState << (PinNum * 2));  // Set the pull-up/pull-down bits for the pin
        } else {
            GPIOB_OTYPER &= ~(0x01 << PinNum);  // Clear the type bit for the pin
            GPIOB_OTYPER |= (DefaultState << PinNum);  // Set the type bit for the pin
        }
        break;
    case GPIO_C:
        GPIOC_MODER &= ~(0x03 << (PinNum * 2));  // Clear the mode bits for the pin
        GPIOC_MODER |= (PinMode << (PinNum * 2));  // Set the mode bits for the pin

        if (PinMode == GPIO_INPUT) {
            GPIOC_PUPDR &= ~(0x03 << (PinNum * 2));  // Clear the pull-up/pull-down bits for the pin
            GPIOC_PUPDR |= (DefaultState << (PinNum * 2));  // Set the pull-up/pull-down bits for the pin
        } else {
            GPIOC_OTYPER &= ~(0x01 << PinNum);  // Clear the type bit for the pin
            GPIOC_OTYPER |= (DefaultState << PinNum);  // Set the type bit for the pin
        }
        break;
    case GPIO_D:
        GPIOD_MODER &= ~(0x03 << (PinNum * 2));  // Clear the mode bits for the pin
        GPIOD_MODER |= (PinMode << (PinNum * 2));  // Set the mode bits for the pin

        if (PinMode == GPIO_INPUT) {
            GPIOD_PUPDR &= ~(0x03 << (PinNum * 2));  // Clear the pull-up/pull-down bits for the pin
            GPIOD_PUPDR |= (DefaultState << (PinNum * 2));  // Set the pull-up/pull-down bits for the pin
        } else {
            GPIOD_OTYPER &= ~(0x01 << PinNum);  // Clear the type bit for the pin
            GPIOD_OTYPER |= (DefaultState << PinNum);  // Set the type bit for the pin
        }
        break;
    default:
        break;
    }
}

// Function to write data to a GPIO pin
// This function checks all 4 ports (GPIO_A, GPIO_B, GPIO_C, GPIO_D)
uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{
    uint8 check;  // Variable to hold the check value

    // Switch case to handle different GPIO ports
    switch (PortName)
    {
    case GPIO_A:
        // Check the mode of the pin in GPIOA
        check = (GPIOA_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
        break;
    case GPIO_B:
        // Check the mode of the pin in GPIOB
        check = (GPIOB_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
        break;
    case GPIO_C:
        // Check the mode of the pin in GPIOC
        check = (GPIOC_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
        break;
    case GPIO_D:
        // Check the mode of the pin in GPIOD
        check = (GPIOD_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
        break;
    default:
        // Return NOK if an invalid port name is provided
        return NOK;
    }

    // If the pin is in output mode
    if (check == 0x01)
    {
        // Switch case to handle different GPIO ports
        switch (PortName)
        {
        case GPIO_A:
            // Clear the bit in the output data register of GPIOA
            GPIOA_ODR &= ~(0x1 << PinNum);
            // Set the bit in the output data register of GPIOA with the provided data
            GPIOA_ODR |= (Data << PinNum);
            break;
        case GPIO_B:
            // Clear the bit in the output data register of GPIOB
            GPIOB_ODR &= ~(0x1 << PinNum);
            // Set the bit in the output data register of GPIOB with the provided data
            GPIOB_ODR |= (Data << PinNum);
            break;
        case GPIO_C:
            // Clear the bit in the output data register of GPIOC
            GPIOC_ODR &= ~(0x1 << PinNum);
            // Set the bit in the output data register of GPIOC with the provided data
            GPIOC_ODR |= (Data << PinNum);
            break;
        case GPIO_D:
            // Clear the bit in the output data register of GPIOD
            GPIOD_ODR &= ~(0x1 << PinNum);
            // Set the bit in the output data register of GPIOD with the provided data
            GPIOD_ODR |= (Data << PinNum);
            break;
        default:
            break;
        }
        // Return OK if the operation is successful
        return OK;
    }
    else
    {
        // Return NOK if the pin is not in output mode
        return NOK;
    }
}

// Function to read the state of a GPIO pin
uint32 Gpio_ReadPin(uint8 PortName, uint8 PinNum)
{
    uint32 pinState = 0;  // Variable to hold the state of the pin

    // Switch case to handle different GPIO ports
    switch (PortName)
    {
    case GPIO_A:
        pinState = GPIOA_IDR & (1 << PinNum);  // Read the state of the pin from GPIOA
        break;
    case GPIO_B:
        pinState = GPIOB_IDR & (1 << PinNum);  // Read the state of the pin from GPIOB
        break;
    case GPIO_C:
        pinState = GPIOC_IDR & (1 << PinNum);  // Read the state of the pin from GPIOC
        break;
    case GPIO_D:
        pinState = GPIOD_IDR & (1 << PinNum);  // Read the state of the pin from GPIOD
        break;
    default:
        break;  // If the port name doesn't match any case, do nothing
    }

    return pinState;  // Return the state of the pin
}

// Function to enable the interrupt for a GPIO pin
void Gpio_EnableInterrupt(uint8 PinNum) {
    EXTI_IMR |= (1 << PinNum);  // Set the corresponding bit in the interrupt mask register
}

// Function to set the trigger for a GPIO pin to falling edge
void Gpio_SetFallingTrigger(uint8 PinNum) {
    EXTI_FTSR |= (1 << PinNum);  // Set the corresponding bit in the falling trigger selection register
}

// Function to enable the NVIC interrupt
void Gpio_EnableNvicInterrupt(uint8 InterruptNum) {
    NVIC_ISER0 |= (1 << InterruptNum);  // Set the corresponding bit in the NVIC interrupt set-enable register
}
