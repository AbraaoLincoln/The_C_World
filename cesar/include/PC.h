#ifndef PC_H
#define PC_H

#include "../include/registrador.h"
#include "../include/memoria.h"
#include "../include/ula.h"
#include "../include/PO.h"

class PC
{
    private:
        PO *po;
        short AE;
    public:
        PC(PO *po);
        void FTE(); //Funcao de transferencia de estados.
        void FS(); //Funcao de saida.
        void update_PE(); //atualiza para o proximo estado(depende de qual instrucao vai ser executada)
        bool end_of_program(); //retorna true quando a instruca HLT e identificada.
};

#endif