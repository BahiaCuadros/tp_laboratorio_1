/*
 * operacionesdeltrabajopractico.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Bahia
 */
#include <stdio.h>
#include <stdlib.h>

int tp1_Menu(int min,int max, char* mensaje,char*mensajeDeError, int*respuesta)
{

	int retorno=-1;
	int opcion;
	if (min<max && mensaje != NULL && mensajeDeError!= NULL)
	{
		printf("%s",mensaje);
		scanf("%d",&opcion);
		while (opcion< min || opcion > max)
		{
			system ("cls");
			printf("%s",mensajeDeError);
			scanf("%d",&opcion);
		}
		*respuesta = opcion;
		retorno= 0;
	}
	return retorno;

}
int tp1_getFloat(char* mensaje, char* mensajeerror, float* retorno,float numeromin)
{

	int rtn;
	float numvar;
	rtn = -1;
	if(mensaje != NULL && mensajeerror!= NULL)
	{
		printf("%s",mensaje);
		scanf("%f",&numvar);
		while(numvar<numeromin)
		{
			system ("cls");
			printf("%s",mensajeerror);
			scanf("%f",&numvar);
		}
		rtn = 0;
		*retorno=numvar;
	}
	else
	{
		return rtn;
	}
	return rtn;

}
int tp1_getInt(char* mensaje, char* mensajeerror, int* retorno,int numeromin,int numeromax)
{

	int rtn;
	int numvar;
	rtn = -1;
	if(mensaje != NULL && mensajeerror!= NULL)
	{	printf("%s",mensaje);
		scanf("%d",&numvar);
		while(numvar<numeromin||numvar>numeromax)
		{
			system ("cls");
			printf("%s",mensajeerror);
			scanf("%d",&numvar);
		}
		rtn = 0;
		*retorno=numvar;
	}
	else
	{
		printf("sos resalame");
		return rtn;
	}
	return rtn;

}

