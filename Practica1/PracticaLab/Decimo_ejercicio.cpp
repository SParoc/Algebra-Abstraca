#include "Decimo_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

DecimoEjercicio::DecimoEjercicio()
{
	c = 0;
	str = "";
}

void DecimoEjercicio::leerStrings()
{
	cout << "Introducir frase: " << endl;
	getline(cin, str);
	cout << "Introducir una palabra de la frase: " << endl;
	getline(cin, str2);
	cout << "Introducir otra palabra: " << endl;
	getline(cin, str3);
}

void DecimoEjercicio::reemplazar()
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == str2[0])
		{
			for (int j = 0; j < str2.length(); j++)
			{
				if (str[i + j] == str2[j])
				{
					c += 1;
					if (c == str2.length())
					{
						str.replace(i , str2.length() , str3);
						c = 0;
					}
				}
			}
			c = 0;
		}
	}
	
	cout << "\nFrase cambiada: " << str;
}
