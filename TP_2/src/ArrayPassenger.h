/**
 * tp2.h
 *
 *  Created on: 10 may. 2022
 *      Author: Bahia
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>


struct sPasajero
	{
		int id;
		char nombre [51];
		char apellido[51];
		float price;
		char flycode[10];
		int typePassenger;
		int statusFlight;
		int isEmpty;
	};

struct sVuelo
		{
		char codigoDeVuelo[10];
		int banderadeVueloActivo;
		int isEmpty;
		};

int CargaPasajero(struct sPasajero *pCarga,int contadorDePasajeros,struct sVuelo *auxiliarVuelo);
int sddPassengers(struct sPasajero *arraypasajero,int len,int id,char name[],char lasName[],float price,int typePassenger,char flycode[]);
int initPassengers(struct sPasajero* pCargados, int Len);
int findPassengerById(struct sPasajero *auxiliarDeBusqueda,int len, int id);
int removedPassenger(struct sPasajero *auxiliarDeBusqueda,int len, int id);
int impresionPasajero(struct sPasajero *arrayPasajeros);
int modificarPasajero(struct sPasajero *pCarga,char* mensaje,char mensajeError);
int initVueloss(struct sVuelo *pCargados, int Len);
void ordenarArraypalabras(struct sPasajero *auxiliarOrdenamiento,int len, int orden);
int sortPassengers(struct sPasajero *AuxiliarPasajero,int len,int order);
void OrdenadorCodigo(struct sPasajero *auxiliarOrdenamiento, int len,int orden);
int sortPassengerByCode(struct sPasajero *AuxiliarPasajeros,int len, int order);
void SepararVueloactivo(struct sPasajero *Auxiliarpasajero, struct sVuelo *AuxiliarVuelo,int len,int orden);
void PromedioPasajes(struct sPasajero *auxiliarpromedio,int len);

#endif /* ARRAYPASSENGER_H_ */
