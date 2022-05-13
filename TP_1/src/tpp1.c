/*
 ============================================================================
 Name        : Trabajo.c
 Author      : -
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"
#include "Tp1operaciones.h"
int main(void)
{

setbuf(stdout,NULL);
int opcion;
float Kilometros;
int validacion;
int validacion1=-1;
int validacion2=-1;
int validacion0;
int banderaCalculoHecho;
int banderaProgramaTerminado=0;
float precioAerolineas;
float precioLatam;
float latamDebito;
float latamCredito;
float latamBitcoin;
float latamUnitario;
float aerolineasDebito;
float aerolineasCredito;
float aerolineasBitcoin;
float aerolineasUnitario;
float diferencia;
banderaCalculoHecho = 0;


while (banderaProgramaTerminado==0)
{
system ("cls");
printf("\n MENU: ");
switch (validacion1)
{




	case 0:
		printf("\n 1) Kilometros ingresados: %.2f",Kilometros);
		break;
	case -1:
		printf("\n 1) Ingrese cantidad de Kilometros:");
		break;
}

	switch (validacion2)
	{
		case 0:
		printf("\n 2) Precios de vuelos ingresados: \n *Por Aerolineas: %.2f \n *Por latam : %.2f",precioAerolineas,precioLatam);
		break;
	case -1:
		printf ("\n 2) ingrese precio de vuelos por Aerolineas y por Latam. ");
		break;
	}
	switch (banderaCalculoHecho)
	{
	case 1:
		printf ("\n 3) Los  calculos ya fueron procesados, ya puede mostrar los resultados con la opcion 4");
		break;
	case 0:
		printf ("\n 3) Calcular todos los costos. ");
		break;
	}
	printf(" \n 4)Informar resultados. \n 5)Carga forzada de datos.  ");
	if(validacion1==-1 && validacion2 == 0 && (opcion ==4  ||opcion==3))
	{
		printf ("\n Por favor debe ingresar primero la cantidad de kilometros:(opcion1)\n");
	}
	if(validacion1==0 && validacion2 == -1 && (opcion ==4  ||opcion==3))
	{
		printf ("\n Por favor debe ingresar primero el precio de los vuelos:(opcion2)\n");
	}
	if(validacion1==-1 && validacion2 == -1 && (opcion ==4  ||opcion==3))
	{
		printf ("\n Por favor debe ingresar primero:\n Datos de cantidad de kilometros:(opcion1)\n Valores delos vuelos: (opcion2) \n");
	}
	if(validacion1==0 && validacion2 == 0 && opcion ==4 && banderaCalculoHecho==0)
	{
		printf ("\n Por favos realice los calculos con la opcion 3 antes de mostrar en pantalla\n");
	}

validacion=tp1_Menu(1,5,"\n ingrese el numero de opcion del menu a la que desea ir: \n","\n ingrese opcion del 1 al 5: \n", &opcion);



switch (opcion)
{
case 1:
	system ("cls");
	validacion1= tp1_getFloat ("ingresar cantidad de kilometros:\n","\n ingrese cantidad de kilometros mayor a cero:\n", &Kilometros ,0);
	break;
case 2:
	system ("cls");
	validacion2= tp1_getFloat("ingresar precio por Latam:\n","\n ingrese precio por Latam mayor a cero:\n", &precioLatam ,0);
	validacion2= tp1_getFloat("ingresar precio por Aerolineas:\n","\n ingrese precio por aerolineas mayor a cero:\n", &precioAerolineas ,0);
	break;
case 5:
	precioAerolineas=162965;
	precioLatam=159339;
	Kilometros=7090;
	validacion1=0;
	validacion2=0;
case 3:
		if(validacion1== 0 && validacion2==0)

	{
	validacion0= tp1_porcentaje(90,precioLatam,&latamDebito);
	validacion0= tp1_porcentaje(125,precioLatam,&latamCredito);
	validacion0=  tp1_pasodemoneda (1,4606954.55,precioLatam,&latamBitcoin);
	validacion0= tp1_division(precioLatam,Kilometros, &latamUnitario);
	validacion0= tp1_porcentaje(90,precioAerolineas,&aerolineasDebito);
	validacion0= tp1_porcentaje(125,precioAerolineas,&aerolineasCredito);
	validacion0=  tp1_pasodemoneda (1,4606954.55,precioAerolineas,&aerolineasBitcoin);
	validacion0= tp1_division(precioAerolineas,Kilometros, &aerolineasUnitario);
	validacion0 = tp1_Diferencias(precioAerolineas,precioLatam,&diferencia);
	banderaCalculoHecho=1;
	}

		if (opcion != 5)
		{
				break;
		}
case 4:
	if(banderaCalculoHecho==1)
	{
	system ("cls");
	printf ("\n \n Kilometros ingresados $%.2f:",Kilometros);
	printf("\n \n Latam: $%.2f ",precioLatam);
	printf("\n \n a) Precio con tarjeta de debito: $%.2f",latamDebito);
	printf("\n b) Precio con tarjeta de cretido: $%.2f",latamCredito);
	printf("\n c) Precio en Bitcoin: $%f",latamBitcoin);
	printf("\n d) Precio kilometro unitario $%.2f",latamUnitario);
	printf("\n \n Aerolineas: %.2f $", precioAerolineas);
	printf("\n a) Precio con tarjeta de debito: $%.2f",aerolineasDebito);
	printf("\n b) Precio con tarjeta de cretido: $%.2f",aerolineasCredito);
	printf("\n c) Precio en Bitcoin: $%f",aerolineasBitcoin);
	printf("\n d) Precio kilometro unitario $%.2f",aerolineasUnitario);
	printf ("\n\n diferencia de precios: $%.2f",diferencia);
	banderaProgramaTerminado=1;

	if (banderaProgramaTerminado==1)
	{	validacion0 = tp1_getInt("\n\nPara iniciar de nuevo digite : 0\n para finalizar el programa digite: 1 \n ", "\n ERROR: \n Para iniciar de nuevo digite : 0\n para finalizar el programa digite: 1 \n",&banderaProgramaTerminado,0,1);
		validacion1= -1;
		validacion2= -1;
		banderaCalculoHecho= 0;
	}
	else
	{
		exit(-1);
	}

	}

	}

{
}
}


}





