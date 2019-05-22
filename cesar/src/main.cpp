#include <iostream>
#include "../include/common.h"
#include "../include/registrador.h"
#include "../include/memoria.h"
#include "../include/ula.h"
#include "../include/PO.h"
#include "../include/PC.h"

int main(int argc, char *argv[])
{
    std::string enter;
    Opcode dic_codes;
    Memoria mem(dic_codes);
    mem.load_instructions(argv[1]);
    Registradores reg(&mem);
    Ula ula(&reg);
    PO po(&reg, &mem, &ula);
    PC pc(&po);

    //Escrevendo dados na memoria(memoria de dados 128 a 255)
    //Soma
    mem.write(133, 10);
    mem.write(134, 15);
    mem.write(135, 180); //Endereco da subrotina
    mem.write(180, 11);
    mem.write(181, 0);
    mem.write(182, 1);
    mem.write(183, 7);
    mem.write(184, 2); //Registrador de retorno
    //Maior valor em um vetor de 32 posicoes
    mem.write(128, 140);
    mem.write(129, 32);
    mem.write(130, 8);
    mem.write(131, -12);
    mem.write(132, -21);

    for(auto i{140u}; i < 173;i++)
    {
        mem.write(i, 1);
    }
    mem.write(150, 10);
    mem.write(167, 17);

    //Colocando subrotina de subtracao na memmoria
    //mem.write(30, 11);//SUB
    //mem.write(31, 0);//dest
    //mem.write(32, 1);//font
    //mem.write(33, 7);//RTS
    //mem.write(34, 2);//registrador de retorno.
   
    if(argc > 2) //Passo a passo
    {
        while(not pc.end_of_program())
        {
            getline(std::cin, enter);
            if(enter == "")
            {
                reg.print_registradores();
                pc.update_PE();
                pc.FS();
                //mem.print_memoria();
            }
        }
        std::cout << "\n";
        reg.print_registradores();
    }else //Executa tudo
    {
        reg.print_registradores();
        std::cout << "\n";
        while( not pc.end_of_program() )
        {
            pc.update_PE();
            pc.FS();
            reg.print_registradores();
            //mem.print_memoria();
            std::cout << "\n";
        }
    }
    
    

    return 0;
}