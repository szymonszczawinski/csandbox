#include "lights.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

light *red;
light *yellow;
light *green;

light *init_light(uint8_t pin, uint8_t state);
void switch_light(light *l, uint8_t new_state);
void green_to_red();
void red_to_green();

void init_lights()
{
    printf("init lights\n");
    red = init_light(10, 0);
    yellow = init_light(9, 0);
    green = init_light(8, 0);
    switch_light(green, 1);
}

void run_lights()
{
    printf(" run lights\n");
    green_to_red();
    delay(10 * 1000);
    red_to_green();
}

light *init_light(uint8_t pin, uint8_t state)
{
    light *l = malloc(sizeof(light));
    l->pin_number = pin;
    l->state = state;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    return l;
}

void switch_light(light *l, uint8_t new_state)
{
    if (new_state != l->state) {
        if (new_state == 0) {
            digitalWrite(l->pin_number, LOW);
        } else {
            digitalWrite(l->pin_number, HIGH);
        }
        l->state = new_state;
    }
}

uint8_t is_light_off(light *l) { return l->state == 0; }
uint8_t is_light_on(light *l) { return l->state > 0; }

void green_to_red()
{
    printf("green to red\n");
    if (is_light_on(green)) {
        switch_light(green, 0);
        switch_light(yellow, 1);
        delay(2000);
        switch_light(yellow, 0);
        switch_light(red, 1);
    }
}
void red_to_green()
{
    printf("red to green\n");
    if (is_light_on(red)) {
        switch_light(yellow, 1);
        delay(2000);
        switch_light(yellow, 0);
        switch_light(red, 0);
        switch_light(green, 1);
    }
}
