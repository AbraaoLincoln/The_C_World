#include <iostream>
#include "../include/common.h"
#include "../include/registrador.h"
#include "../include/memoria.h"
#include "../include/ula.h"
#include "../include/PO.h"
#include "../include/PC.h"

int main(int argc, char *argv[])
{
    Opcode dic_codes;
    Memoria mem(dic_codes);
    mem.load_instructions(argv[1]);
    Registradores reg(&mem);
    Ula ula(&reg);
    PO po(&reg, &mem, &ula);
    PC pc(&po);

    //Escrevendo dados na memoria(memoria de dados 128 a 255)
    mem.write(128, 129);
    mem.write(141, 10);
    mem.write(142, -6); //Endereco da subrotina de subtracao
    mem.write(143, 4);

    //Colocando subrotina de subtracao na memmoria
    //mem.write(30, 11);//SUB
    //mem.write(31, 0);//dest
    //mem.write(32, 1);//font
    //mem.write(33, 7);//RTS
    //mem.write(34, 2);//registrador de retorno.
   
    reg.print_registradores();
    while( not pc.end_of_program() )
    {
        //reg.print_registradores();
        pc.update_PE();
        pc.FS();
        reg.print_registradores();
        //mem.print_memoria();
    }
    

    return 0;
}