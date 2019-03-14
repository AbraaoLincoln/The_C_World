#include<stdio.h>
#include<stdlib.h>
#define LINHAS 3
#define COLUNAS 3
#define SIZE_STRING 10

int main(){
	char ***matriz;

	//Alocando a memoria
	matriz = (char***) malloc(LINHAS*sizeof(char**));
	for(int i=0; i < LINHAS;i++){
		matriz[i] = (char**) malloc(COLUNAS*sizeof(char**));
	}

	for(int i=0; i < LINHAS;i++){
		for(int j=0; j < COLUNAS;j++){
			matriz[i][j] = (char*) malloc(SIZE_STRING*sizeof(char));
		}
	}

	//Recebendo as strings
	printf("Digite as strings:\n");
	for(int i=0; i < LINHAS;i++){
		for(int j=0; j < COLUNAS;j++){
			fscanf(stdin, "%[^\n]",matriz[i][j]);
			setbuf(stdin, NULL);
		}
	}

	//Lendo as strings da matriz e exebindo na tela
	for(int i=0; i < LINHAS;i++){
		for(int j=0; j < COLUNAS;j++){
			printf("%s ", matriz[i][j]);
		}
		printf("\n");
	}

	//Liberando a memoria.
	for(int i=0; i < LINHAS;i++){
		for(int j=0; j < COLUNAS;j++){
			free(matriz[i][j]);
		}
	}

	for(int i=0; i < LINHAS;i++){
		free(matriz[i]);
	}
	free(matriz);
	return 0;
}