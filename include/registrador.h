#ifndef REGISTRADOR_H
#define REGISTRADOR_H

#include <stack>
#include "../include/memoria.h"

class Registradores
{
    private:
        int registradores[8];
        short RI, REM, RDM; //Registrador de instrucao, Registradores de endereço de memoria e  Registrador de dados da memoria. 
        bool flags[4]; //Resgistrador de estado. Posicao 0 = negativo, 1 = overflow, 2 = carry e 3 = zero.
        Memoria *mem;
        std::stack<int> stack;
        short clock; //Armazena a qud. de ciclos de relogio o programa executou.
    public:
        Registradores();
        Registradores(Memoria *mem);
        int read(int index);
        void write(int index, int valor);
        void inc_pc(int inc);
        void print_registradores();
        short show_clock();
        friend class PO;
        friend class PC;
        friend class Ula;
};

#endif