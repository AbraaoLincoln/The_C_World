#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tuple.h"
#include "./hashTable.h"
#include "./stack.h"
#include "./utils.h"

int main(void) {
    char *top;
    char *bar = (char*) malloc(3 * sizeof(char));
    strcpy(bar, "bar");

    printf("\nTuple - Criar\n\n");
    /* ======================= TUPLE ======================= */
    /*
        A struct Tuple é usada para armazenar informações importantes para a analise, no momento
        as informações que podem ser armazendas são: nome e tipo respectivamente.
    */

    /* Criando uma Tuple*/
    Tuple *tuple = tuple_create("nome", "tipo");
    tuple_display(tuple);

    /* ======================= HashTable ======================= */
    /*
        A struct HashTable é usada para armazenar as Tuple criadas, para cada Tuple é associado uma
        chave do tipo String.
    */

    /* Criando uma HashTable*/
    //o valor passado como parametro para a função hashTable_create é o tamanho do array.
    HashTable *hashTable = hashTable_create(10);
    hashTable_display(hashTable);

    printf("\nHashTable - Adicionar\n\n");
    /* Adicionando Elemento a HashTable*/
    /*
        1 - O primeiro parametro passado para a funcao hashTable_insert é a referencia para a hashTale 
        na qual o elemento vai ser adicionado. 

        2 - O segundo parametro é a chave que será associada a Tuple, essa chave pode ser uma string 
        literal ou a referencia para o primeiro caracter da string(char*).

        3 - O terceiro parametro é a referencia para a Tuple que contém as informações.
    
    */
    hashTable_insert(hashTable, "foo", tuple);
    hashTable_insert(hashTable, bar, tuple);
    hashTable_display(hashTable);

    printf("\nHashTable - Buscar\n\n");
    /* Buscando Elemento na HashTable*/
    /*
        1 - O primeiro parametro passado para a funcao hashTable_find é a referencia para a hashTale 
        na qual a busca será feita. 

        2 - O segundo parametro é a chave da Tuple, essa chave pode ser uma string 
        literal ou a referencia para o primeiro caracter da string(char*).

        return: retorna a referencia para a tuple se escontrada, caso contrario retorna NULL.
    
    */
    Tuple *resultado = hashTable_find(hashTable, "foo");
    if(resultado != NULL) tuple_display(resultado);
    resultado = hashTable_find(hashTable, bar);
    if(resultado != NULL) tuple_display(resultado);

    printf("\nHashTable - Remove\n\n");
    /* Removendo Elemento da HashTable*/
    /*
        1 - O primeiro parametro passado para a funcao hashTable_remove é a referencia para a hashTale 
        ao qual o elemento vai ser removido. 

        2 - O segundo parametro é a chave da Tuple que será removida, essa chave pode ser uma string 
        literal ou a referencia para o primeiro caracter da string(char*).
    
    */
    hashTable_remove(hashTable, "foo");
    hashTable_display(hashTable);
    hashTable_remove(hashTable, bar);
    hashTable_display(hashTable);

    printf("\nStack - Criar\n\n");
    /* ======================= STACK ======================= */
    /*
        A struct Stack é usada para armazenar um conjunto de strings.
    */

    /* Criando uma Stack*/
    //Para criar uma stack usar a função stack_create é retornado a referencia da stack criada.
    Stack *stack = stack_create();
    stack_display(stack);

    printf("\nStack - Adicionar\n\n");
    /* Adiconando String no topo da stack*/
    /*
        1 - O primeiro parametro passado para a funcao stack_push é a referencia para a stack 
        ao qual a string será colocada no topo. 

        2 - O segundo parametro é a string que será adicionada, essa string pode ser  
        literal ou a referencia para o primeiro caracter da string(char*).
    
    */
    stack_push(stack, "foo");
    stack_push(stack, bar);
    stack_push(stack, "foobar");
    stack_display(stack);

    printf("\nStack - Top\n\n");
    /* Buscar String no topo da stack*/
    /*
        1 - O parametro passado para a funcao stack_top é a referencia para a stack 
        na qual a busca será feita. 

        return: é retornado a referencia para a string que esta no topo da stack, se a stack estiver
        vazia sera retornado NULL.
    */
   printf("Top da stack\n");
    top = stack_top(stack);
    if(top != NULL) printf("%s\n", top);
    
    /* Buscar String na stack por indice*/
    /*
        1 - O primeiro parametro passado para a funcao stack_topByIndex é a referencia para a stack 
        na qual a busca será feita. 

        2 - O segundo parametro é o indice o qual será considerado como o topo da stack.

        return: é retornado a referencia para a string que esta no indice, se a stack estiver
        vazia ou o indice é invalido, sera retornado NULL.
    */
    printf("\nTop da stack por indice(0)\n");
    top = stack_topByIndex(stack, 0);
    if(top != NULL) printf("%s\n", top);

    printf("\nStack - Pop\n\n");
    /* Removendo String do topo da stack*/
    /*
        1 - O parametro passado para a funcao stack_pop é a referencia para a stack 
        na qual a string no topo será removida. 
    */
    stack_pop(stack);
    stack_display(stack);
}