#include "Septimo_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

SeptimoEjercicio::SeptimoEjercicio()
{
	frase = ""; palabra = "";
	x = 0; y = 0;
}

void SeptimoEjercicio::leerStrings()
{
	cout << "Introducir frase: " << endl;
	getline(cin.ignore(), frase);

	cout << "\nIntroducir palabra para contar sus incidencias en la frase: " << endl;
	getline(cin, palabra);
}
void SeptimoEjercicio::contar()
{
	for (int i = 0; i < frase.length(); i++)
	{
		if (frase[i] == palabra[0])
		{
			for (int j = 0; j < palabra.length(); j++)
			{
				if (frase[i + j] == palabra[j])
				{
					y += 1;
					if (y == palabra.length())
					{
						x += 1;
						y = 0;
					}
				}
			}
		}
	}

	cout << "\n \"" << palabra << "\" se repite " << x << " veces.";
}
