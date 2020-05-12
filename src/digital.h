#ifndef DIGITAL
#define DIGITAL

#include "port.c"

void make_digital_high(Port port);
void make_digital_low(Port port);
_Bool is_high(Port pin);
_Bool is_low(Port pin);

#endif
