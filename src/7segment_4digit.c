#include "7segment_4digit.h"

const short digit_ports[4] = { 10, 11, 12, 13 };

void turn_on(int digit)
{
    make_digital_low(get_port(digit_ports[digit-1]));
}

void turn_off(int digit)
{
    make_digital_high(get_port(digit_ports[digit-1]));
}

void turn_on_all()
{
    int i;
    for (i = 1; i <= sizeof(digit_ports)/sizeof(short); i++) {
        turn_on(i);
    }
}

void turn_off_all()
{
    int i;
    for (i = 1; i <= sizeof(digit_ports)/sizeof(short); i++) {
        turn_off(i);
    }
}

void output_number(short number)
{
    short i;
    short num_of_digits = get_number_of_digits(number);

    for (i = 1; i <= num_of_digits; i++) {
        
        int digit_num = get_reverse_num_from_max(sizeof(digit_ports)/sizeof(short), i);
        
        turn_off_all();
        turn_on(digit_num);
        output_digit(get_position_of_number(number, i));
        clear_display();
    }
}

//TODO migrate
int get_reverse_num_from_max(int max, int num)
{
    return ((max+1) - num);
}

//TODO make pointer array output[0], output[1] and etc.
void output_digit(short digit)
{
    if (digit == 0) {
        output_zero();
    } else if (digit == 1) {
        output_one();
    } else if (digit == 2) {
        output_two();
    } else if (digit == 3) {
        output_three();
    } else if (digit == 4) {
        output_four();
    } else if (digit == 5) {
        output_five();
    } else if (digit == 6) {
        output_six();
    } else if (digit == 7) {
        output_seven();
    } else if (digit == 8) {
        output_eight();
    } else if (digit == 9) {
        output_nine();
    }
}

