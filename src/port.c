#include "port.h"

volatile uint8_t *port_data_register[0];
volatile uint8_t *port_pinInputAddress[8];

const char port_letters[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
const short port_numbers[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

Port get_port(short avr_pin_number) {
	Port port;
	
	switch (avr_pin_number) {
		case 2:
			port.letter = 'E';
			port.number = 4;
			break;

		case 3:
			port.letter = 'E';
			port.number = 5;
			break;

		case 4:
			port.letter = 'G';
			port.number = 5;
			break;

		case 5:
			port.letter = 'E';
			port.number = 3;
			break;

		case 6:
			port.letter = 'H';
			port.number = 3;
			break;

		case 7:
			port.letter = 'H';
			port.number = 4;
			break;

		case 8:
			port.letter = 'H';
			port.number = 5;
			break;

		case 9:
			port.letter = 'H';
			port.number = 6;
			break;
			
		case 10:
			port.letter = 'B';
			port.number = 4;
			break;

		case 11:
			port.letter = 'B';
			port.number = 5;
			break;

		case 12:
			port.letter = 'B';
			port.number = 6;
			break;

		case 13:
			port.letter = 'B';
			port.number = 7;
			break;

		case 50:
			port.letter = 'B';
			port.number = 3;
            break;

		case 51:
			port.letter = 'B';
			port.number = 2;
            break;

		case 52:
			port.letter = 'B';
			port.number = 1;
            break;

		case 53:
			port.letter = 'B';
			port.number = 0;
            break;

		default:
			port.letter = 'X';
			port.number = 0;
	}

	return port;
}
