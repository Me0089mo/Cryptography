#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void menu();

void main(){
	//Matriz de correspondencia de valores
	unsigned char mat[2][26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
						0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	char c, key[3];
	char *msj_cip;
	char *msj_descip;
	int a=0, b=0;
	int op=0, n=26, cont, cont2, nuevo_val=0, bandera=0, aux=0;
	do{
		//Despliegue del menu de opciones
		menu();
		scanf("%d", &op);
		//Cifrado del mensaje
		if(op==1){
			msj_cip=(char*)calloc(200, sizeof(char));
			printf("Ingrese la llave (con formato a,b): ");
			scanf("%s", &key);
			a=(int)key[0];
			b=(int)key[2];
			printf("Ingrese el mensaje a cifrar: ");
			//Obtención del mensaje caracter a caracter
			bandera=0;
			while((c=getchar())!='\n' || bandera==0){
				for(cont=0; cont<n; cont++){
					if(toupper(c)==mat[0][cont]){
						//Se obtiene el nuevo valor para la letra
						nuevo_val=(mat[1][cont]*a+b)%n;
						for(cont2=0; cont2<n; cont2++){
							if(nuevo_val==mat[1][cont2])
								msj_cip[strlen(msj_cip)]=mat[0][cont2];
						}
					}
				}
				if(c=='\n')
					bandera=1;
			}
			printf("Mensaje cifrado: %s\n", msj_cip);
			free(msj_cip);
		}
		//Descifrado del mensaje
		else if(op==2){
			msj_descip=(char*)calloc(200, sizeof(char));
			printf("Ingrese la llave (con formato a,b): ");
			scanf("%s", &key);
			a=(int)key[0];
			b=(int)key[2];
			printf("Ingrese el mensaje a descifrar: ");
			//Obtención del mensaje caracter a caracter
			bandera=0;
			while((c=getchar())!='\n' || bandera==0){
				for(cont=0; cont<n; cont++){
					if(toupper(c)==mat[0][cont]){
						//Se obtiene el nuevo valor para la letra
						aux=(mat[1][cont]-b);
						//Tnto para valores positivos como negativos falta poner la multiplicación por el inverso
						if(aux>0)
							nuevo_val=aux%n;
						else
							nuevo_val=(n+aux)%n;
						for(cont2=0; cont2<n; cont2++){
							if(nuevo_val==mat[1][cont2])
								msj_descip[strlen(msj_descip)]=mat[0][cont2];
						}
					}
				}
				if(c=='\n')
					bandera=1;
			}
			printf("Mensaje descifrado: %s\n", msj_descip);
			free(msj_descip);
		}
	}while(op!=3);
}

void menu(){
	printf("Escoja la opcion que desee realizar: ");
	printf("\n1.- Cifrar");
	printf("\n2.- Descifrar");
	printf("\n3.- Salir         ");
}