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
    HashTable *hashTable = hashTable_create(20);
    Node *n1;
    Node *n2;
    n1 = linkedList_createNode("foo", "string");
    hashTable->hashArray[0] = n1;
    printf("%s\n", hashTable->hashArray[0]->name);
    printf("%s\n", hashTable->hashArray[0]->type);
    n2 = linkedList_createNode("bar", "string");
    hashTable->hashArray[1] = n2;
    printf("%s\n", hashTable->hashArray[1]->name);
    printf("%s\n", hashTable->hashArray[1]->type);
    printf("%i\n", hashTable_hashKey("foo", hashTable->size));
    printf("%i\n", hashTable_hashKey("bar", hashTable->size));
    printf("%i\n", hashTable_hashKey("foo", hashTable->size));
    printf("%i\n", hashTable_hashKey("somaa", hashTable->size));
}