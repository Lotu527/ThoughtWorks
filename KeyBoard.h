#ifndef KEYBOARDH
#define KEYBOARDH
#include<signal.h>

static int DISPLAY_RATE = 1000;
static bool DISPLAY_STOP = false;

void speedUp(int){
    DISPLAY_RATE = DISPLAY_RATE*5/10;
}
void speedDown(int){
    DISPLAY_RATE = DISPLAY_RATE*15/10;
}
void stop(int){
    DISPLAY_STOP = !DISPLAY_STOP;
}
void listen(){
    signal(SIGTSTP,stop);
    signal(SIGINT,speedUp);
    signal(SIGQUIT,speedDown);
}

#endif