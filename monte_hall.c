#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void simulacao_fixa(int *n, int modo);

int main(){
	srand(time(NULL));
	int n=0;
	float freq_relativa=0;

	for(int i=0; i < 10000; i++){
		simulacao_fixa(&n, 0);
	}
	freq_relativa = (float)n / 10000;
	printf("Probabilidade sem mudar a escolha: %0.2f\n", freq_relativa);
	n = 0;
	for(int i=0; i < 10000; i++){
		simulacao_fixa(&n, 1);
	}
	freq_relativa = (float)n / 10000;
	printf("Probabilidade mudando a escolha: %0.2f\n", freq_relativa);
}

void simulacao_fixa(int *n, int modo){
	int escholida, premiada, abrir_vazia, aux;
	premiada = rand() % 3;
	escholida = rand() % 3;
	while(1){
		abrir_vazia = rand() % 3;
		if(escholida != abrir_vazia && abrir_vazia != premiada){
			break;
		}
	}
	//printf("%d %d %d\n", escholida, premiada, abrir_vazia);
	if(modo == 1){
		while(1){
			aux = rand() % 3;
			if(aux != escholida && aux != abrir_vazia){
				escholida = aux;
				break;
			}
		}
	}

	if(escholida == premiada){
		*n += 1;
	}

}