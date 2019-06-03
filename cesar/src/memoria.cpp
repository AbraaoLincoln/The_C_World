#include "../include/common.h"
#include "../include/memoria.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * construct
 * @param referencia ao objeto do tipo Opcode que contem o dicionario de mnemonicos para codigo numerico.
 */
Memoria::Memoria(Opcode & dic)
{
    dic_opcode = dic;

    for(auto i{0u}; i < 256;i++){
        memoria[i] = 0;
    }
}
/**
 * read
 * acessa a memoria e retorna o valor contido nela
 * @param index, indice da memoria
 * @return valor contido na memoria
 */
int Memoria::read(int index)
{
    return memoria[index];
};

/**
 * write
 * escreve na memoria o valor passado
 * @param index, posicao da memoria
 * @param valor, valor a ser escrito;
 */
void Memoria::write(int index, int valor)
{
    memoria[index] = valor;
}

/**
 * load_instructions
 * copia as instrucoes do arquivo para a memoria
 * @param nome_do_arquivo, nome do arquivo onde estao as instrucoes
 */
void Memoria::load_instructions(std::string nome_do_arquivo)
{
    unsigned index{0};
    std::string instruction, substr;
    std::ifstream file;
    file.open(nome_do_arquivo);

    while(not file.eof())
    {
        getline(file, instruction);
        if(instruction.find(',') != std::string::npos) //verifica se a instrucao tem dois enderecos.
        {
            substr = instruction.substr(0, instruction.find(' ')); //decobre qual e a instrucao.
            memoria[index] = dic_opcode.mnemonicosTonumeric[substr];
            index++;
            if(substr != "MOV")
            {
                memoria[index] = dic_opcode.mnemonicosTonumeric[instruction.substr(instruction.find(' ')+1, instruction.find(',') - instruction.find(' ') -1)];
                index++;
                memoria[index] = dic_opcode.mnemonicosTonumeric[instruction.substr(instruction.find(',')+1)];
                index++;
            }else
            {
                substr = instruction.substr(instruction.find(' ')+1, instruction.find(',') - instruction.find(' ') -1);
                if(dic_opcode.mnemonicosTonumeric.count(substr) == 1)
                {
                    memoria[index] = dic_opcode.mnemonicosTonumeric[substr];
                    index++;
                }else
                {
                    memoria[index] = stringTOint(substr);
                    index++;
                }

                substr = instruction.substr(instruction.find(',')+1);

                if(dic_opcode.mnemonicosTonumeric.count(substr) == 1)
                {
                    if(substr.find('(') != std::string::npos)
                    {
                        if(substr.find('+') != std::string::npos)
                        {
                            memoria[index] = dic_opcode.mnemonicosTonumeric[substr] + 275; //275 = usando mode de enderecamento indireto com pos-incremento
                        }else if(substr.find('-') != std::string::npos)
                        {
                            memoria[index] = dic_opcode.mnemonicosTonumeric[substr] + 265; //265 = usando mode de enderecamento indireto com pre-decremento
                        }else
                        {
                            memoria[index] = dic_opcode.mnemonicosTonumeric[substr] + 256; //256 = usando mode de enderecamento indireto
                        }
                        
                    }else
                    {
                        memoria[index] = dic_opcode.mnemonicosTonumeric[substr];
                    }                    
                    index++;
                }else
                {
                    memoria[index] = stringTOint(substr);
                    index++;
                }
                
            }
            
        }else
        {
            memoria[index] = dic_opcode.mnemonicosTonumeric[instruction.substr(0, instruction.find(' '))];
            index++;
            memoria[index] = dic_opcode.mnemonicosTonumeric[instruction.substr(instruction.find(' ')+1)];
            index++;
        }
        
    }
}

/**
 * print_memoria
 * exibi no terminal o estado atual da memoria
 */
void Memoria::print_memoria()
{
    std::cout << "Memoria de Instruções:\n";
    for(auto i{0u}; i < 128; i++)
    {
        std::cout << memoria[i] << " ";
    }
    std::cout << "\n";

    
    std::cout << "Memoria de Dados:\n";
    for(auto i{128u}; i < 256; i++)
    {
        std::cout << memoria[i] << " ";
    }
    std::cout << "\n";
    
}

/**
 * edit_memory
 * edita a memoria antes da execucao da simulacao
 * @param index = posicao da memoria
 * @param valor =  valor a ser escrito na memoria
 */
void Memoria::edit_memory()
{
    std::string line;

    do
    {
        print_memoria();
        std::cout << "Deseja editar a memoria ? <se sim entre com a posicao e o valor separados por espaco e aperte enter, senao aperte enter>" << std::endl;
        getline(std::cin, line);

        if(line != ""){
            write(stringTOint(line.substr(0, line.find(" "))), stringTOint(line.substr(line.find(" ")+1)));
        }
    }while(line != "");

}