#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include "../include/common.h"

class Memoria
{
    private:
        int memoria[256]; //posicao 0 a 127 memoria de instrucao, 128 a 255 memoria de dados.
        Opcode dic_opcode;
    public:
        Memoria(Opcode & dic_opcode);
        void write(int index, int valor);
        int read(int index);
        void load_instructions(std::string nome_do_arquivo);
        void print_memoria();
        void edit_memory();
        friend class PO;
        friend class PC;
};

#endif