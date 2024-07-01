## Project Overview
This project is a software solution that successfully displays a decimal counter value on a seven-segment display. It demonstrates the effective use of functions, multisource programming, and the addition of source files and include paths to the IDE.

## Features
- **GPIO Driver**: A custom GPIO driver is implemented with functions such as `GPIO_ConfigPin` and `GPIO_WritePin`. The `GPIO_ConfigPin` function initializes the GPIO registers based on the provided arguments, while the `GPIO_WritePin` function checks the initialized configuration of the requested pin argument and performs the write action if the configuration matches the request.
- **Seven Segment Display Control**: The main application uses the GPIO functions to control a seven-segment display and display a decimal counter value.

## Additional Enhancements
In addition to the basic functionality, a `GPIO_ReadPin` function was added to the GPIO driver, expanding its capabilities and allowing for more complex operations.