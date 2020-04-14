#include "leds.h"
#include <stdint.h>

static uint16_t * leds;

uint16_t Leds_Bits(uint16_t led){
    return (1 << (led - 1)); 
}    

void Leds_Create(uint16_t * puerto){
    leds = puerto;
    *puerto = 0;
}

void Leds_On(uint16_t led){
    *leds |= Leds_Bits(led);
}

void Leds_Off(uint16_t led){
    *leds &= ~Leds_Bits(led);
}

void Leds_On_All(){
    *leds = 0xFFFF;
}

void Leds_Off_All(){
    *leds = 0x0000;
}

void Leds_IsOn(int16_t led) {
    *leds &= Leds_Bits(led);
}