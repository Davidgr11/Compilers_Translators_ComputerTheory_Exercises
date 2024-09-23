#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LMC 100
#define TM 30

/*
	TEORIA COMPUTACIONAL
	Practica 2

	Integrantes:
	- Gonzalez Robles David Alejandro

*/
/////////////////////////////////////////
int main()
{
	printf("---BIENVENIDO AL AUTÓMATA---\n\n");
	srand(time(NULL));
	int *matriz = NULL,       // matriz dinamica
    cont=0,     //para saber en que linea del archivo estoy
	i=0,        //recorrer el bufer
	j=0,         //moverme en el vector de estados
	k=0,          //contador auxiliar
	col = 0,  row = 0;          // filas y columnas
	char edos[TM];		//ahi almaceno los estados
	char trans[TM][3];  //ahi almaceno las transicioes
	char caracter[TM];
	int band=0;     //auxiliar para confirmar
	
	//inicializamos la matrix de trans
	for(i=0;i<TM;i++){
		for(j=0;j<3;j++){
			trans[i][j]='-';
		}
	}
	//inicializamos vector de estados
	for(j=0;j<TM;j++){
		edos[j]='-';//vacio
	}
	i=0;
	j=0;
	
	//LECTURA DE ARCHIVO
	printf("Leyendo archivo...\n");
	
	FILE *ap;
	ap=fopen("Automata.txt", "r");
	if (ap == NULL){
		printf("Error al abrir el fichero");
	}
	else{
		printf("El archivo se abrio de manera exitosa\n\n\n");
		
		//bufer para ir leyendo linea por linea
		char bufer[LMC];
    	while (fgets(bufer, LMC, ap))
    	{
        	strtok(bufer, "\n");
        	//printf("La línea es: '%s'\n", bufer);
	
			//opciones para guardar lo necesario segun la linea del archivo
			switch(cont){
				case 0: //cadena a entero para saber cuantos estados hay
						row=atoi(bufer);
						printf("Numero de estados del AFND->%d\n", row);
						break;
				
				case 1: printf("Los estados son-> ");
						//almacena estados en un vector
						while(j<row){
							if(bufer[i]!=','){
								edos[j]=bufer[i];
								printf("%c ", edos[j]);
								j++;
								i++;
							}
							else{
								i++;
							}
						}
						printf("\n");
						printf("\nGuardando transisiones...");
						break;

				default: //inicializamos la matriz de transiciones
						j=0;
						i=0; //inicializamos
						while(j<3){
							if(bufer[i]!=','){
								trans[k][j]=bufer[i];
								//printf("%c", trans[k][j]);
								j++;
								i++;
							}
							else{
								i++;
							}		
						}
						k++;
						break;
						
			}
			cont++;
    	}
		printf("\nTransiciones guardadas con exito\n\n");
		fclose(ap);
	}
	
	//inicializamos vector de estados
	for(j=0;j<TM;j++){
		caracter[j]='_';//vacio
	}
	
	//llenamos el vector de caracteres
	printf("Los caracteres son-> ");
	k=0;
	for(j=0;j<TM;j++){
		band=0;
		//recoremos todo para checar que no se repita
		for(i=0;i<TM;i++){
			if(trans[j][2]==caracter[i]){
				band=1;
			}
		}
		if(band==0 && trans[j][2]!='-'){
			caracter[k]=trans[j][2];
			printf("%c ", caracter[k]);
			k++;
		}
	}

	//imprimimos el numero de caracteres resultantes
	col=k;
	printf("\n%d caracteres\n", col);
	
	//ordenamos los caracteres
	char aux;
	for(i=0;i<TM;i++){
		for(j=0;j<TM-1;j++){
			if(caracter[j]>caracter[j+1]){
				aux=caracter[j];
				caracter[j]=caracter[j+1];
				caracter[j+1]=aux;
				
			}
		}
	}
	/*for(i=0;i<TM;i++){
		printf("%c\n", caracter[i]);
	}*/

	char M[row+1][col+1][3];//creamos el diagrama de transiciones

	//inicializamos el diagrama
	for(i=0;i<row+1;i++){
		for(j=0;j<col+1;j++){
			for(k=0;k<3;k++){
				M[i][j][k]=' ';
				//printf("%c", M[i][j][k]);
			}
			//printf(" | ");
		}
		//printf("\n");
	}

	//primero llenamos los estados y los caracteres de la matriz
	M[0][0][0]='E';
	M[0][0][1]='D';
	M[0][0][2]='O';
	for(i=1;i<row+1;i++){
		M[i][0][1]=edos[i-1];
		//printf("%c", M[i][0][0]);
	}
	printf("\n");
	for(i=1;i<col+1;i++){
		M[0][i][1]=caracter[i-1];
		//printf("%c", M[0][i][0]);
	}
	printf("\n");

	//almacenamos los estados iniciales y los finales
	j=0;
	k=0;
	char check[2][3];
	for(i=0;i<row;i++){
		printf("El estado '%c' es 1)inicial 2)final 3)intermedio\n", edos[i]);
		scanf("%d", &band);
		if(band==1){
			check[0][k]=edos[i];
				k++;
		}
		if(band==2){
			check[1][j]=edos[i];
				j++;
		}
	}
	/*for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%c ", check[i][j]);
		}
		printf("\n");
	}*/
	
	//Llenamos el diagrama de transiciones
	int a;
	for(i=1;i<row+1;i++){//mueve edos matriz
		for(j=1;j<col+1;j++){//mueve caracteres
			for(k=0;k<TM;k++){
				if(M[i][0][1]==trans[k][0]){
					if(M[0][j][1]==trans[k][2]){
						M[i][j][1]=trans[k][1];
						for(a=0;a<3;a++){
							if(trans[k][1]==check[0][a]){
								M[i][j][2]='+';
							}
						}
						for(a=0;a<2;a++){
							if(trans[k][1]==check[1][a]){
								M[i][j][2]='*';
							}
						}
					}
				} 
			}
		}
	}

	printf("\nDIAGRAMA DE TRANSICIONES\n\n");
	
	//imprimimos
	for(i=0;i<row+1;i++){
		for(j=0;j<col+1;j++){
			for(k=0;k<3;k++){
				printf("%c", M[i][j][k]);
			}
			printf(" | ");
		}
		printf("\n");
	}
	
}