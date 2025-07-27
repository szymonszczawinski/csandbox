#include <stdint.h>
typedef enum
{
    LOW = 0,
    HIGH = 1,
    CHANGE = 2,
    FALLING = 3,
    RISING = 4,
} PinStatus;

typedef enum
{
    INPUT = 0x0,
    OUTPUT = 0x1,
    INPUT_PULLUP = 0x2,
    INPUT_PULLDOWN = 0x3,
    OUTPUT_OPENDRAIN = 0x4,
} PinMode;

void digitalWrite(uint8_t pin, int state);
void pinMode(uint8_t pin, int state);
void delay(unsigned long ms);
