#include "7segment.h"
#include "digital.c"

const char segments[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

Port get_display_port(char display_segment)
{
    Port display_port;
		 if (display_segment == segments[0]) { display_port = get_port(2); }
	else if (display_segment == segments[1]) { display_port = get_port(3); }
	else if (display_segment == segments[2]) { display_port = get_port(4); }
	else if (display_segment == segments[3]) { display_port = get_port(5); }
	else if (display_segment == segments[4]) { display_port = get_port(6); }
	else if (display_segment == segments[5]) { display_port = get_port(7); }
	else if (display_segment == segments[6]) { display_port = get_port(8); }
	else if (display_segment == segments[7]) { display_port = get_port(9); }

	return display_port;
}

void clear_display()
{
    int i;
    for (i = 0; i < sizeof(segments); i++) {
        make_digital_low(get_display_port(segments[i]));
    }
}

void output_zero()
{
    make_digital_high(get_display_port('A'));
    make_digital_high(get_display_port('B'));
    make_digital_high(get_display_port('C'));
    make_digital_high(get_display_port('D'));
    make_digital_high(get_display_port('E'));
    make_digital_high(get_display_port('F'));
}

void output_one()
{
    make_digital_high(get_display_port('B'));
    make_digital_high(get_display_port('C'));
}

void output_two()
{
    make_digital_high(get_display_port('A'));
    make_digital_high(get_display_port('B'));
    make_digital_high(get_display_port('D'));
    make_digital_high(get_display_port('E'));
    make_digital_high(get_display_port('G'));
}

void output_three()
{
    output_one();
    make_digital_high(get_display_port('A'));
    make_digital_high(get_display_port('D'));
    make_digital_high(get_display_port('G'));
}

void output_four()
{
    output_one();
    make_digital_high(get_display_port('F'));
    make_digital_high(get_display_port('G'));
}

void output_five()
{
    make_digital_high(get_display_port('A'));
    make_digital_high(get_display_port('C'));
    make_digital_high(get_display_port('D'));
    make_digital_high(get_display_port('F'));
    make_digital_high(get_display_port('G'));
}

void output_six()
{
    output_five();
    make_digital_high(get_display_port('E'));
}

void output_seven()
{
    output_one();
    make_digital_high(get_display_port('A'));
}

void output_eight()
{
    output_zero();
    make_digital_high(get_display_port('G'));
}

void output_nine()
{
    output_three();
    make_digital_high(get_display_port('F'));
}
