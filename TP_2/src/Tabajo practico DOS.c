/*
 ============================================================================
 Name        : Tabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define ELEMENTS 2000
int main(void) {
setbuf(stdout,NULL);
 struct sPasajero arrayPasajeros[ELEMENTS];
 struct sPasajero auxiliarCargas;
 struct sVuelo arrayVuelos[ELEMENTS];
 int opcionMenu;
 int opcionMenu4;
 int Banderaprimerpasajero=0;
 int contadorDePasajeros=0;
 int auxiliarId;
 int posicionModificador;
 int AuxiliarModificador;
 initPassengers(arrayPasajeros, ELEMENTS);
 initVueloss(arrayVuelos, ELEMENTS);
	 sddPassengers(arrayPasajeros,ELEMENTS,1000,"Milagros","Cardenas",500,1,"g123");
	 strcpy(arrayVuelos[0].codigoDeVuelo,"g123");
	 arrayVuelos[0].banderadeVueloActivo=0;
	 arrayVuelos[0].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1001,"Camilo","Cardenas",600,1,"t123");
	 strcpy(arrayVuelos[1].codigoDeVuelo,"t123");
	 arrayVuelos[1].banderadeVueloActivo=1;
	 arrayVuelos[1].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1002,"Lucia","Recalde",700,3,"y123");
	 strcpy(arrayVuelos[2].codigoDeVuelo,"y123");
	 arrayVuelos[2].banderadeVueloActivo=1;
	 arrayVuelos[2].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1003,"Natalia","velasquez",650,2,"p123");
	 strcpy(arrayVuelos[3].codigoDeVuelo,"p123");
	 arrayVuelos[3].banderadeVueloActivo=1;
	 arrayVuelos[3].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1004,"Federico","Gonzalez",700,2,"k123");
	 strcpy(arrayVuelos[4].codigoDeVuelo,"k123");
	 arrayVuelos[4].banderadeVueloActivo=0;
	 arrayVuelos[4].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1005,"Erika","Longhi",700,3,"p123");
	 strcpy(arrayVuelos[3].codigoDeVuelo,"p123");
	 arrayVuelos[3].banderadeVueloActivo=1;
	 arrayVuelos[5].isEmpty=0;
	 contadorDePasajeros++;
	 sddPassengers(arrayPasajeros,ELEMENTS,1006,"Nahuel","Maldonado",650,2,"p123");
	 strcpy(arrayVuelos[3].codigoDeVuelo,"p123");
	 arrayVuelos[3].banderadeVueloActivo=0;
	 arrayVuelos[6].isEmpty=0;
	 contadorDePasajeros++;
	 Banderaprimerpasajero=1;
 while(arrayPasajeros[ELEMENTS].isEmpty==1)
 {
	 printf("\n MENU : \n 1: ALTAS\n 2: MODIFICAR \n 3: BAJA \n 4: INFORMAR:\n");
	  utn_getNumero(&opcionMenu,"ingrese numero de opcion por favor:","solo se permite ingresar numeros del 1 al 4.\n Ingrese numero de opcion por favor: ",1,4,5);
	  switch (opcionMenu)
	  {
	  case 1:
		 if(Banderaprimerpasajero==0)
		 {
			 Banderaprimerpasajero=1;
		 }

	 	 CargaPasajero(&auxiliarCargas,contadorDePasajeros,arrayVuelos);
	 	 sddPassengers(arrayPasajeros,ELEMENTS,auxiliarCargas.id,auxiliarCargas.nombre,auxiliarCargas.apellido,auxiliarCargas.price,auxiliarCargas.typePassenger,auxiliarCargas.flycode);
	 	 contadorDePasajeros++;
	 	 break;
	  case 2:

	 	 if(Banderaprimerpasajero==1)
	 	 {
	 	utn_getNumero(&auxiliarId,"ingrese el Id del pasajero que desea modificar","el numero ingresado es invalido, ingrese el numero de pasajero que desea modificar",1000,40000,5);
	 	posicionModificador = findPassengerById(arrayPasajeros,ELEMENTS,auxiliarId);
	 	impresionPasajero(&arrayPasajeros[posicionModificador]);
	 	utn_getNumero(&AuxiliarModificador,"Este es el pasajero que desea modificar?\n1:Si\n2:No","Por favor ingrese solo \n1:Para Si\n2:Para No",1,2,5);
	 	if(AuxiliarModificador==1)
	 	{
	 		modificarPasajero(&arrayPasajeros[posicionModificador],"\ INDIQUE QUE DESEA MODIFICAR \n 1: nombre \n 2:apellido. \n 3:codigo de vuelo.\n 4: tipo de pasajero. \n 5: precio.","\ INDIQUE QUE DESEA MODIFICAR \n 1: nombre \n 2:apellido. \n 3:codigo de vuelo.\n  4: tipo de pasajero. \n 5: precio\n ingrese numero del 1 al 5 por favor: \n ");

	 	}
	 		 }
	 	 if(Banderaprimerpasajero==0)
	 	 {
	 		 printf("Primero debe realizar la carga de un pasajero.\n");
	 	 }

	 	break;
	 	break;
	  case 3:

		 	 if(Banderaprimerpasajero==1)
		 	 {
		utn_getNumero(&auxiliarId,"ingrese el Id del pasajero que desea eliminar","el numero ingresado es invalido, ingrese el numero de pasajero que desea eliminar",1000,40000,5);
	 	if (removedPassenger(arrayPasajeros,ELEMENTS, auxiliarId)!=0)
	 	{
	 		printf("\n el Id ingresado no se encontro registrado \n");
	 		break;
	 	}
	 	printf("\n Primero debe realizar la carga de un pasajero \n");
	 	contadorDePasajeros--;
	 	 break;
		 	 }
		 	 break;

	  case 4:

	 	 if(Banderaprimerpasajero==0)
	 	 {
	 		 printf("Primero debe realizar la carga de un pasajero.\n");
	 		 break;
	 	 }
	 	 printf ("1: LISTADO DE LOS PASAJEROS POR NOMBRE Y APELLIDO. \n 2: TOTAL Y PROMEDIO DE LOS PASAJEROS. \n 3: LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELOS 'ACTIVO");
	 	 utn_getNumero(&opcionMenu4,"\n ingrese numero de la opcion que desea:","solo se permite ingresar numeros del 1 al 3.\n Por favor ingrese el numero de la opcion que desea",1,3,5);
	 	 switch (opcionMenu4)
	 	 {
	 	 case 1:
	 		sortPassengers(arrayPasajeros,ELEMENTS,1);
	 		break;
	 	 case 2:
	 		PromedioPasajes(arrayPasajeros,ELEMENTS);
	 		break;
	 	 case 3:
	 		SepararVueloactivo(arrayPasajeros,arrayVuelos,contadorDePasajeros,1);
	 		 break;
	 	 }
	  }

 }

}



