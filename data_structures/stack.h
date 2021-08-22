#ifndef stack_File
#define stack_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack
{
    int maxSize;
    int size;
    char **stackArray;
} Stack;

Stack* stack_create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->maxSize = 5;
    stack->size = 0;
    stack->stackArray = (char**) malloc(stack->maxSize * sizeof(char**));
}

void stack_free(Stack *stack) {
    for(int i = 0; i < stack->size; i++) {
        free(stack->stackArray[i]);
    }
    free(stack);
}

Stack* stack_push(Stack *stack, char *value) {
    
    if(stack->size >= stack->maxSize) {
        stack->maxSize += 20;
        stack->stackArray = (char**) realloc(stack->stackArray, stack->maxSize * sizeof(char**));
    }

    if(stack->size < stack->maxSize) {
        char *newValue = (char*) malloc(strlen(value) * sizeof(char));
        strcpy(newValue, value);
        stack->stackArray[stack->size] = newValue;
        stack->size += 1;
    }

    return stack;
}

Stack* stack_pop(Stack *stack) {

    if(stack->size > 0) {
        free(stack->stackArray[stack->size - 1]);
        stack->stackArray[stack->size - 1] = NULL;
        stack->size -= 1;
    }

    return stack;
}

char* stack_top(Stack *stack) {
    if(stack->size > 0) {
        return stack->stackArray[stack->size - 1];
    }

    return NULL;
}

char* stack_topByIndex(Stack *stack, int index) {
    if(stack->size > 0 && index < stack->size) {
        return stack->stackArray[index];
    }

    return NULL;
}

void stack_display(Stack *stack) {
    printf("=========-Display Stack-=========\n");
    if(stack->size > 0) {
        for(int i = stack->size - 1; i >= 0; i--) {
            printf("%s\n", stack->stackArray[i]);
        }
        printf("--------------------\n");
    }else {
        printf("Empty Stack\n");
    }
}

#endif