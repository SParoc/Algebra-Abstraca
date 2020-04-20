#include "Cesar.h"
#include <string>
#include <iostream>

using namespace std;

CifradoCesar::CifradoCesar()
{
	abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	x = 0;
}

string CifradoCesar::cifrarMensaje(string mensaje, int clave)
{
	for (int i = 0; i < mensaje.length(); i++)
	{
		x = abc.find(mensaje[i]);
		x += clave;
		mensaje[i] = abc[x];
	}
	return mensaje;
}

string CifradoCesar::descifrarMensaje(string mensajeCifrado, int clave)
{
	cout << "Introducir clave: " << endl;
	cin >> clave;

	cout << "Introducir mensaje para descifrarlo: \n";
	getline(cin.ignore(), mensajeCifrado);

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		x = abc.find(mensajeCifrado[i]);
		x -= clave;
		mensajeCifrado[i] = abc[x];
	}
	return mensajeCifrado;
}
