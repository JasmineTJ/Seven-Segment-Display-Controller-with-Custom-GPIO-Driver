/**
 * main.c
 *
 *  Edited on: Apr 22, 2024
 *  Author    : Salma Ashraf and Yassmeen Tarek
 */

#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

int main() {
  // Initialize system clock
  Rcc_Init();
  // Enable GPIOA clock
  Rcc_Enable(RCC_GPIOA);
  // Configure GPIO pins as outputs
  uint32 i = 0;
  for (i = 0; i < 7; i++) {
    Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
  }
  // Initialize counter
  uint8 counter = 0;
  // Infinite loop for 7-Segment sequence
  while (1) {
	// Switch case to control 7-Segment sequence based on counter value
	switch (counter)
	{
	case 0:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, LOW);
		break;
	
	case 1:
		Gpio_WritePin(GPIO_A, 0, LOW);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, LOW);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, LOW);

		break;
	case 2:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, LOW);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 3:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 4:
		Gpio_WritePin(GPIO_A, 0, LOW);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, LOW);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 5:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, LOW);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 6:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, LOW);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 7:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, LOW);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, LOW);
		Gpio_WritePin(GPIO_A, 6, LOW);

		break;
	case 8:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, HIGH);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	case 9:
		Gpio_WritePin(GPIO_A, 0, HIGH);
		Gpio_WritePin(GPIO_A, 1, HIGH);
		Gpio_WritePin(GPIO_A, 2, HIGH);
		Gpio_WritePin(GPIO_A, 3, HIGH);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);

		break;
	default:

		break;
	}
	// Delay loop to control 7-Segment sequence speed
	for(i=0 ; i <1000000;i++ ){}
	// Increment counter
	counter++;
	// Reset counter if it reaches 10
	if(counter == 10){
		counter = 0;
	}

  }

  return 0;
}
