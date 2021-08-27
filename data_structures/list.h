#ifndef list_File
#define list_File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct List
{
    int size;
    int minSize;
    int arraySize;
    char **array;
}List;


List* list_create(int arraySize) {
    List *list = (List*) malloc(sizeof(List));
    list->arraySize = arraySize;
    list->minSize = arraySize;
    list->size = 0;
    list->array = (char**) malloc(arraySize * sizeof(char**));

    return list;
}

void list_add(List *list, char *str) {
    if(list->size == list->arraySize) {
        list->arraySize += 20;
        list->array = (char**) realloc(list->array, list->arraySize * sizeof(char**));
    }

    list->array[list->size] = str;
    list->size++;
}

void list_pop(List *list) {
    if(list->size > 0 ) {
        if(list->size == list->minSize) {
            list->arraySize = list->minSize;
            list->array = (char**) realloc(list->array, list->arraySize * sizeof(char**));
        }

        free(list->array[(list->size - 1)]);
        list->array[list->size - 1] = NULL;
        list->size--;
    }
}

char* list_get(List *list, int index) {
    if(index < list->size) return list->array[index];

    return NULL;
}

#endif