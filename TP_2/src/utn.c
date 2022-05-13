/*
 * utn.c
 *
 *  Created on: 8 may. 2022
 *      Author: Bahia
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
static int myGets(char* cadena, int longitud);
static int getFloat(float*pResultado);
static int esFLoat(char*cadena);
static int esPalabra (char*cadena);
static int esNumerica(char*cadena);

static int getInt(int*pResultado);
static int esPalabra(char*cadena);
static int esPalabraoNumero(char*cadena);

int utn_getPalNum (char*pResultado, char*mensaje, char*mensajeError,int intentos,int len)
{
	int retorno = -1;
	char texto[300];
	if(mensaje !=  NULL && mensajeError != NULL && intentos > 0)
	{
		printf("%s",mensaje);
		gets(texto);
		while ((esPalabraoNumero(texto)==0 && intentos>0)||strlen(texto)>len)
		{
			printf("%s",mensajeError);
			gets(texto);
			intentos--;
		}
		if(esPalabraoNumero(texto))
		{
		strcpy (pResultado,texto);
		retorno = 0;

		}
	}return retorno;
}

int utn_getNumero (int *pResultado, char*mensaje, char*mensajeError, int minimo, int maximo, int reintentos)
{
	setbuf(stdout,NULL);
	int bufferGetNumero;
	int retorno = -1;
	if(mensaje!= NULL && mensajeError != NULL && minimo < maximo && reintentos > 0 )
	{
		printf("%s",mensaje);
		while((getInt(&bufferGetNumero)!=0 || bufferGetNumero > maximo || bufferGetNumero<minimo) && reintentos >0 )
		{
			printf("%s",mensajeError);
		}

		*pResultado=bufferGetNumero;
		retorno=0;
		return retorno;
	}
	return retorno;
}
int utn_getFloat (float* pResultado, char*mensaje, char*mensajeError, float minimo, float maximo, int reintentos)
{
	setbuf(stdout,NULL);
	float bufferGetFloat;
	int retorno = -1;
	if(mensaje!= NULL && mensajeError != NULL && minimo < maximo && reintentos > 0)
	{
		printf("%s",mensaje);
		while((getFloat(&bufferGetFloat)==-1 || bufferGetFloat > maximo || bufferGetFloat<minimo)&& reintentos >0)
		{
			printf("%s",mensajeError);
		}
		*pResultado=bufferGetFloat;
		retorno=0;
		return retorno;
	}
	return retorno;
}
int utn_getPalabra (char*pResultado, char*mensaje, char*mensajeError,int intentos,int len)
{
	int retorno = -1;
	char texto[51];
	if((mensaje !=  NULL && mensajeError != NULL && intentos > 0)||strlen(texto)>len)
	{
		printf("%s",mensaje);
		gets(texto);
		while (esPalabra(texto)==0 && intentos>0)
		{
			printf("%s",mensajeError);
			gets(texto);
			intentos--;
		}
		if(esPalabra(texto)==1)
		{
		strcpy (pResultado,texto);
		retorno = 0;

		}

	}return retorno;
}

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}
static int getInt(int*pResultado)
{
	char buffergetInt[4096];
	int retorno = -1;
	myGets(buffergetInt,sizeof(buffergetInt));
	if (esNumerica(buffergetInt)==1)
	{
		*pResultado= atoi(buffergetInt);
		retorno=0;
	}
	return retorno;
}


static int getFloat(float*pResultado)
{
	char buffergetFloat[4096];
	int retorno = -1;
	myGets(buffergetFloat,sizeof(buffergetFloat));
	if (esFLoat(buffergetFloat)==1)
	{
		retorno=0;
		*pResultado= atof(buffergetFloat);

	}
	return retorno;
}

static int esFLoat(char*cadena)
{
	int I=0;
	int retorno=1;
	int banderadePunto = 0;

	if (cadena[0]=='-')
	{
		I=1;
	}


	for( ;cadena[I]!='\0';I++)
	{
		if (cadena[I]>'9'||cadena[I] <'0')
		{
			if (cadena[I]=='.'&& banderadePunto ==0)
		{
			banderadePunto = 1;
		}
			else
			{
			retorno = 0;
			break;
			}

		}

	}
	return retorno;
}
static int esNumerica(char*cadena)
{
	int I=0;
	int retorno=1;

	if (cadena[0]=='-')
	{
		I=1;
	}
	for( ;cadena[I]!='\0';I++)
	{

		if (cadena[I]>'9'||cadena[I] <'0')
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}
static int esPalabra(char*cadena)
{
	int I=0 ;
	int retorno = 1;
	for (;cadena[I]!='\0';I++)
	{
		if ((cadena[I]< 64 || cadena [I]> 91 )&&(cadena[I]>123 || cadena[I]<96))
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}
static int esPalabraoNumero(char*cadena)
{
	int I=0 ;
	int retorno = 1;
	for (;cadena[I]!='\0';I++)
	{
		if ((cadena[I]< 64 || cadena [I]> 91 )&&(cadena[I]>123 || cadena[I]<96)&&(cadena[I]>'9'||cadena[I] <'0'))
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}
