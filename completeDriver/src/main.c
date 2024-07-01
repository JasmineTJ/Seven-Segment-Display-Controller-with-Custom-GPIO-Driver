/*
 * main.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Salma Ashraf and Yassmeen Tarek
 */
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Gpio\Gpio.h"
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Rcc\Rcc.h"
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Lib\Utils.h"
#include "C:\Users\TJnotebook\eclipse-workspace\Lab4_Startup_Project\Lib\Bit_Operations.h"

// Define the pin numbers for the button and LEDs
#define BUTTON_PIN      3
#define RED_LED_PIN     5
#define GREEN_LED_PIN   6
#define BLUE_LED_PIN    7

// Define the debounce count threshold
#define DEBOUNCE_COUNT  10

// Declare a volatile integer for the debounce counter
volatile int debounceCounter = 0;

// Declare a static variable for the last button state, initially assumed not pressed
static uint32 lastButtonState = 1;

// Declare a volatile variable for the LED color state, initially set to 8
volatile uint32 ledColorState = 8;

// Interrupt handler for EXTI line 3
void EXTI3_IRQHandler(void) {
    // If the interrupt pending register of EXTI line for the button pin is set
    if (READ_BIT(EXTI_PR, BUTTON_PIN)) {
        // Clear the pending bit
        SET_BIT(EXTI_PR, BUTTON_PIN);
        // Increment the debounce counter
        debounceCounter++;
    }
}

// Main function
int main() {
    // Initialize the RCC
    Rcc_Init();

    // Enable the clock for GPIOB
    Rcc_Enable(RCC_GPIOB);

    // Configure the button pin as input with pull-up
    Gpio_ConfigPin(GPIO_B, BUTTON_PIN, GPIO_INPUT, PULL_UP);

    // Configure the LED pins as output
    Gpio_ConfigPin(GPIO_B, RED_LED_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_B, GREEN_LED_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_B, BLUE_LED_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);

    // Enable the interrupt for the button pin
    Gpio_EnableInterrupt(BUTTON_PIN);

    // Set the trigger for the button pin to falling edge
    Gpio_SetFallingTrigger(BUTTON_PIN);

    // Enable the NVIC interrupt with interrupt number 9
    Gpio_EnableNvicInterrupt(9);

    // Main loop
    while (1) {
        // Turn off all LEDs at the start of each loop iteration
        Gpio_WritePin(GPIO_B, RED_LED_PIN, LOW);
        Gpio_WritePin(GPIO_B, GREEN_LED_PIN, LOW);
        Gpio_WritePin(GPIO_B, BLUE_LED_PIN, LOW);

        // If the debounce counter has reached the threshold
        if (debounceCounter >= DEBOUNCE_COUNT) {
            // Reset the debounce counter
            debounceCounter = 0;

            // Increment the LED color state
            ledColorState++;

            // If the LED color state exceeds the maximum
            if (ledColorState > 8) {
                // Reset the LED color state
                ledColorState = 1;
            }
        }

        // Read the button state into currentButtonState
        uint32 currentButtonState = Gpio_ReadPin(GPIO_B, BUTTON_PIN);

        // If a falling edge is detected on the button pin
        if (lastButtonState && !currentButtonState) {
            // Increment the LED color state
            ledColorState++;

            // If the LED color state exceeds the maximum
            if (ledColorState > 8) {
                // Reset the LED color state
                ledColorState = 1;
            }
        }

        // Update lastButtonState with the current button state
        lastButtonState = currentButtonState;

        // Switch on the LED color state
        switch (ledColorState) {
            case 1: // Red
                Gpio_WritePin(GPIO_B, RED_LED_PIN, HIGH);
                break;
            case 2: // Green
                Gpio_WritePin(GPIO_B, GREEN_LED_PIN, HIGH);
                break;
            case 3: // Blue
                Gpio_WritePin(GPIO_B, BLUE_LED_PIN, HIGH); 
                break;
            case 4: // Yellow (Red + Green)
                Gpio_WritePin(GPIO_B, RED_LED_PIN, HIGH);
                Gpio_WritePin(GPIO_B, GREEN_LED_PIN, HIGH); 
                break;
            case 5: // Magenta (Red + Blue)
                Gpio_WritePin(GPIO_B, RED_LED_PIN, HIGH);
                Gpio_WritePin(GPIO_B, BLUE_LED_PIN, HIGH);
                break;
            case 6: // Cyan (Green + Blue)
                Gpio_WritePin(GPIO_B, GREEN_LED_PIN, HIGH);
                Gpio_WritePin(GPIO_B, BLUE_LED_PIN, HIGH);
                break;
            case 7: // White (Red + Green + Blue)
                Gpio_WritePin(GPIO_B, RED_LED_PIN, HIGH);
                Gpio_WritePin(GPIO_B, GREEN_LED_PIN, HIGH);
                Gpio_WritePin(GPIO_B, BLUE_LED_PIN, HIGH);
                break;
            case 8: // All LEDs off
                Gpio_WritePin(GPIO_B, RED_LED_PIN, LOW);
                Gpio_WritePin(GPIO_B, GREEN_LED_PIN, LOW);
                Gpio_WritePin(GPIO_B, BLUE_LED_PIN, LOW);
                break;
            default: // If the LED color state is not within 1-8, reset it to 8
                ledColorState = 8;
                break;
        }
    }

    // Return 0 for successful execution
    return 0;
}
