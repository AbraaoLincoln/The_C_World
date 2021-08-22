#ifndef tuple_File
#define tuple_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tuple
{
    char* name;
    char* type;
} Tuple;

Tuple* tuple_create(char *name, char *type) {
    Tuple *tuple = (Tuple*) malloc(sizeof(Tuple));
    tuple->name = (char*) malloc(strlen(name) * sizeof(char));
    tuple->type = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(tuple->name, name);
    strcpy(tuple->type, type);
    return tuple;
}

void tuple_freeTuple(Tuple *tuple) {
    free(tuple->name);
    free(tuple->type);
    free(tuple);
}

void tuple_display(Tuple *tuple) {
    printf("=========-Display Tuple-=========\n");
    printf("%s\n", tuple->name);
    printf("%s\n", tuple->type);
    printf("--------------------\n");
}

#endif