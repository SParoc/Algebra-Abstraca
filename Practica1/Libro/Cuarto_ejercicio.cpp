#include "Cuarto_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

CuartoEjercicio::CuartoEjercicio()
{
	str = "";
	str2.assign(6, '*');
}

void CuartoEjercicio::leerString()
{
	do
	{
		cout << "Introducir un string (tamano par): \n";
		getline(cin, str);
	} while (str.length() % 2 != 0);
}

void CuartoEjercicio::separar()
{
	str.insert(str.length()/2, str2);
	cout << "\n\n" << str << endl;
}
