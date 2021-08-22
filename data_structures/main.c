#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedList.h"
#include "./hashTable.h"

void testLinkedList();
void testHashTable();

int main(void) {
    //testLinkedList();
    testHashTable();
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
    // hashTable_display(hashTable);

    //remove
    // printf("\nRemove\n\n");
    // hashTable_remove(hashTable, "var2");
    // hashTable_remove(hashTable, "var11");
    // hashTable_display(hashTable);

    //find
    printf("\nFind\n\n");
    Tuple* t = hashTable_find(hashTable, "var");

    if(t != NULL) {
        tuple_display(t);
    };

    t = hashTable_find(hashTable, "bar");

    if(t != NULL) {
        tuple_display(t);
    };

    t = hashTable_find(hashTable, "var2");

    if(t != NULL) {
        tuple_display(t);
    };

}