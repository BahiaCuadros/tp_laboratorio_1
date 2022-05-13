/*
 * tp2.c
 *
 *  Created on: 10 may. 2022
 *      Author: Bahia
 */

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int CargaPasajero(struct sPasajero *pCarga,int contadorDePasajeros,struct sVuelo *auxiliarVuelo)
{
	int retorno = -1;
	int I;
	int respuesta;
	struct sPasajero auxiliarCarga;
	int banderadeVuelocargado=0;
	 utn_getPalabra(&auxiliarCarga.nombre,"\n ingrese el nombre del pasajero por favor: ","\n ingrese el nombre usando solo letras por favor",5,sizeof(auxiliarCarga.nombre));
	 utn_getPalabra(&auxiliarCarga.apellido,"\n ingrese el apellido del pasajero por favor: ","\n ingrese el apellido usando solo letras por favor",5,sizeof(auxiliarCarga.apellido));
	 utn_getNumero(&auxiliarCarga.typePassenger,"\n ¿Que vuelo desea?\n 1:turista\n 2:ejecutivo \n 3: Primera clase","\n ingrese opcion del 1 al 3 por favor",0,3,5);
	 utn_getFloat(&auxiliarCarga.price,"\n Indique el valor del vuelo:$","\n indique el valor del vuelo usando solo numeros por favor: $",0,1000000,5);
	 utn_getPalNum(&auxiliarCarga.flycode,"\n indique el codigo de vuelo por favor:","\n El codigo solo puede contener 10 letras y numeros",5,sizeof(auxiliarCarga.flycode));
	 for (I=0;I<=2000;I++)
	 {
		if(strcmp( auxiliarVuelo[I].codigoDeVuelo,auxiliarCarga.flycode)==0)
		{
			if(auxiliarVuelo[I].banderadeVueloActivo==1)
			{
				utn_getNumero(&respuesta,"\n El estado del vuelo que cargo, esta ACTIVO, ¿Desea modificarlo?\nPor favor ingrese \n 1: en caso de si o \n 0: en caso de no","\n Por favor ingrese \n 1: en caso de si o \n 2: en caso de no:",0,1,5);
				banderadeVuelocargado=1;
				if (respuesta==1)
				{
					utn_getNumero(&auxiliarVuelo[I].banderadeVueloActivo,"\n 1: Si desea indicar que el vuelo esta ACTIVO \n 0: si desea indicar que el vuelo esta INACTIVO ", "\n Por favor ingrese solo un numero \n \n 1:si desea indicar que el vuelo esta ACTIVO \n 0: si desea indicar que el vuelo esta INACTIVO",0,1,5);

				}
			}
			if(auxiliarVuelo[I].banderadeVueloActivo==0 && banderadeVuelocargado==0)
			{
			utn_getNumero(&respuesta,"\n El estado del vuelo que cargo, esta INACTIVO, ¿Desea modificarlo?\nPor favor ingrese \n 1: en caso de si o \n 0: en caso de no","\n Por favor ingrese \n 1: en caso de si: \n 2: en caso de no:",0,1,5);
			banderadeVuelocargado=1;
			if (respuesta==1)
				{
					utn_getNumero(&auxiliarVuelo[I].banderadeVueloActivo,"\n 1: Si desea indicar que el vuelo esta ACTIVO \n 0: si desea indicar que el vuelo esta INACTIVO ", "\nPor favor ingrese solo un numero \n \n 1:si desea indicar que el vuelo esta ACTIVO \n 0: si desea indicar que el vuelo esta INACTIVO",0,1,5);
				}
			}
			break;
		}

	 }
	 if(banderadeVuelocargado==0)
	 {
		 	 for(I=0;I<=2000;I++)
	 {
		 if(auxiliarVuelo[I].isEmpty!=0)
		 {
			 strcpy(auxiliarVuelo[I].codigoDeVuelo,auxiliarCarga.flycode);
			 utn_getNumero(&auxiliarVuelo->banderadeVueloActivo,"\n El vuelo que ingreso no se encuentra guardado en la base de datos, por favor indique su estado:\n 1: Si desea indicar que el vuelo esta ACTIVO \n 0: si desea indicar que el vuelo esta INACTIVO ", "\n Por favor ingrese solo un numero \n \n 1: Si desea indicar que el vuelo esta ACTIVO \n 0: Si desea indicar que el vuelo esta INACTIVO",0,1,5);
			 auxiliarVuelo[I].isEmpty==0;
			 banderadeVuelocargado=1;
			 I=2001;
		 }

	 }
	 }

	 if(banderadeVuelocargado=0)
	 {	 	 printf("no hay mas espacio para almacenar vuelos");
	 }

	*pCarga=auxiliarCarga;
	 retorno=1;
	 return retorno;
}
int initVueloss(struct sVuelo *pCargados, int Len)
{
	int retorno = -1;
	int I;
	for (I=0;I<=Len;I=I+1)
	{
		pCargados[I].isEmpty =1;
	}
	return 0 ;
}

