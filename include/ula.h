#ifndef ULA_H
#define ULA_H

#include "../include/registrador.h"
#include "../include/common.h"

class Ula
{
    private:
        Registradores *m_reg;
        short result;
    public:
        Ula(Registradores * reg);
        void operation(short op, int dest, int font=0);
        void update_flags();
};

#endif