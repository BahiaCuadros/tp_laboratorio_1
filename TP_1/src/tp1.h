/*
 * operacionesdeltrabajopractico.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Bahia
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef TP1_H_
#define TP1_H_
int tp1_getFloat(char* mensaje, char* mensajeerror, float* retorno,float numeromin);
int tp1_getInt(char* mensaje, char* mensajeerror, int* retorno,int numeromin,int numeromax);
int tp1_Menu(int min,int max, char* mensaje,char* mensajeDeError, int* respuesta);
#endif /* TP1_H_ */
