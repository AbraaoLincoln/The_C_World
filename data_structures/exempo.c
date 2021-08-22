#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tuple.h"
#include "./hashTable.h"
#include "./stack.h"
#include "./utils.h"

int main(void) {
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

    printf("\nTuple - Criar\n\n");
    /* ======================= TUPLE ======================= */
    /*
        A struct Tuple é usada para armazenar informações importantes para a analise, no momento
        as informações que podem ser armazendas são: nome e tipo respectivamente.
    */
}