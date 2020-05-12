/**
Header Guad

This is a preprocessor technique of preventing a header file from being included multiple times
*/
#ifndef PORT
#define PORT

volatile uint8_t *port_data_register[0];
volatile uint8_t *port_input_pin_address[8];

/**
For global variables use the "extern" keyword
Compiler indicate that a global of the specified name and type has been declared elsewhere.
This will then be cleaned up by the linker when the project is built.
*/
extern const char port_letters[];
extern const short port_numbers[];

typedef struct {
	char letter;
	short number;
} Port;

Port get_port(short avr_pin_number);

#endif