int initPassengers(struct sPasajero *pCargados, int Len)
{
	int retorno = -1;
	int I;
	for (I=0;I<=Len;I=I+1)
	{
		pCargados[I].isEmpty=1;
	}
	return 0 ;
}
int sddPassengers(struct sPasajero *arraypasajero,int len,int id,char name[],char lasName[],float price,int typePassenger,char flycode[])
{
	int retorno=-1;
	int I;
	for( I= 0; I <=len;I++)
	{
		if(arraypasajero[I].isEmpty==1)
				{
			arraypasajero[I].isEmpty=0;
			arraypasajero[I].id =1000+I;
			arraypasajero[I].price= price;
			arraypasajero[I].typePassenger= typePassenger;
			strcpy(arraypasajero[I].apellido,lasName);
			strcpy(arraypasajero[I].nombre,name);
			strcpy(arraypasajero[I].flycode,flycode);
			retorno=0;
			break;
				}
	}
	return retorno;
}
int findPassengerById(struct sPasajero *auxiliarDeBusqueda,int len, int id)
{
	int retorno=-1;
	int I;
	for (I=0;I<=len;I++)
	{
		if (auxiliarDeBusqueda[I].id==id)
		{
			retorno = I;
			break;
		}
	}
	return retorno;
}
int removedPassenger(struct sPasajero *auxiliarDeBusqueda,int len, int id)
{
	int retorno=-1;
	int I;
	int confirmacion;
	for (I=0;I<=len;I++)
	{
		if (auxiliarDeBusqueda[I].id==id)
		{
			impresionPasajero(&auxiliarDeBusqueda[I]);
			utn_getNumero(&confirmacion,"Desea eliminar a este pasajero\n 1:Si \n 2:No","indique uno o dos",0,3,5);
			if(confirmacion==1)
			{
			char Auxiliarcadena[100]="";
			auxiliarDeBusqueda[I].isEmpty=1;
			auxiliarDeBusqueda[I].id =0;
			auxiliarDeBusqueda[I].price= 0;
			auxiliarDeBusqueda[I].typePassenger= 0;
			strcpy(auxiliarDeBusqueda[I].apellido,Auxiliarcadena);
			strcpy(auxiliarDeBusqueda[I].nombre,Auxiliarcadena);
			strcpy(auxiliarDeBusqueda[I].flycode,Auxiliarcadena);
			retorno = 0;
			}

			break;
		}
	}
	return retorno;
}
int printPasenget(struct sPasajero *auxiliarDeImpresion,int legth)
{
	int I=0;
	for(I=0;I<legth;I++)
	{
		if(auxiliarDeImpresion[I].isEmpty==0)
		{
			switch (auxiliarDeImpresion[I].typePassenger)
			{
			case 1:
				printf("\n%d \t %s \t %s \t Clase Turista \t %s \t %.2f \n\n",auxiliarDeImpresion[I].id,auxiliarDeImpresion[I].nombre,auxiliarDeImpresion[I].apellido,auxiliarDeImpresion[I].flycode,auxiliarDeImpresion[I].price);
			break;
			case 2:
				printf("\n%d \t %s \t %s \t Clase Ejecutiva \t %s \t %.2f \n\n",auxiliarDeImpresion[I].id,auxiliarDeImpresion[I].nombre,auxiliarDeImpresion[I].apellido,auxiliarDeImpresion[I].flycode,auxiliarDeImpresion[I].price);
			break;
			case 3:
				printf("\n%d \t %s \t %s \t Primera Clase \t %s \t %.2f \n\n",auxiliarDeImpresion[I].id,auxiliarDeImpresion[I].nombre,auxiliarDeImpresion[I].apellido,auxiliarDeImpresion[I].flycode,auxiliarDeImpresion[I].price);
			break;
			}
		}

	}
	return 0;

}
int impresionPasajero(struct sPasajero *arrayPasajeros)
{
printf("\n Nombre:%s ",arrayPasajeros->nombre);
printf("\n Apellido:%s ",arrayPasajeros->apellido);
printf("\n Codigo de vuelo:%s ",arrayPasajeros->flycode);
printf("\n Clase:%d ",arrayPasajeros->typePassenger);
printf("\n precio:%f ",arrayPasajeros->price);
printf("\n bandera:%d ",arrayPasajeros->isEmpty);
return 0;
}
int modificarPasajero(struct sPasajero *pCarga,char* mensaje,char mensajeError)
{
	int modificador;
	utn_getNumero(&modificador,mensaje,mensajeError,0,5,5);
	struct sPasajero auxiliarCarga;

	switch (modificador)
	{
	case 1:
	utn_getPalabra(&auxiliarCarga.nombre,"\n ingrese el nuevo nombre del pasajero por favor: \n","\n ingrese el nuevo nombre usando solo letras por favor\n",5,sizeof(auxiliarCarga.nombre));
	strcpy(pCarga->nombre,auxiliarCarga.nombre);
	break;
	case 2:
	 utn_getPalabra(&auxiliarCarga.apellido,"\n ingrese el nuevo apellido del pasajero por favor: \n","\n ingrese el nuevo apellido usando solo letras por favor\n",5,sizeof(auxiliarCarga.apellido));
	 strcpy(pCarga->apellido,auxiliarCarga.apellido);
	 break;
	 case 4:
	 utn_getNumero(&auxiliarCarga.typePassenger,"¿Que vuelo desea?\n 1:turista\n 2:ejecutivo \n 3: Primera clase","ingrese opcion del 1 al 3 por favor",0,4,5);
	 pCarga->typePassenger= auxiliarCarga.typePassenger;
	 break;
	 case 5:
	 utn_getFloat(&auxiliarCarga.price,"\n Indique el nuevo valor del vuelo:\n $","\n indique el nuevo valor del vuelo usando solo numeros por favor:\n $",0,1000000,5);
	 pCarga->price= auxiliarCarga.price;
	 break;
	 case 3:
	 utn_getPalNum(&auxiliarCarga.flycode,"\n indique el nuevo codigo de vuelo por favor:\n","El codigo solo puede contener 10 letras y numeros",5,sizeof(auxiliarCarga.flycode));
	 strcpy(pCarga->flycode,auxiliarCarga.flycode);
	 break;
	}
	 return 0;
}
void ordenarArraypalabras(struct sPasajero *auxiliarOrdenamiento,int len,int orden)
{
	struct sPasajero Auxiliarapellido;
	int I;
	int Iactual;
	if (orden==1)
	{
		for(I=0;I<len;I++)
			{
				for (Iactual=0;Iactual<len-1;Iactual++)
				{
					int iSiguiente = Iactual +1;
					if (strcmp(auxiliarOrdenamiento[Iactual].apellido,auxiliarOrdenamiento[iSiguiente].apellido)>0)
					{
						Auxiliarapellido = auxiliarOrdenamiento[Iactual];
						auxiliarOrdenamiento[Iactual]=auxiliarOrdenamiento[iSiguiente];
						auxiliarOrdenamiento[iSiguiente]=Auxiliarapellido;
					}
				}
			}
	}
	if (orden ==0)
	{
			for(I=0;I<len;I++)
	{
		for (Iactual=0;Iactual<len-1;Iactual++)
		{
			int iSiguiente = Iactual +1;
			if (strcmp(auxiliarOrdenamiento[Iactual].apellido,auxiliarOrdenamiento[iSiguiente].apellido)<0)
			{
				Auxiliarapellido = auxiliarOrdenamiento[Iactual];
				auxiliarOrdenamiento[Iactual]=auxiliarOrdenamiento[iSiguiente];
				auxiliarOrdenamiento[iSiguiente]=Auxiliarapellido;
			}
		}
	}

	}

}
int sortPassengers(struct sPasajero *AuxiliarPasajero,int len,int order)
{
	int I;
	int retorno=-1;
	struct sPasajero arrayPrimeraclase[len];
	struct sPasajero arrayclaseTurista[len];
	struct sPasajero arrayclaseEjecutivo[len];
	int contador=0;
	int contador1=0;
	int contador2=0;
	int contador3=0;
	for(I=0;I<=len;I++)
	{
		if(AuxiliarPasajero->isEmpty==0)
		{

		switch (AuxiliarPasajero[I].typePassenger)
		{

		case 1:

			arrayclaseTurista[contador1]=AuxiliarPasajero[I];
			contador1++;
			contador ++;
			break;
		case 2:
			arrayclaseEjecutivo[contador2]=AuxiliarPasajero[I];
			contador ++;
			contador2++;
			break;
		case 3:
			arrayPrimeraclase[contador3]=AuxiliarPasajero[I];

			contador ++;
			contador3++;
			break;
		}
		}
	}
	printf("\n\nCLASE TURISTA \n\n");
	if(contador1>0)
	{

		ordenarArraypalabras(arrayclaseTurista,contador1,order);
		printPasenget(arrayclaseTurista,contador1);
	}
	else
	{
		printf("No hay pasajeros en clase turista.");
	}
	printf("\n\nCLASE EJECUTIVA\n\n");
	if(contador2>0)
	{

			ordenarArraypalabras(arrayclaseEjecutivo,contador2,order);
			printPasenget(arrayclaseEjecutivo,contador2);
	}
	else
	{
		printf("No hay pasajeros en clase ejecutiva.");
	}
	printf("\n\nPRIMERA CLASE\n\n");
	if (contador3>0)
	{

		ordenarArraypalabras(arrayPrimeraclase,contador3,order);
	printPasenget(arrayPrimeraclase,contador3);
	}
	else
	{
		printf("No hay pasajeros en primera clase.");
	}
	return retorno;
}
void SepararVueloactivo(struct sPasajero *Auxiliarpasajero, struct sVuelo *AuxiliarVuelo,int len,int orden)
{
	struct sPasajero Vueloactivo[len];
	struct sPasajero vueloinactivo[len];
	int contador1=0;
	int contador2=0;
	int I;
	int X;
	for(I=0;I<len;I++)
	{
		for (X=0;X<len;X++)
		{
			if(((strcmp(Auxiliarpasajero[I].flycode,AuxiliarVuelo[X].codigoDeVuelo))==0)&& Auxiliarpasajero[I].isEmpty==0)
			{
				if(AuxiliarVuelo[X].banderadeVueloActivo==1)
				{
					Vueloactivo[contador1]=Auxiliarpasajero[I];
					contador1++;
				}
				else
				{
					vueloinactivo[contador2]=Auxiliarpasajero[I];
					contador2++;
				}
			}
		}

	}
	printf("\nVUELOS ACTIVOS");
	OrdenadorCodigo(Vueloactivo,contador1,orden);
	printPasenget(Vueloactivo,contador1);
	printf("\nVUELOS INACTIVOS");
	OrdenadorCodigo(vueloinactivo,contador2,orden);
	printPasenget(vueloinactivo,contador2);

}
int sortPassengerByCode(struct sPasajero *AuxiliarPasajeros,int len, int order)
{
	int retorno=-1;
	int contador;
	struct sPasajero AuxiliarOrdencodigo[len];
	for (int I=0;I<len;I++)
	{

		if(AuxiliarPasajeros[I].isEmpty==0)
		{

		AuxiliarOrdencodigo[I]=AuxiliarPasajeros[I];
		contador++;
		}

	}

	OrdenadorCodigo(AuxiliarOrdencodigo,contador,order);
	printPasenget(AuxiliarOrdencodigo,contador);
	retorno=0;
	return retorno;
}
void OrdenadorCodigo(struct sPasajero *auxiliarOrdenamiento, int len,int orden)
{
	struct sPasajero AuxiliarCodigo;
	int I;
	int Iactual;
	if (orden==1)
	{
		for(I=0;I<len;I++)
			{
				for (Iactual=0;Iactual<len-1;Iactual++)
				{
					int iSiguiente = Iactual +1;
					if (strcmp(auxiliarOrdenamiento[Iactual].flycode,auxiliarOrdenamiento[iSiguiente].flycode)>0)
					{
						AuxiliarCodigo = auxiliarOrdenamiento[Iactual];
						auxiliarOrdenamiento[Iactual]=auxiliarOrdenamiento[iSiguiente];
						auxiliarOrdenamiento[iSiguiente]=AuxiliarCodigo;
					}
				}
			}
	}
	if (orden ==0)
	{
			for(I=0;I<len;I++)
	{
		for (Iactual=0;Iactual>len-1;Iactual++)
		{
			int iSiguiente = Iactual +1;
			if (strcmp(auxiliarOrdenamiento[Iactual].flycode,auxiliarOrdenamiento[iSiguiente].flycode)<0)
			{
				AuxiliarCodigo = auxiliarOrdenamiento[Iactual];
				auxiliarOrdenamiento[Iactual]=auxiliarOrdenamiento[iSiguiente];
				auxiliarOrdenamiento[iSiguiente]=AuxiliarCodigo;
			}
		}
	}

	}

}

void PromedioPasajes(struct sPasajero *auxiliarpromedio,int len)
{
	float sumadeValores=0;
	int cantidadValores=0;
	struct sPasajero AuxiliarPromedio[len];
	float Promedio=0;
	int contador=0;
	for (int I=0;I<len;I++)
	{
		if(auxiliarpromedio[I].isEmpty==0)
		{
			sumadeValores=sumadeValores+ auxiliarpromedio[I].price;
			cantidadValores++;
		}
	}
	Promedio=sumadeValores/cantidadValores;
	printf("El precio promedio de los pasajes es de :$ %.2f",Promedio);
	for (int X=0;X<len;X++)
	{
		if(auxiliarpromedio[X].isEmpty==0)
		{
				if (auxiliarpromedio[X].price>Promedio)
				{

					AuxiliarPromedio[contador]=auxiliarpromedio[X];
					contador ++;
				}
		}
}
	printf("\n\n Los pasajeros que superan el precio de vuelo promedio son:\n");
	printPasenget(AuxiliarPromedio,contador);
}
