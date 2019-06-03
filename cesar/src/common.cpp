#include "../include/common.h"
#include <sstream>

/**
 * stringTOint
 * converte string para inteiro
 * @param s, uma string
 */
int stringTOint(std::string s)
{
	int n;
	std::istringstream conversion(s);
    conversion >> n;
	return n;	
}