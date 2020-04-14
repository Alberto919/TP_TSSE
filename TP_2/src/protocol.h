#include "FSMprotocol.h"

#ifndef PROTOCOL_H
#define PROTOCOL_H

/* Resultados ficticios para poder hacer el test */
enum Test {	
	TEST_ON 			= 1,
	TEST_OFF 			= 0,
	TEST_TEMP 			= 25,
	TEST_HUM 			= 30,	
} valores;

void create(int * paramP, int * paramS);
void Iluminacion_ON(int *cmd);
void Iluminacion_OFF(int *cmd);
void Riego_ON(int *cmd);
void Riego_OFF(int *cmd);
void Temperatura(int *cmd);
void Humedad(int *cmd);
#endif // PROTOCOL_H
