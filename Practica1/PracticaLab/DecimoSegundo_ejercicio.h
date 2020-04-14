#pragma once

#include <string>
#include <fstream>

class DecimoSegundo
{
public:
	DecimoSegundo();
	void ingresarNumeros();
	void operar();


private:
	std::ofstream outNumeros;
	std::ifstream inNumeros;
	std::string numerosArray[10];
	int N, x, y, suma;
};

