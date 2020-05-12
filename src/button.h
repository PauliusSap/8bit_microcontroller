#ifndef BUTTON
#define BUTTON

typedef struct {
    Port port;
    _Bool down;
    _Bool up;
    _Bool click;
} Button;

_Bool is_down(Button *button);
_Bool is_up(Button *button);
_Bool is_click(Button *button);

#endif
