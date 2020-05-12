#include "digital.h"

void make_digital_high(Port port)
{
   *port_data_register[port.letter] |= (1 << port.number);
}

void make_digital_low(Port port)
{
    *port_data_register[port.letter] &= ~(1 << port.number);
}

_Bool is_high(Port port_pin)
{
    if (*(port_input_pin_address[port_pin.letter]) & (1 << port_pin.number)) {
        return 1;
    }
    
    return 0;
}

_Bool is_low(Port port_pin)
{
    if (!(*(port_input_pin_address[port_pin.letter]) & (1 << port_pin.number))) {
        return 1;
    }

    return 0;
}
