#include "unity.h"
#include "leds.h"
#include <stdint.h>

/*
    • Se puede prender un LED individual.
    • Se puede apagar un LED individual.
    • Se pueden prender y apagar múltiples LED’s.
    • Se pueden prender todos los LEDs de una vez.
    • Se pueden apagar todos los LEDs de una vez.
    • Se puede consultar el estado de un LED.
    • Revisar limites de los parametros.
    • Revisar parámetros fuera de los limites.
*/

static uint16_t ledsVirtuales = 0xFFFF;

void setUp(void)
{    
    Leds_Create(&ledsVirtuales);
}

void tearDown(void)
{
}

void test_ledsOffAfterCreate(void)
{    
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL(0x0, ledsVirtuales);
}

//  Se puede prender un LED individual
void test_IndividualLedOn(void)
{
    const uint16_t led = 3;
    Leds_On(led);
    TEST_ASSERT_EQUAL(1 << (led-1), ledsVirtuales);
}

//  Se puede apagar un LED individual
void test_IndividualLedOff(void)
{
    const uint16_t  led = 3;
    Leds_On(led);
    Leds_Off(led);
    TEST_ASSERT_EQUAL(0x0, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s
void test_MultipleLedOnAndOff(){
    Leds_On(2);
    Leds_On(5);
    Leds_Off(2);
    TEST_ASSERT_EQUAL(0x0 , ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez
void test_AllLedOn(){
    Leds_On_All();
    TEST_ASSERT_EQUAL(0xFFFF , ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez
void test_AllLedOff(){
    Leds_Off_All();
    TEST_ASSERT_EQUAL(0x0, ledsVirtuales);
}

// Se puede consultar el estado de un LED.
void test_IsLedOn(){
    const uint16_t  led = 3;
    Leds_On(led);
    TEST_ASSERT_TRUE(ledsVirtuales);
}

// Se puede consultar el estado de un LED.
void test_IsLedOff(){
    const uint16_t  led = 3;
    Leds_Off(led);
    TEST_ASSERT_TRUE(!ledsVirtuales);
}