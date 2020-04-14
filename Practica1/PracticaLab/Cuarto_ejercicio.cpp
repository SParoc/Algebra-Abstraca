#include "Cuarto_ejercicio.h"
#include <iostream>
#include <string>

using namespace std;

CuartoYQuintoEjercicio::CuartoYQuintoEjercicio()
{
	nro1 = 0; nro2 = 0; numero = 0; str = "";
}

void CuartoYQuintoEjercicio::EnteroAString()
{
	cout << "Introducir primer numero: ";
	cin >> nro1;
	cout << "Introducir segundo numero: ";
	cin >> nro2;

	str = to_string(nro1) + to_string(nro2);
	cout << "\n" << str;
}

void CuartoYQuintoEjercicio::StringAEntero()
{
	numero = stoi(str);
}

void CuartoYQuintoEjercicio::Duplicar()
{
	numero *= 2;
	cout << "\n" << numero << endl;
}

void CuartoYQuintoEjercicio::QuintoEjercicio()
{
	//Crear objeto string formado por 1000 "a"s (1 linea)
	string str5(1000, 'a');

	cout <<"\n"<< str5;
}
