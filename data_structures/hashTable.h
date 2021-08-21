#ifndef HashTable_File
#define HashTable_File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./linkedList.h"

#define PRIME 31

typedef struct HashTable
{
    int size;
    Node **hashArray;
} HashTable;

void setHashTableToNull(HashTable* hashTable) {
    for(int i = 0; i < hashTable->size; i++) {
        hashTable->hashArray[i] = NULL;
    }
}

HashTable* hashTable_create(int size) {
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->hashArray = (Node**) malloc(size * sizeof(*hashTable->hashArray));
    setHashTableToNull(hashTable);
    return hashTable;
}

int hashTable_hashKey(char *key, int hashTableSize) {
    int hash = 0;

    for(int i = 0; i < strlen(key); i++) {
        hash = (PRIME * hash + key[i]) % hashTableSize;
    }

    return hash;
}

void hashTable_insert(HashTable* hashTable, char* key, Tuple *tuple) {
    int hashKey = hashTable_hashKey(key, hashTable->size);
    Node *node = linkedList_createNode();
    node->key = (char*) malloc(strlen(key) * sizeof(char));
    strcpy(node->key, key);
    node->tupla = tuple;
    
    if(hashTable->hashArray[hashKey] == NULL) {
        hashTable->hashArray[hashKey] = node;
    }else {
        hashTable->hashArray[hashKey] = linkedList_insert(hashTable->hashArray[hashKey], node);
    }
}

void hashTable_remove(HashTable* hashTable, char* key) {
    int hashKey = hashTable_hashKey(key, hashTable->size);

    if(hashTable->hashArray[hashKey] != NULL) {
        Node* node = linkedList_findByKey(hashTable->hashArray[hashKey], key);

        if(node != NULL) 
            hashTable->hashArray[hashKey] = linkedList_remove(hashTable->hashArray[hashKey], node);
    }
}

Tuple* hashTable_find(HashTable* hashTable, char* key) {
    int hashKey = hashTable_hashKey(key, hashTable->size);
    Node* node = linkedList_findByKey(hashTable->hashArray[hashKey], key);
    return node->tupla;
}

void hashTable_display(HashTable* hashTable) {
    printf("=========-Display HashTable-=========\n");
    for(int i = 0; i < hashTable->size; i++) {
        if(hashTable->hashArray[i] != NULL) linkedList_display(hashTable->hashArray[i]);
        //printf("====================\n");
    }
}

#endif