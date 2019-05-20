#include "../include/registrador.h"

/**
 * construct da classe Resgistradores
 * incializa o contador de progrmas o o apontador de pilha
 */
Registradores::Registradores()
{
    registradores[6] = 0;
    registradores[7] = 0;
}
/**
 * construct da classe Resgistradores
 * incializa o contador de progrmas o o apontador de pilha e o RI.
 * @param mem, ponteiro para a memoria
 */
Registradores::Registradores(Memoria *mem)
{
    registradores[6] = 0;
    registradores[7] = 0;
    this->mem = mem;
    RI = mem->read(registradores[7]);
    for(auto i{0u}; i < 4;i++)
    {
        flags[i] = false;
    }
}

/**
 * Acessa e retorna o valor que esta no resgistrador do indice passado
 * @param indice do registrador
 * @return valor contido no registrador
 */
int Registradores::read(int index)
{
    return registradores[index];
}

/**
 * Escreve no registrador o valor passado
 * @param index, indice do registrador
 * @param valor, o valor a ser escrito
 */
void Registradores::write(int index, int valor)
{
    registradores[index] = valor;
}

/**
 *update_pc
 *atualiza o contador de programas com o endereco da proxima instrucao
 *@paran inc, valor do incremento
 */
void Registradores::inc_pc(int inc)
{
    registradores[7] += inc;
    RI = mem->read(registradores[7]); //ciclo de busca da instrucao "atalho"
}

/**
 * print_flags
 * exibi no terminal ou escreve em arquivo as flags de controle
 * @param mode, onde sera mostrado no terminal = 0 ou no arquivo = 1;
 */
void Registradores::print_registradores()
{
    std::cout << "PC:" << registradores[7] << std::endl;
    std::cout << "RI:" << RI << std::endl;
    std::cout << "N:" << flags[0] << " V:" << flags[1] << " C:" << flags[2] << " Z:" << flags[3] << std::endl;
    for(auto i{0u}; i < 8;i++)
    {
        std::cout << "R" << i << ":" << registradores[i] << " ";
    }
    std::cout << "\n";
}
