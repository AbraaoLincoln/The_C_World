#ifndef PO_H
#define PO_H

#include "../include/registrador.h"
#include "../include/memoria.h"
#include "../include/ula.h"

class PO
{
    private:
        Registradores *regs;
        Memoria *mem;
        Ula *ula;
    public:
        PO(Registradores *regs, Memoria *mem, Ula *ula);
        short get_opcode();
        friend class PC;

};

#endif