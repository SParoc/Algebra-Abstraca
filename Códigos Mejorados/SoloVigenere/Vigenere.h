#pragma once

#include <string>

using namespace std;

class Vigenere
{
public:
	Vigenere();
	string cipherText(string mensaje);
	string decipherText(string mensajeCifrado);
	string abc;

private:
	string clave;

};