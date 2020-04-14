#include "build/temp/_test_led.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
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

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}





void test_IndividualLedOn(void)

{

    const uint16_t led = 3;

    Leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)((1 << (led-1))), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}





void test_IndividualLedOff(void)

{

    const uint16_t led = 3;

    Leds_On(led);

    Leds_Off(led);

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}





void test_MultipleLedOnAndOff(){

    Leds_On(2);

    Leds_On(5);

    Leds_Off(2);

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedOn(){

    Leds_On_All();

    UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedOff(){

    Leds_Off_All();

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}





void test_IsLedOn(){

    const uint16_t led = 3;

    Leds_On(led);

    if ((ledsVirtuales)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));};

}





void test_IsLedOff(){

    const uint16_t led = 3;

    Leds_Off(led);

    if ((ledsVirtuales)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(82)));};

}
