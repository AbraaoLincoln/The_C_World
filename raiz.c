#include <stdio.h>
#include <stdlib.h>
#define INCREMENTO 0.0001

float rzq(float n){
	float valor_inc = 0.0001, sair = 1;

	do{
		if((int)(valor_inc * valor_inc) == n){
			sair = 0;
		}else{
			valor_inc += INCREMENTO;
		}
	}while(sair);

	return valor_inc;
}

int main(void){
	float n = 0;
	printf("Entre com o numero para calcular a raiz quadrada: \n");
	scanf("%f", &n);
	printf("Raiz de %0.1f é: %0.4f\n", n, rzq(n));
	return 0;
}
