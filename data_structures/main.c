#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedList.h"

int main(void) {
    struct Node *linkedList;
    struct Node *n;
    struct Node *n1;

    linkedList = createNode("foo", "int");
    n = createNode("bar", "float");
    insert(linkedList, n);
    //n1 = find(linkedList, n);
    n1 = createNode("foobar", "string");
    insert(linkedList, n1);
    display(linkedList);
    printf("=======================\n");
    linkedList = shift(linkedList);
    //printf("%i\n", nodeAreEquals(linkedList, n));
    //printf("%s\n", n1->type);
    //removeNode(linkedList, n);
    display(linkedList);
    printf("=======================\n");
    linkedList = pop(linkedList);
    display(linkedList);
    printf("=======================\n");
    linkedList = pop(linkedList);
    //linkedList = shift(linkedList);
    display(linkedList);
    printf("=======================\n");
}