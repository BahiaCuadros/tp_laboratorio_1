/*
 * utn.h
 *
 *  Created on: 8 may. 2022
 *      Author: Bahia
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
int utn_getNumero (int*pResultado, char*mensaje, char*mensajeError, int minimo, int maximo, int reintentos);
int utn_getPalabra (char*pResultado, char*mensaje, char*mensajeError,int intentos,int len);
int utn_getPalNum (char*pResultado, char*mensaje, char*mensajeError,int intentos,int len);
int utn_getFloat (float* pResultado, char*mensaje, char*mensajeError, float minimo, float maximo, int reintentos);
#endif /* UTN_H_ */
