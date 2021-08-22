#ifndef linkedList_file
#define linkedList_file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./tuple.h"

typedef struct Node
{
    char* key;
    struct Node *previous; 
    struct Node *next; 
    Tuple *tuple;
} Node;

bool linkedList_nodesHaveTheSameKey(Node *node1, Node *node2) {
    return strcmp(node1->key, node2->key) == 0;
}

void linkedList_freeNode(Node *node) {
    free(node->key);
    //tuple_freeTuple(node->tuple);
    free(node);
}

void linkedList_erroInvalidParam() {
    printf("Invalid Param\n");
    exit(EXIT_FAILURE);
}

Node* linkedList_createNode() {
    Node *node = (Node*) malloc(sizeof(Node));
    node->key = NULL;
    node->previous = NULL;
    node->next = NULL;
    node->tuple = NULL;
    return node;
}

Node* linkedList_insert(Node *root, Node *newNode) {
    if(newNode == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;
    
    if(root != NULL) {
        while(true) {
            if(linkedList_nodesHaveTheSameKey(currentNode, newNode)) {
                newNode->previous = currentNode->previous;
                newNode->next = currentNode->next;
                if(currentNode->previous != NULL)
                    currentNode->previous->next = newNode;
                
                if(currentNode->previous == NULL) {
                    linkedList_freeNode(currentNode);
                    return newNode;
                }else {
                    linkedList_freeNode(currentNode);
                    return root;
                }

            }else {
                if(currentNode->next == NULL) {
                    currentNode->next = newNode;
                    newNode->previous = currentNode;
                    return root;
                }else {
                    currentNode = currentNode->next;
                }
            }
        };
    }else {
        return newNode;
    }
}

Node* linkedList_remove(Node *root, Node *node) {
    if(root == NULL || node == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;
    Node *temp;
    
    while(true) {
        if(linkedList_nodesHaveTheSameKey(currentNode, node)) {
            if(currentNode->previous == NULL && currentNode->next != NULL){
                temp = currentNode->next;
                linkedList_freeNode(currentNode);
                return temp;
            }

            if(currentNode->previous == NULL && currentNode->next == NULL){
                linkedList_freeNode(currentNode);
                return NULL;
            }

            if(currentNode->previous != NULL )
                currentNode->previous->next = currentNode->next;

            if(currentNode->next != NULL) 
                currentNode->next->previous = currentNode->previous;

            linkedList_freeNode(currentNode);
            return root;
        }else {
            if(currentNode->next == NULL) {
                return root;
            }else {
                currentNode = currentNode->next;
            }
        }
    };
}

Node* linkedList_find(Node *root, Node *node) {
    if(root == NULL || node == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;
    
    while(true) {
        if(linkedList_nodesHaveTheSameKey(currentNode, node)) {
            return currentNode;
        }else {
            if(currentNode->next == NULL) {
                return NULL;
            }else {
                currentNode = currentNode->next;
            }
        }
    };
}

Node* linkedList_findByKey(Node *root, char* key) {
    if(root == NULL || key == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;
    
    while(true) {
        if(strcmp(currentNode->key, key) == 0) {
            return currentNode;
        }else {
            if(currentNode->next == NULL) {
                return NULL;
            }else {
                currentNode = currentNode->next;
            }
        }
    };
}

Node* linkedList_shift(Node *root) {
    if(root == NULL) linkedList_erroInvalidParam();
    Node *newRoot;

    if(root->next == NULL) {
        newRoot = NULL;
    }else {
        newRoot = root->next;
        newRoot->previous = NULL; 
    }

    linkedList_freeNode(root);
    return newRoot;
}

Node* linkedList_pop(Node *root) {
    if(root == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;

    if(root->next == NULL) {
        return NULL;
    }else {
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        currentNode->previous->next = NULL;
        linkedList_freeNode(currentNode);
        return root;
    }
}


void linkedList_display(Node *root) {
    Node *currentNode = root;
    
    if(root == NULL) {
        printf("Empty Linked list\n");
    }else {
        printf("=========-Display Linked list-=========\n");
    }
    while(currentNode != NULL) {
        if(currentNode->key != NULL) printf("%s\n", currentNode->key);
        if(currentNode->tuple != NULL) {
            if(currentNode->tuple->name != NULL) printf("%s\n", currentNode->tuple->name);
            if(currentNode->tuple->type != NULL) printf("%s\n", currentNode->tuple->type);
        }
        printf("--------------------\n");
        currentNode = currentNode->next;
    };
}

#endif