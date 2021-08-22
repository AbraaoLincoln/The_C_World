#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedList.h"
#include "./hashTable.h"
#include "./stack.h"
#include "./utils.h"

void testLinkedList();
void testHashTable();
void testStack();
void testeHashtableAndStack();

int main(void) {
    //testLinkedList();
    //testHashTable();
    //testStack();
    testeHashtableAndStack();
}

void testLinkedList() {
    struct Node *linkedList;
    struct Node *n;
    struct Node *n1;

    linkedList = linkedList_createNode("foo", "int");
    n = linkedList_createNode("bar", "float");
    linkedList_insert(linkedList, n);
    //n1 = find(linkedList, n);
    n1 = linkedList_createNode("foobar", "string");
    linkedList_insert(linkedList, n1);
    linkedList_display(linkedList);
    printf("=======================\n");
    linkedList = linkedList_shift(linkedList);
    //printf("%i\n", nodeAreEquals(linkedList, n));
    //printf("%s\n", n1->type);
    //removeNode(linkedList, n);
    linkedList_display(linkedList);
    printf("=======================\n");
    linkedList = linkedList_pop(linkedList);
    linkedList_display(linkedList);
    printf("=======================\n");
    linkedList = linkedList_pop(linkedList);
    //linkedList = shift(linkedList);
    linkedList_display(linkedList);
    printf("=======================\n");
}

void testHashTable() {
    HashTable *hashTable = hashTable_create(10);

    Tuple *t1 = tuple_create("bar", "int");
    hashTable_insert(hashTable, "var", t1);
    //hashTable_display(hashTable);
    // printf("====================\n");
    Tuple *t2 = tuple_create("foo", "float");
    hashTable_insert(hashTable, "var", t2);
    //hashTable_display(hashTable);
    Tuple *t3 = tuple_create("foo", "int");
    hashTable_insert(hashTable, "var2", t2);

    //test
    printf("\nInsert\n\n");
    hashTable_insert(hashTable, "var1", t2);
    hashTable_insert(hashTable, "var2", t3);
    hashTable_insert(hashTable, "var3", t2);
    hashTable_insert(hashTable, "var4", t2);
    hashTable_insert(hashTable, "var5", t2);
    hashTable_insert(hashTable, "var6", t2);
    hashTable_insert(hashTable, "var7", t2);
    hashTable_insert(hashTable, "var8", t2);
    hashTable_insert(hashTable, "var9", t2);
    hashTable_insert(hashTable, "var10", t2);
    hashTable_insert(hashTable, "var11", t2);
    hashTable_insert(hashTable, "var12", t2);
    hashTable_insert(hashTable, "var13", t2);
    hashTable_insert(hashTable, "var14", t2);
    hashTable_insert(hashTable, "var15", t2);
    hashTable_display(hashTable);

    //remove
    printf("\nRemove\n\n");
    hashTable_remove(hashTable, "var2");
    hashTable_remove(hashTable, "var11");
    hashTable_display(hashTable);

    //find
    printf("\nFind\n\n");
    Tuple* t = hashTable_find(hashTable, "var");

    if(t != NULL) {
        tuple_display(t);
    }else{
        printf("key: var not found\n");
    };

    t = hashTable_find(hashTable, "bar");

    if(t != NULL) {
        tuple_display(t);
    }else{
        printf("key: bar not found\n");
    };

    t = hashTable_find(hashTable, "var2");

    if(t != NULL) {
        tuple_display(t);
    }else{
        printf("key: var2 not found\n");
    };

    t = hashTable_find(hashTable, "var13");

    if(t != NULL) {
        tuple_display(t);
    }else{
        printf("key: var13 not found\n");
    };


    hashTable_freeHashtable(hashTable);
}

void testStack() {
    Stack *s = stack_create();
    char *top;

    printf("\nPush\n\n");
    stack_push(s, "teste");
    stack_push(s, "teste1");
    stack_push(s, "teste2");
    stack_push(s, "teste3");
    stack_push(s, "teste4");
    stack_push(s, "teste5");
    stack_push(s, "teste6");
    stack_display(s);

    printf("\nPop\n\n");
    stack_pop(s);
    stack_pop(s);
    stack_display(s);

    printf("\nTop\n\n");
    top = stack_top(s);
    if(top != NULL) printf("%s\n", top);

    printf("\nTop - Index\n\n");
    top = stack_topByIndex(s, 2);
    if(top != NULL) printf("%s\n", top);

    stack_free(s);
}

void testeHashtableAndStack() {
    HashTable *hashTable = hashTable_create(10);
    Stack *s = stack_create();
    char *key;

    printf("\nStack - Push\n\n");
    stack_push(s, "global");

    printf("\nHashTable - Insert\n\n");
    Tuple *t1 = tuple_create("bar", "int");
    hashTable_insert(hashTable, utils_strcat("var", stack_top(s)), t1);
    
    printf("\nHashTable - Lookup\n\n");
    Tuple* t = hashTable_find(hashTable, utils_strcat("bar", stack_top(s)));

    if(t != NULL) {
        tuple_display(t);
    }else{
        printf("key: %s not found\n", utils_strcat("var", stack_top(s)));
    };
}