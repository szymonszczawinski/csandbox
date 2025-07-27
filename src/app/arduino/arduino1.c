#include "arduino1.h"
#include "lights.h"
#include <stdint.h>
#include <stdio.h>

void setup()
{
    printf("----------setup---------------\n");
    init_lights();
}

void loop()
{
    printf("-----------loop----------------\n");
    run_lights();
}

int run_arduino1()
{
    setup();
    loop();
    return 0;
}
