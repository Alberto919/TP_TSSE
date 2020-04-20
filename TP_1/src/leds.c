#include "leds.h"
#include <stdint.h>

#define ALL_OFF 0x0000  //Todos los led apagados
#define ALL_ON  0xFFFF  //Todos los led encendidos
#define LED_OFFSET 1    //Constante de desplazamiento
#define BIT_ON    1  

static uint16_t * leds;

uint16_t Leds_Bits(uint16_t led){
    return (BIT_ON << (led - LED_OFFSET)); 
}    

void Leds_Create(uint16_t * puerto){
    leds = puerto;
    *puerto = ALL_OFF;
}

void Leds_On(uint16_t led){
    *leds |= Leds_Bits(led);
}

void Leds_Off(uint16_t led){
    *leds &= ~Leds_Bits(led);
}

void Leds_On_All(){
    *leds = ALL_ON;
}

void Leds_Off_All(){
    *leds = ALL_OFF;
}

bool Leds_IsOn(int16_t led) {
    return *leds & Leds_Bits(led);
}