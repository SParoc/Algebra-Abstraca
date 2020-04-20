#include <iostream>
#include <string>

#include "Cesar.h"

using namespace std;

int main()
{
    CifradoCesar cesar;
	string mensaje, mensajeCifrado;
    int opcion, clave;

	cout << "\nCifrado Cesar: \n\n1. Cifrar mensaje\n2.Descrifrar mensaje\n\n";
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		getline(cin.ignore(), mensaje);
		cin >> clave;
		cout<<"\n"<<cesar.cifrarMensaje(mensaje, clave);
		break;
	case 2:
		getline(cin.ignore(), mensajeCifrado);
		cin >> clave;
		cout<<"\n"<<cesar.descifrarMensaje(mensajeCifrado, clave);
		break;
	default:
		break;
	}
}
