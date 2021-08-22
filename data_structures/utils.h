#ifndef utils_File
#define utils_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* utils_strcat(char *str1, char *str2) {
    char *aux = (char*) malloc(1 * sizeof(char));
    strcat(aux, str1);
    strcat(aux, str2);

    return aux;
}


#endif