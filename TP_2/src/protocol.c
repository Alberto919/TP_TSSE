#include "protocol.h"


static int * _status;
static int * _proceso;
void procesar(int cmd);
void status(int cmd);


void procesar(int cmd){
	switch (cmd)
	{
	case ILUMINACION_OFF:
		*_proceso = TEST_OFF;
		break;
	case ILUMINACION_ON:
		*_proceso = TEST_ON;
		break;
	case RIEGO_OFF:
		*_proceso = TEST_OFF;
		break;
	case RIEGO_ON:
		*_proceso = TEST_ON;
		break;
	case GET_TEMP:
		*_proceso = TEST_TEMP;
		break;
	case GET_HUM:
		*_proceso = TEST_HUM;
		break;
	}
}

void status(int cmd){
    *_status = cmd;
}

void create(int * paramP, int * paramS){  
    _proceso = paramP;
    _status = paramS;
    init();
    procesar_callback(&procesar);
    responder_callback(&status);  
}

//Enciande la iluminacion del invernadero
void Iluminacion_ON(int *cmd){
    sendCommand(cmd); 
}

//Apaga la iluminacion del invernadero
void Iluminacion_OFF(int *cmd){
    sendCommand(cmd); 
}

//Inicia el Riego por goteo
void Riego_ON(int *cmd){
    sendCommand(cmd); 
}

//Detiene el Riego por goteo
void Riego_OFF(int *cmd){
    sendCommand(cmd); 
}

//Obtener temperatura
void Temperatura(int *cmd){
    sendCommand(cmd); 
}

//Detiene el Riego por goteo
void Humedad(int *cmd){
    sendCommand(cmd); 
}

