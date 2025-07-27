#include "common.h"
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
void digitalWrite(uint8_t pin, int state)
{
    printf("OUT: pin %d state %d\n", pin, state);
}
void pinMode(uint8_t pin, int mode)
{
    printf("MODE: pin %d mode %d\n", pin, mode);
}

void delay(unsigned long ms)
{
    printf("sleep for %lums\n", ms);
    sleep((ms / 1000));
}
