#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "EuclidesAlgorithm.h"


int inverse(int z, int a){
	int res=0, cont=0, cociente=0, inverso=0, val_z_inicial=0;
	//Matriz donde se guardarán las ecuaciones generadas
	int **ecuaciones=(int**)malloc(sizeof(int*));
	//Obtención de ecuaciones a partir del Algoritmo de Euclides
	val_z_inicial=z;
	do{
		res=a%z;
		cociente=a/z;
		ecuaciones[cont]=(int*)malloc(sizeof(int)*4);
		ecuaciones[cont][0]=res;
		ecuaciones[cont][1]=a;
		ecuaciones[cont][2]=z;
		ecuaciones[cont][3]=cociente;
		a=z;
		z=res;
		cont++;
	}while(res!=0);
	//Sustitución de ecuaciones a partit del Algoritmo Extendido de Euclides
	cont-=2;
	if(cont==-1)
		inverso=1;
	else
		inverso=extendedAlgorithm(ecuaciones, cont);
		if(cont%2==0)
			inverso=val_z_inicial-(inverso%val_z_inicial);
	return inverso;
}

//Función recursiva
int extendedAlgorithm(int **ecuaciones, int numEc){
	//Variable aux recupera el valor acumulado de b's hasta el momento en el caso de la ecuación 1
	int aux=0, cont=0;
	//Tratándose de la primera ecuación
	if(numEc==0)
		return ecuaciones[numEc][3];
	//Tratándose de la segunda ecuación
	else if(numEc==1){
		aux=extendedAlgorithm(ecuaciones, numEc-1);
		return ecuaciones[numEc][3]=aux*ecuaciones[numEc][3]+1;
	}
	//En el caso de las demás ecuaciones
	else{
		aux=extendedAlgorithm(ecuaciones, numEc-1);
		ecuaciones[numEc][3]=ecuaciones[numEc][3]*ecuaciones[numEc-1][3];
		ecuaciones[numEc][3]=ecuaciones[numEc][3]+ecuaciones[numEc-2][3];
		return ecuaciones[numEc][3];
	}
}
