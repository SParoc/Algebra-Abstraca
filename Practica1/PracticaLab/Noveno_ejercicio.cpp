#include "Noveno_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

NovenoEjercicio::NovenoEjercicio()
{
	str = ""; str2 = "";
}

void NovenoEjercicio::leerStrings()
{
	do
	{
		cout << "Introducir primera string (debe tener tamaño par): " << endl;
		getline(cin, str);

	} while (str.length() % 2 != 0);
	
	cout << "Introducir segunda string: " << endl;
	getline(cin, str2);
}

void NovenoEjercicio::fusionarStrings()
{
	str.insert((str.length() / 2), str2);
	cout << "\nNueva string: " << str;
}
