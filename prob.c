#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int result[6] = {0}, n[] = {10, 100, 1000, 10000, 100000}, r = 0;
  float fna = 0;
  srand(time(NULL));

  for(int i = 0;i < 5;i++){

    for(int j = 0; j < n[i]; j++){
      r = rand() % 6 + 1;
      result[r-1] += 1;
    }

    printf("Frequencias de ocorrencias: n = %d:\n", n[i]);
    for(int z = 0;z < 6;z++){
      fna = (float)result[z] / (float)n[i];
      printf(" n%d = %0.4f", z+1, fna);
      if( z == 2 || z == 5){
        printf("\n");
      }
    }
    printf("Diferença para a probabilidade padrão:\n");
    for(int z = 0;z < 6;z++){
      fna = (float)result[z] / (float)n[i] - (float)1/6;
      printf(" n%d = %0.4f", z+1, fna);
      if( z == 2 || z == 5){
        printf("\n");
      }
    }

  }

}
