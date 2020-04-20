#pragma once

#include <string>

using namespace std;

class CifradoCesar
{
public:
	CifradoCesar();
	string cifrarMensaje(string mensaje, int clave);
	string descifrarMensaje(string mensajeCifrado, int clave);
	string abc;

private:
	int x;
};
