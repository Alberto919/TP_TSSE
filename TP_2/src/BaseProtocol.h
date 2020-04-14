/*
 * BaseProtocol.h
 *
 *  Created on: 4 dic. 2019
 *      Author: Alberto
 */

#ifndef BASEPROTOCOL_H_
#define BASEPROTOCOL_H_

#define START_CMD       0xF0
#define END_CMD 		0xFF

/* Result codes */
enum Result {
	FAIL 				= 0xF7,
	OK   				= 0xF8,
	READY 				= 0x00,
	ILUMINACION_OFF 	= 0x01,
	ILUMINACION_ON 		= 0x02,
	RIEGO_OFF 			= 0x03,
	RIEGO_ON 			= 0x04,
	GET_TEMP 			= 0x05,
	GET_HUM 			= 0x06,	
};
#endif /* BASEPROTOCOL_H_ */

