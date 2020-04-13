#pragma once

#include <string>

class CifradoCesar
{
public:
	CifradoCesar();
	void cifrarMensaje();
	void descifrarMensaje();

private:
	std::string mensaje, mensajeCifrado, abc;
	int x, clave;
};
