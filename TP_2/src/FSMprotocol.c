/*
 * FSMprotocol.cpp
 *
 *  Created on: 4 dic. 2019
 *      Author: Alberto
 */

#include "FSMprotocol.h"

enum State
{
	WAIT,
	DATA,
	END
} state;

unsigned char cmd_byte;
unsigned char opr_byte;
void (*funcionProcesar)(int);
void (*funcionRespuesta)(int);


void receive(int input);
bool exec_cmd(int cmd);
void sendFail();
void sendOK();
void send(int input);

void init()
{
	state = WAIT;	
}

void sendCommand(int *buf)
{
	int written = 0;
	while (written < BUFFER_LENGHT)
	{
		receive(buf[written]);
		written++;
	}
}

void procesar_callback(void (*funcionEjecutar)(int))
{
	funcionProcesar = funcionEjecutar;
}

void responder_callback(void (*funcionReturn)(int))
{
	funcionRespuesta = funcionReturn;
}

void receive(int input)
{
	switch (state)
	{
	case WAIT:
		if (input == START_CMD)
		{
			cmd_byte = input; // store valid command
			state = DATA;
		}
		break;
	case DATA:
		if (input > -1)
		{
			opr_byte = input; // store valid command
			state = END;
		}
		else
		{
			state = WAIT;
			sendFail();
		}
		break;
	case END:
		if (input == END_CMD)
		{
			if (exec_cmd(opr_byte))
			{
				sendOK();
			}
			else
			{
				sendFail();
			}
			state = WAIT;
		}
		else
		{
			state = WAIT;
			sendFail();
		}
		break;
	}
}

bool exec_cmd(int cmd)
{
	bool check = true;
	switch (cmd)
	{
	case READY:
		funcionProcesar(cmd);
		break;
	case ILUMINACION_OFF:
		funcionProcesar(cmd);
		break;
	case ILUMINACION_ON:
		funcionProcesar(cmd);
		break;
	case RIEGO_OFF:
		funcionProcesar(cmd);
		break;
	case RIEGO_ON:
		funcionProcesar(cmd);
		break;
	case GET_TEMP:
		funcionProcesar(cmd);
		break;
	case GET_HUM:
		funcionProcesar(cmd);
		break;
	default:
		check = false;
		break;
	}
	return check;
}

void sendFail()
{
	send(FAIL);
}

void sendOK()
{
	send(OK);
}

void send(int input)
{
	funcionRespuesta(input);
}
