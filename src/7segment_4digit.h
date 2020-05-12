#ifndef _7_SEGMENT_4_DIGIT
#define _7_SEGMENT_4_DIGIT

#include "7segment.c"
#include "number.c"

extern const short digit_ports[4];

void turn_on();
void turn_off();
void turn_on_all();
void turn_off_all();
void output_number(short number);
void output_digit(short digit);

#endif
