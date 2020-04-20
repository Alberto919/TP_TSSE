#include <stdint.h>
#include <stdbool.h>

void Leds_Create(uint16_t * puerto);

void Leds_On(uint16_t led);

void Leds_Off(uint16_t led);

void Leds_On_All();

void Leds_Off_All();

bool Leds_IsOn(int16_t led);