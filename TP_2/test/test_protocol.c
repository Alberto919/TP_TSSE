#include "unity.h"
#include "protocol.h"
#include "FSMprotocol.h"

/*
    • Se puede prender la iluminacion del invernadero.
    • Se puede iniciar el riego por goteo en el invernadero.
    • Se puede chequear si el comando enviado es incorrecto.
    • Se puede consultar el valor de la temperatura.
    • Se puede consultar el valor de la humedad.
    • Se puede apagar la iluminacion del invernadero.
    • Se puede detener el riego por goteo en el invernadero.
*/

static int resultado;
static int status;

void setUp(void)
{
    create(&resultado, &status);
}

void tearDown(void)
{
}

//  Se puede prender la iluminacion del invernadero
void test_protocol_iluminacionON(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,ILUMINACION_ON, END_CMD};
    //enviamos el comando
	sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_ON, resultado);
}

//  Se puede iniciar el riego por goteo en el invernadero
void test_protocol_riegoON(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,RIEGO_ON, END_CMD};
    //enviamos el comando
	sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_ON, resultado);
}

//  Se puede chequear si el comando enviado es incorrecto
//  los comandos siguen el formato
//  START_CMD       -> Inicio del comando
//  INSTRUCCION     -> Instruccion a ejectar
//  START_CMD       -> Fin del comando
//  El mismo es validado antes de ejecutar la instruccion
void test_protocol_Command(void){
    //comando a validar
    int buf[BUFFER_LENGHT] = {START_CMD,RIEGO_ON, START_CMD};
    //enviamos el comando
	sendCommand(buf);   
    TEST_ASSERT_EQUAL(FAIL, status);
}

//  Se puede consultar el valor de la temperatura 
//  del invernadero, la misma se a fijado a un valor ficticio
//  para poder realizar el testing
void test_protocol_getTemperatura(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,GET_TEMP, END_CMD};
    //enviamos el comando
	sendCommand(buf);   
    TEST_ASSERT_EQUAL(TEST_TEMP, resultado);
}

//  Se puede consultar el valor de la humedad 
//  del invernadero, la misma se a fijado a un valor ficticio
//  para poder realizar el testing
void test_protocol_getHumedad(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,GET_HUM, END_CMD};
    //enviamos el comando
	sendCommand(buf);   
    TEST_ASSERT_EQUAL(TEST_HUM, resultado);
}


//  Se puede apagar la iluminacion del invernadero
void test_protocol_iluminacionOFF(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,ILUMINACION_OFF, END_CMD};
    //enviamos el comando
	sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_OFF, resultado);
}

//  Se puede detener el riego por goteo en el invernadero
void test_protocol_riegoOFF(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,RIEGO_OFF, END_CMD};
    //enviamos el comando
	sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_OFF, resultado);
}
