#include "Quinto_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

QuintoEjercicio::QuintoEjercicio()
{
	str = "";
	x = 0;
}

void QuintoEjercicio::leerString()
{
	cout << "Introducir frase: \n";
	getline(cin, str);
}

void QuintoEjercicio::reemplazar()
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!(isalpha(str[i])))
		{
			str[i] = ' ';
		}
	}
}

void QuintoEjercicio::tokens()
{
	do
	{
		x = str.find(' ');
		cout << str.substr(0, x) << endl;
		str.erase(0, x+1);

	} while (x != -1);
}
