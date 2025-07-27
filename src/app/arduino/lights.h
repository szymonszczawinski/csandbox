#include <stdint.h>
typedef struct Light {
    uint8_t state : 1;
    uint8_t pin_number;

} light;

void init_lights();
void run_lights();
