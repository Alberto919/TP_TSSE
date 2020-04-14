/*
 * FSMprotocol.h
 *
 *  Created on: 4 dic. 2019
 *      Author: Alberto
 */

#ifndef FSMPROTOCOL_H_
#define FSMPROTOCOL_H_

#include "BaseProtocol.h"
#include <stdbool.h>
#include <stdio.h>

#define BUFFER_LENGHT 3

void init();
void sendCommand(int *buf);
void procesar_callback(void (*funcionEjecutar)(int));
void responder_callback(void (*funcionReturn)(int));

#endif /* FSMPROTOCOL_H_ */