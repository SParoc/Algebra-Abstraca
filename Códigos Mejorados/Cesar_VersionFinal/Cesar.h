#pragma once

#include <string>

using namespace std;

class CifradoCesar
{
public:
	CifradoCesar();
	string cifrarMensaje(string mensaje);
	string descifrarMensaje(string mensajeCifrado);
	string abc;

private:
	int clave;
};
