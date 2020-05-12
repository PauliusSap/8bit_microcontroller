#ifndef _7_SEGMENT
#define _7_SEGMENT

#include "port.h"

extern const char segments[8];

Port get_display_port(char display_port);

void clear_display();

void output_one();
void output_two();
void output_three();
void output_four();
void output_five();
void output_six();
void output_seven();
void output_eight();
void output_nine();

#endif
