#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    char* name;
    char* type;
    struct Node *previous; 
    struct Node *next; 
};

bool nodeAreEquals(struct Node *node1, struct Node *node2) {
    return  (strcmp(node1->name, node2->name) == 0) && (strcmp(node1->type, node2->type) == 0);
}

void freeNode(struct Node *node) {
    free(node->name);
    free(node->type);
    free(node);
}

struct Node* createNode(char* name, char* type) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->name = (char*) malloc(strlen(name) * sizeof(char));
    node->type = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(node->name, name);
    strcpy(node->type, type);
    node->previous = NULL;
    node->next = NULL;
    return node;
}

bool insert(struct Node *root, struct Node *newNode) {
    struct Node *currentNode = root;

    while(true) {
        if(nodeAreEquals(currentNode, newNode)) {
            newNode->previous = currentNode->previous;
            newNode->next = currentNode->next;
            currentNode->previous->next = newNode;
            freeNode(currentNode);
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

bool removeNode(struct Node *root, struct Node *node) {
    struct Node *currentNode = root;
    
    while(true) {
        if(nodeAreEquals(currentNode, node)) {
            if(currentNode->previous != NULL)
                currentNode->previous->next = currentNode->next;
            if(currentNode->next != NULL) 
                currentNode->next->previous = currentNode->previous;
            freeNode(currentNode);
            return true;
        }else {
            if(currentNode->next == NULL) {
                return false;
            }else {
                currentNode = currentNode->next;
            }
        }
    };
}

struct Node* find(struct Node *root, struct Node *node) {
    struct Node *currentNode = root;
    
    while(true) {
        if(nodeAreEquals(currentNode, node)) {
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

void display(struct Node *root) {
    struct Node *currentNode = root;
    
    while(currentNode != NULL) {
        printf("%s\n", currentNode->name);
        printf("%s\n", currentNode->type);
        printf("---------------------\n");
        currentNode = currentNode->next;
    };
}

