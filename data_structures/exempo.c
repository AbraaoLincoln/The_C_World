#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *name;
    char *type;
    struct node *next; 
};



int main(void) {
    struct node n1;
    struct node n2;

    n1.name = (char*) malloc(50 * sizeof(char));
    n1.type = (char*) malloc(50 * sizeof(char));
    strcpy(n1.name, "var");
    strcpy(n1.type, "int");

    n2.name = (char*) malloc(50 * sizeof(char));
    n2.type = (char*) malloc(50 * sizeof(char));
    strcpy(n2.name, "var2");
    strcpy(n2.type, "String");
    n1.next = &n2;

    printf("%s\n", n2.type);
    printf("%s\n", n1.next->type);

    free(n1.name);
    free(n1.type);
    free(n2.name);
    free(n2.type);

    //checks for erro
    /*
    if(n1.name == NULL) {
        printf("Allocations fails");
        exit(EXIT_FAILURE);
    }
    */
}