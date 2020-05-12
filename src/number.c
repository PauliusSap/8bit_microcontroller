#include "util/number.h"

short get_number_of_digits(int number) {
    short digits = 0;

    if (number == 0) {
        digits++;
    }
   
    while (number != 0) {
        number /= 10;
        digits++;
    }

    return digits;
}

short get_position_of_number(int number, short pos)
{
    short i, n = 1, num_pos;
    for (i = 1; i < pos; i++) {
        n *= 10;
    }

    num_pos = (number/n)%10;
    if (num_pos < 0) {
        num_pos *= -1;
    }

    return num_pos;
}
