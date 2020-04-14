#include "Sexto_ejercicio.h"

#include <string>
#include <iostream>

using namespace std;

SextoEjercicio::SextoEjercicio()
{
	str = "";
}

void SextoEjercicio::leerString()
{
	cout << "Introducir string: \n";
	getline(cin, str);
}

void SextoEjercicio::voltear()
{
	str2.assign(str.rbegin(), str.rend());
	cout << "String al reves:\n" << str2;
}
