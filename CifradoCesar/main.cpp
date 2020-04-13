
#include <iostream>
#include <string>

#include "Cesar.h"

using namespace std;

int main()
{
    CifradoCesar cesar;
    int opcion = 0;

	cout << "\nCifrado Cesar: \n\n1. Cifrar mensaje\n2.Descrifrar mensaje\n\n";
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		cesar.cifrarMensaje();
		break;
	case 2:
		cesar.descifrarMensaje();
		break;
	default:
		break;
	}
}
