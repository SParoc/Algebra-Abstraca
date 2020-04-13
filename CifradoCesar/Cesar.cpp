#include "Cesar.h"
#include <string>
#include <iostream>

using namespace std;

CifradoCesar::CifradoCesar()
{
	mensaje = "";
	mensajeCifrado = "";
	abc = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	x = 0;
	clave = 0;
}

void CifradoCesar::cifrarMensaje()
{
	cout << "Introducir clave: "<<endl;
	cin >> clave;
	cout << "Introducir mensaje para cifrarlo: \n";
	getline(cin.ignore(), mensaje);

	for (int i = 0; i < mensaje.length(); i++)
	{
		x = abc.find(mensaje[i]);
		x += clave*2;
		if (x >= 52)
		{
			x = x % 52;
		}
		if (mensaje[i] != ' ')
		{
			mensaje[i] = abc[x];
		}
	}
	cout << "\nEl mensaje cifrado es: \n" << mensaje;
}

void CifradoCesar::descifrarMensaje()
{
	cout << "Introducir clave: " << endl;
	cin >> clave;

	cout << "Introducir mensaje para descifrarlo: \n";
	getline(cin.ignore(), mensajeCifrado);

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		x = abc.find(mensajeCifrado[i]);
		x -= clave*2;

		if (x < 0)
		{
			x = 52 + x;
		}
		if (mensajeCifrado[i] != ' ')
		{
			mensajeCifrado[i] = abc[x];
		}
	}
	cout << "\nEl mensaje descifrado es: \n" << mensajeCifrado;
}
