#include "../include/PC.h"

/**
 * construct da classe PC
 * inicializa o estado atual com 1, se a primeira operacao for o MOV
 */
PC::PC(PO *po)
{
    this->po = po;
    AE = 1;
}

/**
 * FTE
 * funcao de transferencia de estados, gera o proximo estado da instrucao sendo executada
 * @param AE, estado atual
 */
void PC::FTE()
{
    switch(AE)
    {
        case 2:
            AE = 3;
            break;
        case 4:
            AE = 3;
            break;
        case 6:
            AE = 3;
            break;
        case 7:
            AE = 3;
            break;
        case 13:
            AE = 3;
            break;
        case 14:
            AE = 3;
            break;
        case 19:
            AE = 10;
            break;
        case 20:
            AE = 10;
            break;
        case 21:
            AE = 10;
            break;
        case 22:
            AE = 10;
            break;
        case 23:
            AE = 10;
            break;
        case 24:
            AE = 10;
            break;
        case 25:
            AE = 10;
            break;
        case 26:
            AE = 10;
            break;
        case 27:
            AE = 10;
            break;
        case 28:
            AE = 10;
            break;
        case 29:
            AE = 10;
            break;
        case 30:
            AE = 10;
            break;
        case 31:
            AE = 10;
            break;
        case 32:
            AE = 10;
            break;
    }
}

/**
 * FS
 * informa para a PO qual operacao realizar
 * @param AE, estado atual
 */
