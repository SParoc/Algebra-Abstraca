#include "DecimoPrimer_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

DecimoPrimerEjercicio::DecimoPrimerEjercicio()
{
	str = "";
	str2 = "";
	abc = "abcdefghijklmnopqrstuvwxyz";
	i = a = b = x = y = 0;
}

void DecimoPrimerEjercicio::leerStrings()
{
	cout << "Introducir palabra (minusculas): "<<endl;
	cin >> str;
	cout << "Introducir otra palabra (minusculas): " << endl;
	cin >> str2;
}

void DecimoPrimerEjercicio::seleccionar()
{
	for (int i = 0; i < abc.length(); i++)
	{
		if (abc[i] == str[a])
		{
			x = i;
		}
		else if (abc[i] == str2[b])
		{
			y = i;
		}

		if (x != y) { break; };
		i = 0;
		a += 1;
		b += 1;
	}

	if (x < y)
	{
		cout << "\n\"" << str << "\" es lexicograficamente mayor ";
	}
	else if (y < x)
	{
		cout << "\n\"" << str2 << "\" es lexicograficamente mayor ";
	}
	else
	{
		cout << "Las palabras son iguales.";
	}
}
