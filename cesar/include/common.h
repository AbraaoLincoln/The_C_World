#ifndef COMMON_H
#define COMMON_H

#include <map>

/**
 * struct Opcode 
 * Dicionario que contem os mnemonicos e os respectivos codigos numericos.
 */
struct Opcode
{
    std::map<std::string, int> mnemonicosTonumeric{
        {"MOV", 9}, //Operacao com dois enderecos
        {"ADD", 10},
        {"SUB", 11},
        {"CMP", 12},
        {"AND", 13},
        {"OR", 14}, //============================
        {"R0", 0},//Registradores
        {"R1", 1},
        {"R2", 2},
        {"R3", 3},
        {"R4", 4},
        {"R5", 5},
        {"R6", 6},
        {"R7", 7},
        {"(R0)", 0}, //Modo indexado
        {"(R1)", 1},
        {"(R2)", 2},
        {"(R3)", 3},
        {"(R4)", 4},
        {"(R5)", 5},
        {"(R6)", 6},
        {"(R7)", 7}, //============================
        {"CLR", 128}, //Operacoes com apenas um endereco
        {"NOT", 129},
        {"INC", 130},
        {"DEC", 131},
        {"NEG", 132},
        {"TST", 133},
        {"ADC", 138},
        {"SBC", 139},
        {"HLT", 15}, //Encerra o programa
        {"BR", 48},//Instrucoes de salta
        {"BNE", 49},
        {"BEQ", 50},
        {"BPL", 51},
        {"BMI", 52},
        {"BVC", 53},
        {"BVS", 54},
        {"BCC", 55},
        {"BCS", 56},
        {"BGE", 57},
        {"BLT", 58},
        {"BGT", 59},
        {"BLE", 60},
        {"BHI", 61},
        {"BLS", 62},
        {"JSR", 6}, //Instrucao de subrotina(pula para a subrotina)
        {"RTS", 7} ////Instrucao de subrotina(volta para onde a subrotina foi chamada)
    };

};

/**
 * stringTOint
 * converte string para inteiro
 * @param s, uma string
 */
int stringTOint(std::string s);

#endif