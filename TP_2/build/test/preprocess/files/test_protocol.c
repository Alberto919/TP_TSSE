#include "build/temp/_test_protocol.c"
#include "src/FSMprotocol.h"
#include "src/protocol.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
static int resultado;

static int status;



void setUp(void)

{

    create(&resultado, &status);

}



void tearDown(void)

{

}





void test_protocol_iluminacionON(void){

    int buf[3] = {0xF0,ILUMINACION_ON, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ON)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}





void test_protocol_riegoON(void){

    int buf[3] = {0xF0,RIEGO_ON, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ON)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}















void test_protocol_Command(void){

    int buf[3] = {0xF0,RIEGO_ON, 0xF0};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((FAIL)), (UNITY_INT)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}









void test_protocol_getTemperatura(void){

    int buf[3] = {0xF0,GET_TEMP, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_TEMP)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}









void test_protocol_getHumedad(void){

    int buf[3] = {0xF0,GET_HUM, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_HUM)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}







void test_protocol_iluminacionOFF(void){

    int buf[3] = {0xF0,ILUMINACION_OFF, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_OFF)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

}





void test_protocol_riegoOFF(void){

    int buf[3] = {0xF0,RIEGO_OFF, 0xFF};

 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_OFF)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}
