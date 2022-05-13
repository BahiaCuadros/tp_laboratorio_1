/*
 * Tp1operaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Bahia
 */

int tp1_porcentaje(float porcentaje,float numero, float* pResultado)
{
	float multiplicador;
	int retorno= -1;
	float resultado;
	if (porcentaje > 0 && numero > 0)
	{
		multiplicador = porcentaje/100;
		*pResultado= numero*multiplicador;
		retorno=0;
	}
	return retorno;
}
int tp1_pasodemoneda(float monedaoriginal,float monedafinal,float precioaconvertir,float* pResultado)
{
	int retorno = -1;
	if(monedaoriginal >0 && monedafinal > 0, precioaconvertir > 0 )
	{
			float multiplicador;
	multiplicador=monedaoriginal/monedafinal;
	*pResultado=precioaconvertir*multiplicador;
	retorno= 0;
	}
	return retorno;

}
int tp1_division(float valorTot,float cantidadTot, float* valorUnidad)
{
	int retorno = -1;
	float resultado;
 if(cantidadTot != 0 )
 {
	 	resultado = valorTot/cantidadTot;
		retorno= 0;	*valorUnidad=resultado;

 }


	return retorno;
}
int tp1_Diferencias(float precio1, float precio2, float*diferencia)
{
	if (precio1>precio2)
	{
		*diferencia=precio1-precio2;
	}
	else
	{
		if(precio1 <precio2)
		{
			*diferencia=precio2-precio1;
		}
		else
		{
			*diferencia = 0;
		}
	}
	return 0;
}
