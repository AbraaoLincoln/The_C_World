#include "../include/PO.h"

/**
 * construct da clase PO
 * incializa os registradores, memoria e a ula
 * @param *regs, ponterio para um objeto do tipo Registradores
 * @param *mem, ponterio para um objeto do tipo Memoria
 * @param *ula, ponterio para um objeto do tipo Ula
 */
PO::PO(Registradores *regs, Memoria *mem, Ula *ula)
{
    this->regs = regs;
    this->mem = mem;
    this->ula = ula;
};

/**
 * get_opcode
 * @return, retorna o codigo da operacao atual
 */
short PO::get_opcode()
{
    return regs->RI;
}