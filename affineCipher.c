#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "EuclidesAlgorithm.h"

//Matriz de correspondencia de valores
unsigned char mat[2][26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
							0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	
void menu();
char *cipher(int key[], char *msj);
char *descipher(int key[], char *msj);
/*int inverse(int key[]);
int extendedAlgorithm(int **ecuaciones, int numEc);
*/
void main(){
	int key[2];
	char *msj=(char*)malloc(sizeof(char)*500);
	int op=0;
	do{
		//Despliegue del menu de opciones
		menu();
		scanf("%d", &op);
		//Cifrado del mensaje
		if(op==1){
			printf("Ingrese la llave: \na=");
			scanf("%d", &key[0]);
			printf("b=");
			scanf("%d", &key[1]);
			printf("Ingrese el mensaje a cifrar: ");
			if(fgets(msj, sizeof(msj), stdin))
    			msj[strcspn(msj, "\n")]='\0';
			else{
			}
			printf("Mensaje cifrado: %s\n", cipher(key, msj));
		}
		//Descifrado del mensaje
		else if(op==2){
			printf("Ingrese la llave: \na=");
			scanf("%d", &key[0]);
			printf("b=");
			scanf("%d", &key[1]);
			printf("Ingrese el mensaje a descifrar: ");
			if(fgets(msj, sizeof(msj), stdin))
    			msj[strcspn(msj, "\n")]='\0';
			else{
			}
			printf("Mensaje descifrado: %s\n", descipher(key, msj));
		}
	}while(op!=3);
}

void menu(){
	printf("Escoja la opcion que desee realizar: ");
	printf("\n1.- Cifrar");
	printf("\n2.- Descifrar");
	printf("\n3.- Salir         ");
}

char *cipher(int key[], char *msj){
	//Obtención del mensaje caracter a caracter
	int cont, cont2, cont3, nuevo_val=0, aux=0, n=26;
	char *msj_cip=(char*)malloc(sizeof(char)*500);
	char c;
	printf("%s", msj);
	for(cont3=0; cont3<strlen(msj); cont3++){
		c=msj[cont3];
		for(cont=0; cont<n; cont++){
			if(toupper(c)==mat[0][cont]){
				//Se obtiene el nuevo valor para la letra
				nuevo_val=(mat[1][cont]*key[0]+key[1])%n;
				for(cont2=0; cont2<n; cont2++){
					if(nuevo_val==mat[1][cont2])
						msj_cip[strlen(msj_cip)]=mat[0][cont2];
				}
			}
		}
	}
	printf("%s\n", msj_cip);
	return msj_cip;
}

char *descipher(int key[], char *msj){
	//Obtención del mensaje caracter a caracter
	int cont, cont2, cont3, nuevo_val=0, aux=0, n=26, inv=0;
	char *msj_descip=(char*)malloc(sizeof(char)*500);
	char c;
	for(cont3=0; cont3<strlen(msj); cont3++){
		c=msj[cont3];
		for(cont=0; cont<n; cont++){
			if(toupper(c)==mat[0][cont]){
				//Se obtiene el inverso multiplicativo
				inv=inverse(26, key[0]);
				//Se obtiene el nuevo valor para la letra
				aux=(mat[1][cont]-key[1])*inv;
				//En caso de qu eel resultadi sea positivo
				if(aux>0)
					nuevo_val=(aux)%n;
				//En caso de que sea negativo
				else
					nuevo_val=n-(aux%n);
				for(cont2=0; cont2<n; cont2++){
					if(nuevo_val==mat[1][cont2])
						msj_descip[strlen(msj_descip)]=mat[0][cont2];
				}
			}
		}
	}
	return msj_descip;
}

/*int inverse(int key[]){
	int res=0, cont=0, a=0, b=0, cociente=0, val_a_inicial=0, inverso=0;
	//Matriz donde se guardarán las ecuaciones generadas
	int **ecuaciones=(int**)malloc(sizeof(int*));
	//Obtención del mayor de los 2 números
	if(key[0]>key[1]){
		a=key[0];
		b=key[1];
		val_a_inicial=a;
	}
	else{
		a=key[1];
		b=key[0];
		val_a_inicial=a;
	}
	//Obtención de ecuaciones a partir del Algoritmo de Euclides
	do{
		res=a%b;
		cociente=a/b;
		ecuaciones[cont]=(int*)malloc(sizeof(int)*4);
		ecuaciones[cont][0]=res;
		ecuaciones[cont][1]=a;
		ecuaciones[cont][2]=b;
		ecuaciones[cont][3]=cociente;
		a=b;
		b=res;
		cont++;
	}while(res!=0);
	//Sustitución de ecuaciones a partit del Algoritmo Extendido de Euclides
	cont-=2;
	if(cont==-1)
		inverso=1;
	else
		inverso=extendedAlgorithm(ecuaciones, cont);
		if(cont%2==0)
			inverso=val_a_inicial-(inverso%val_a_inicial);
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
}*/
