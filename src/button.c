#include "button.h"

_Bool is_down(Button *button)
{
    if (is_high((*button).port)) { //or button->port
        return 1;
    }

    return 0;
}


_Bool is_up(Button *button)
{
    if (is_low((*button).port)) {
        return 1;
    }

    return 0;
}

_Bool is_click(Button *button)
{
    if (is_down(button)) {
        (*button).down = 1;
    }

    if ((*button).down && is_up(button)) {
        (*button).up = 1;
    }
    
    if ((*button).down && (*button).up) {
        (*button).down = 0;
        (*button).up = 0;
        
        return 1;
    }

    return 0;
}
