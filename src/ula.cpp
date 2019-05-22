#include <iostream>
#include "../include/common.h"
#include "../include/ula.h"
#include "../include/registrador.h"

/**
 * Construct
 * Passa o endereco dos registrador da PO para a Ula
 */
Ula::Ula(Registradores * reg) : m_reg{reg}
{}

/**
 * operation
 * Reazliza as operacoes da Ula
 *@param op, operacao a ser realizada
 *@param dest, registrador do onde esta o valor 1 e onde sra escrito o resultado
 *@param fonte, resgistrador onde esta o valor 2
 */
void Ula::operation(short op, int dest, int font)
{
    switch(op)
    {
        case 0: //escreve no registrador de destino o resultado da operacao anterior
            m_reg->write(dest, result);
            break;
        case 10: //Realiza a soma.
            std::cout << "ULA: SOMA\n";
            if(font == 8)
            {
                result = m_reg->read(dest) + 1;
            }else
            {
                result = m_reg->read(dest) + m_reg->read(font); 
            } 
            update_flags();
            break;
        case 11: //Realiza a subtracao.
            std::cout << "ULA: SUBTRACAO\n";
            if(font == 8)
            {
                result = m_reg->read(dest) - 1;
            }else
            {
                result = m_reg->read(dest) - m_reg->read(font);    
            }
            update_flags(); 
            break;
        case 13: //AND
            result = m_reg->read(dest) and m_reg->read(font);
            break;
        case 14: //OR
            m_reg->read(dest) or m_reg->read(font);
            break;
        default:
            break;
    }
}

/**
 * update_flags
 * atualiza as flags apos cada operacao realizada na ula.
 */
void Ula::update_flags()
{
    if(result < 0) //flag negativo(n)
    {
        m_reg->flags[0] = true;
    }else
    {
        m_reg->flags[0] = false;
    }
    

    if(result > 127 or result < -127) //flag overflow(v)
    {
        m_reg->flags[1] = true;
    }else
    {
        m_reg->flags[1] = false;
    }
    

    if(result > 127 or result < -127) //flag carry(c)
    {
        m_reg->flags[2] = true;
    }else
    {
        m_reg->flags[2] = false;
    }
    

    if(result == 0) //flag zero(z)
    {
        m_reg->flags[3] = true;
    }else
    {
        m_reg->flags[3] = false;
    }
    
}
