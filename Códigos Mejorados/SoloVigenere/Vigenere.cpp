#include "Vigenere.h"

Vigenere::Vigenere()
{
	abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
	clave = "AlgebraAbstracta";
}

string Vigenere::cipherText(string mensaje)
{
	string mensajeCifrado;
	int posM, posC, k = 0;

	for (int i = 0; i < mensaje.length(); i++)
	{
		posM = abc.find(mensaje[i]);
		posC = abc.find(clave[k]);
		k += 1;

		if (k >= clave.length())
		{
			k = 0;
		}

		posM += posC;

		if (posM >= abc.length())
		{
			posM = posM % abc.length();
		}
		
		mensajeCifrado += abc[posM];
	}
	return mensajeCifrado;
}

string Vigenere::decipherText(string mensajeCifrado)
{
	string mensaje;
	int posM, posC, k = 0;

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		posM = abc.find(mensajeCifrado[i]);
		posC = abc.find(clave[k]);
		k += 1;

		if (k >= clave.length())
		{
			k = 0;
		}

		posM -= posC;

		if (posM < 0)
		{
			posM = posM + abc.length();
		}

		mensaje += abc[posM];
	}
	return mensaje;
}
