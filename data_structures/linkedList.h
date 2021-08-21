#ifndef linkedList_file
#define linkedList_file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    char* name;
    char* type;
    char* key;
    struct Node *previous; 
    struct Node *next; 
} Node;

bool linkedList_nodeAreEquals(Node *node1, Node *node2) {
    return (strcmp(node1->key, node2->key) == 0) && (strcmp(node1->name, node2->name) == 0) && (strcmp(node1->type, node2->type) == 0);
}

bool linkedList_nodesHaveTheSameKey(Node *node1, Node *node2) {
    return strcmp(node1->key, node2->key) == 0;
}

void linkedList_freeNode(Node *node) {
    free(node->name);
    free(node->type);
    free(node->key);
    free(node);
}

void linkedList_erroInvalidParam() {
    printf("Invalid Param\n");
    exit(EXIT_FAILURE);
}

Node* linkedList_createNode(char* name, char* type) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->name = (char*) malloc(strlen(name) * sizeof(char));
    node->type = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(node->name, name);
    strcpy(node->type, type);
    node->previous = NULL;
    node->next = NULL;
    return node;
}

bool linkedList_insert(Node *root, Node *newNode) {
    if(root == NULL || newNode == NULL) linkedList_erroInvalidParam();
    Node *currentNode = root;

    while(true) {
        if(linkedList_nodesHaveTheSameKey(currentNode, newNode)) {
            newNode->previous = currentNode->previous;
            newNode->next = currentNode->next;
            currentNode->previous->next = newNode;
            linkedList_freeNode(currentNode);
            return true;
        }else {
            if(currentNode->next == NULL) {
                currentNode->next = newNode;
                newNode->previous = currentNode;
                return true;
            }else {
                currentNode = currentNode->next;
            }
        }
    };

    return false;
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
    
    if(root == NULL) printf("Empty Linked list\n");

    while(currentNode != NULL) {
        printf("%s\n", currentNode->name);
        printf("%s\n", currentNode->type);
        printf("---------------------\n");
        currentNode = currentNode->next;
    };
}

#endif