#include "Tercer_ejercicio.h"
#include <iostream>
#include <string>

using namespace std;

TercerEjercicio::TercerEjercicio()
{
	str = "";
}

void TercerEjercicio::leerString()
{
	cout << "Ingresar palabra o frase (en minusculas): ";
	getline(cin, str);
}

void TercerEjercicio::minusculasAMayusculas()
{
	cout << "\n\nString en mayusculas: \n";

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}

	cout << str;
}

void TercerEjercicio::mayusculasAMinusculas()
{
	cout << "\n\nDe vuelta a minusculas: \n";

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}

	cout << str;
}
