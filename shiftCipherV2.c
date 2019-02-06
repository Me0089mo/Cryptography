#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

unsigned char mat[2][26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
					0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

void menu();
char *cipher(int key, char *msj);
char *descipher(int key, char *msj);

void main(){
	
	char c;
	char *msj=(char*)malloc(sizeof(char)*500);
	int op=0, key=0;
	do{
		//Despliegue del menu de opciones
		menu();
		scanf("%d", &op);
		//Cifrado del mensaje
		if(op==1){
			printf("Ingrese la llave: ");
			scanf("%d", &key);
			printf("Ingrese el mensaje a cifrar: ");
			scanf("%s", msj);
			printf("Mensaje cifrado: %s\n", &cipher(key, msj));
		}
		//Descifrado del mensaje
		else if(op==2){
			printf("Ingrese la llave: ");
			scanf("%d", &key);
			printf("Ingrese el mensaje a descifrar: ");
			scanf("%s", msj);
			printf("Mensaje descifrado: %s\n", &descipher(key, msj));
		}
	}while(op!=3);
}

void menu(){
	printf("Escoja la opcion que desee realizar: ");
	printf("\n1.- Cifrar");
	printf("\n2.- Descifrar");
	printf("\n3.- Salir         ");
}

char *cipher(int key, char *msj){
	//Obtención del mensaje caracter a caracter
	int cont, cont2, cont3, nuevo_val=0, aux=0, n=26;
	char *msj_cip=(char*)malloc(sizeof(char)*500);
	char c;
	for(cont3=0; cont3<strlen(msj); cont3++){
		c=msj[cont3];
		for(cont=0; cont<n; cont++){
			if(toupper(c)==mat[0][cont]){
				//Se obtiene el nuevo valor para la letra
				nuevo_val=(mat[1][cont]+key)%n;
				for(cont2=0; cont2<n; cont2++){
					if(nuevo_val==mat[1][cont2])
						msj_cip[strlen(msj_cip)]=mat[0][cont2];
				}
			}
		}
	}
	return msj_cip;
}

char *descipher(int key, char *msj){
	//Obtención del mensaje caracter a caracter
	int cont, cont2, cont3, nuevo_val=0, aux=0, n=26;
	char *msj_descip=(char*)malloc(sizeof(char)*500);
	char c;
	for(cont3=0; cont3<strlen(msj); cont3++){
		c=msj[cont3];
		for(cont=0; cont<n; cont++){
			if(toupper(c)==mat[0][cont]){
				//Se obtiene el nuevo valor para la letra
				aux=(mat[1][cont]-key);
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
	}
	return msj_descip;
}