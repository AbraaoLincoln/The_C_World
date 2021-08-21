#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PRIME 31

typedef struct HashTable
{
    int size;
    struct Node **hashArray;
} HashTable;

HashTable* hashTable_create(int size) {
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));;
    hashTable->size = size;
    hashTable->hashArray = (Node**) malloc(size * sizeof(*hashTable->hashArray));

    return hashTable;
}

int hashTable_hashKey(char *key, int hashTableSize) {
    int hash = 0;

    for(int i = 0; i < strlen(key); i++) {
        hash = (PRIME * hash + key[i]) % hashTableSize;
    }

    return hash;
}

void hashTable_insert(struct HashTable* hashTable, char* key, struct Node *node) {

}
