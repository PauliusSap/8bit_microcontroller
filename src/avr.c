#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "7segment_4digit.c"
#include "button.c"

Button button;
Button *btn;

int count_click = 0;

void setup()
{
    DDRA = 0b0000000;
    _SFR_IO8(0x04) = 0b11110100; //DDRB Port Data Direction Register
    DDRC = 0b0000000;
    DDRD = 0b0000000;
    _SFR_IO8(0x0D) = 0b00111000; //DDRE
    DDRF = 0b0000000;
    _SFR_IO8(0x13) = 0b00100000; //DDRG
    DDRH = 0b01111000;


    port_input_pin_address['A'] = &_SFR_IO8(0x00);
    port_input_pin_address['B'] = &_SFR_IO8(0x03);
    port_input_pin_address['C'] = &_SFR_IO8(0x06);
    port_input_pin_address['D'] = &_SFR_IO8(0x09);
    port_input_pin_address['E'] = &_SFR_IO8(0x0C);
    port_input_pin_address['F'] = &_SFR_IO8(0x0F);
    port_input_pin_address['G'] = &_SFR_IO8(0x12);
    port_input_pin_address['H'] = &PINH;

    //TODO better port mapping
    port_data_register['A'] = &_SFR_IO8(0x02);
    port_data_register['B'] = &_SFR_IO8(0x05);
    port_data_register['C'] = &_SFR_IO8(0x08);
    port_data_register['D'] = &_SFR_IO8(0x0B);
    port_data_register['E'] = &_SFR_IO8(0x0E);
    port_data_register['F'] = &_SFR_IO8(0x11);
    port_data_register['G'] = &_SFR_IO8(0x14);
    port_data_register['H'] = &PORTH;

    button.port = get_port(50);
    btn = &button;
}

void beep(int level)
{
    int i;

    for (i = 0; i < level; i++) {
        make_digital_high(get_port(51));
        _delay_us(500);
        make_digital_low(get_port(51));
        _delay_us(500);
    }
}

void loop()
{
    if (is_click(btn)) {
        count_click++;

        beep(30*count_click);
    }

    output_number(count_click);
}
    
int main()
{
    setup();

    while (1) { 
        loop(); 
    }

    return 0;
}