void PC::FS()
{
    switch(AE)
    {
        case 1:// MOV
            if(po->mem->memoria[po->regs->read(7) + 2] > 255)
            {
                po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(po->mem->memoria[po->regs->read(7) + 2] - 256)]);
                po->regs->inc_pc(3);
            }else
            {
                //dados da memoria para o registrador(memoria >> registrador)
                po->regs->REM = po->mem->memoria[po->regs->read(7) + 2]; //endereco de memoria onde esta o dado a ser lido salvo no reg. no REM
                po->regs->RDM = po->mem->read(po->regs->REM); //escreve o dado que esta na posicao de memoria que REM aponta no RDM
                po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->regs->RDM); //escreve no registrador indicado o valor que esta na memoria de dados
                po->regs->inc_pc(3); //Incrementa o contador de programa para a proxima instrucao na memoria
            }
            
            break;
        case 2: //ADD
            po->ula->operation(10, po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(7) + 2]);
            FTE();
            FS();
            po->regs->inc_pc(3);
            break;
        case 3: //Escrita do resultado da ULA no resgistrador.
            po->ula->operation(0, po->mem->memoria[po->regs->read(7) + 1]); //escreve o resultado da ULA no regirstrador determinado
            break;
        case 4:// SUB
            po->ula->operation(11, po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(7) + 2]);
            FTE();
            FS();
            po->regs->inc_pc(3);
            break;
        case 5: //CMP
            po->ula->operation(11, po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(7) + 2]);
            po->regs->inc_pc(3);
            break;
        case 6: // AND
            po->ula->operation(13, po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(7) + 2]);
            FTE();
            FS();
            po->regs->inc_pc(3);
            break;
        case 7: // OR
            po->ula->operation(14, po->mem->memoria[po->regs->read(7) + 1], po->mem->memoria[po->regs->read(7) + 2]);
            FTE();
            FS();
            po->regs->inc_pc(3);
            break;
        case 8: //JSR
            po->regs->write(6, po->regs->read(po->mem->memoria[po->regs->read(7) + 2])); //Coloca o endereco da subrotina no R6
            po->regs->stack.push(po->regs->read(po->mem->memoria[po->regs->read(7) + 1])); //Salva o conteudo do registrador de retorna na pilha
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->regs->read(7)); //Salva o valor do contador de programa atual no registrador de retorno
            po->regs->write(7, po->regs->read(6)); //Coloca o endereco da subrotina no PC
            po->regs->RI = po->mem->memoria[po->regs->read(7)];
            update_PE();
            FS();
            break;
        case 9: //RTS
            po->regs->write(7, po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->write(po->regs->read(po->mem->memoria[po->regs->read(7) + 1]), po->regs->stack.top());
            po->regs->stack.pop();
            po->regs->inc_pc(3);
            break;
        case 10: //BR
            po->regs->inc_pc(po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            break;
        case 11: //CLS  =============TODO===================
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], 0);
            po->regs->inc_pc(2);
            break;
        case 12: //NOT
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], not po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->inc_pc(2);
            break;
        case 13: //INC
            po->ula->operation(10, po->mem->memoria[po->regs->read(7) + 1], 8);
            FTE();
            FS();
            po->regs->inc_pc(2);
            break;
        case 14: //DEC
            po->ula->operation(11, po->mem->memoria[po->regs->read(7) + 1], 8);
            FTE();
            FS();
            po->regs->inc_pc(2);
            break;
        case 15: //NEG
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], -1 * po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->inc_pc(2);
            break;
        case 16: // TST
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->inc_pc(2);
            break;
        case 17: //ADC
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->inc_pc(2);
            break;
        case 18: //SBC
            po->regs->write(po->mem->memoria[po->regs->read(7) + 1], po->regs->read(po->mem->memoria[po->regs->read(7) + 1]));
            po->regs->inc_pc(2);
            break;
        case 19: //BNE
            if(po->regs->flags[3] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }       
            break;
        case 20: //BEQ
            if(po->regs->flags[3] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 21: //BPL
            if(po->regs->flags[0] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 22: //BMI
            if(po->regs->flags[0] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 23: //BVC
            if(po->regs->flags[1] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 24: //BVS
            if(po->regs->flags[1] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 25: //BCC
            if(po->regs->flags[2] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 26: //BCS
            if(po->regs->flags[2] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 27: //BGE
            if(po->regs->flags[0] == po->regs->flags[1])
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 28: //BLT
            if(po->regs->flags[0] < po->regs->flags[1])
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 29: //BGT
            if(po->regs->flags[0] == po->regs->flags[1] and po->regs->flags[3] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 30: //BLE 
            if(po->regs->flags[0] != po->regs->flags[1] and po->regs->flags[3] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 31: //BHI
            if(po->regs->flags[2] == 0 and po->regs->flags[3] == 0)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
        case 32: //BLS
            if(po->regs->flags[2] == 1 or po->regs->flags[3] == 1)
            {
                FTE();
                FS();
            }else
            {
                po->regs->inc_pc(2);
            }
            break;
    }
}

/**
 * update_PE
 * atualiza o estado atual para o proximo estado da nova instrucao que sera executada
 */
void PC::update_PE()
{
    switch(po->regs->RI)
    {
        case 9: //Instrucao MOV
            AE = 1; //estado inicial do MOV
            break;
        case 10: //Instrucao ADD
            AE = 2; //estado inicial da soma
            break;
        case 11: //Instrucao SUB
            AE = 4; //Estado incial do subtracao
            break;
        case 12: //Instrucao CMP
            AE = 5; //Estado incial do da comparacao
            break;
        case 13: //Instrucao AND
            AE = 6; //Estado inicial do AND
            break;
        case 14: //Instrucao OR
            AE = 7; //Estado inicial do OR
            break;
        case 6://Instrucao JSR
            AE = 8; //Estado inicial do JSR
            break;
        case 7: //Instrucao RTS
            AE = 9; //Estado incial do RTS
            break;
        case 48: //Instrucao BR
            AE = 10; //Estado incial do BR(jump incodicional)
            break;
        case 49: //Instrucao BNE
            AE = 19;
            break;
        case 50: //Instrucao BEQ
            AE = 20;
            break;
        case 51: //Instrucao BPL
            AE = 21;
            break;
        case 52: //Instrucao BMI
            AE = 22;
            break;
        case 53: //Instrucao BVC
            AE = 23;
            break;
        case 54: //Instrucao BVS
            AE = 24;
            break;
        case 55: //Instrucao BCC
            AE = 25;
            break;
        case 56: //Instrucao BCS
            AE = 26;
            break;
        case 57: //Instrucao BGE
            AE = 27;
            break;
        case 58: //Instrucao BLT
            AE = 28;
            break;
        case 59: //Instrucao BGT
            AE = 29;
            break;
        case 60: //Instrucao BLE
            AE = 30;
            break;
        case 61: //Instrucao BHI
            AE = 31;
            break;
        case 62: //Instrucao BLS
            AE = 32;
            break;
        case 128: //Instrucao CLS
            AE = 11;
            break;
        case 129: //Instrucao NOT
            AE = 12;
            break;
        case 130: //Instrucao INC
            AE = 13;
            break;
        case 131: //Instrucao DEC
            AE = 14;
            break;
        case 132: //Instrucao NEG
            AE = 15;
            break;
        case 133: //Instrucao TST
            AE = 16;
            break;
        case 138: //Instrucao ADC
            AE = 17;
            break;
        case 139: //Instrucao SBC
            AE = 18;
            break;
    }
}

/**
 * end_of_program
 * verifica se o programa chegou ao fim
 * @return true, se o o pragrama chegou ao fim, false caso contrario
 */
bool PC::end_of_program()
{
    return po->regs->RI == 15;
}