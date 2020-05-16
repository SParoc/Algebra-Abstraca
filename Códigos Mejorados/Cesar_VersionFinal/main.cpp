#include <iostream>
#include "Cesar.h"

int main()
{
  CifradoCesar cesar;
  string mensaje, mensajeCifrado;
  int opcion;

	cout << "\nCifrado Cesar: \n\n1. Cifrar mensaje\n2.Descrifrar mensaje\n\n";
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		cout << "\nIntroducir mensaje: ";
		getline(cin.ignore(), mensaje);
		cout<<"\nMensaje cifrado: "<<cesar.cifrarMensaje(mensaje);
		break;
	case 2:
		cout << "\nIntroducir mensaje: ";
		getline(cin.ignore(), mensajeCifrado);
		cout<<"\nMensaje descifrado: "<<cesar.descifrarMensaje(mensajeCifrado);
		break;
	default:
		break;
	}
}
