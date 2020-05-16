#include "Cesar.h"

CifradoCesar::CifradoCesar()
{
	abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	clave = 13;
}

string CifradoCesar::cifrarMensaje(string mensaje)
{
	string mensajeCifrado;
	int pos;

	for (int i = 0; i < mensaje.length(); i++)
	{
		pos = abc.find(mensaje[i]) + clave;
		if (pos >= abc.length())
		{
			pos = pos % abc.length();
		}
		mensajeCifrado += abc[pos];
	}
	return mensajeCifrado;
}

string CifradoCesar::descifrarMensaje(string mensajeCifrado)
{
	string mensajeDescifrado;
	int pos;

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		pos = abc.find(mensajeCifrado[i]) - clave;
		if (pos < 0)
		{
			pos = abc.length() + pos;
		}
		mensajeDescifrado += abc[pos];
	}
	return mensajeDescifrado;
}
