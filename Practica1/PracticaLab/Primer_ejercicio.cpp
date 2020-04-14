#include <iostream>
#include <string>
#include "Primer_ejercicio.h"

using namespace std;

PrimerYSegundoEjercicio::PrimerYSegundoEjercicio()
{
	str = "";
	str2 = "";
}

void PrimerYSegundoEjercicio::leerString()
{
	cout << "Introducir palabra o frase: " << endl;
	getline(cin, str);
	x = str.length();
}

void PrimerYSegundoEjercicio::StringACharArray()
{
	charArray = new char[x];

	cout << "\n\nArray de caracteres: \n";

	for (int i = 0; i < str.length(); i++)
	{
		charArray[i] = str[i];
		cout << charArray[i] << ", ";
	}
}

void PrimerYSegundoEjercicio::CharArrayAString()
{
	cout << "\n\nDe vuelta a String: \n";

	for (int j = 0; j < (sizeof(*charArray) * x); j++)
	{
		str2.push_back(charArray[j]);
	}
	cout << str2;
}

void PrimerYSegundoEjercicio::SegundoEjercicio()
{
	cout << "\nRespuesta: El metodo capacity muestra la capacidad maxima de elementos que puede tener un string,"
		<< " y se diferencia del metodo size porque este ultimo indica la cantidad de elementos que el string tiene,"
		<< " el numero de elementos de un string puede ser menor o igual que su capacidad, es por esto que si aplicamos"
		<< " los metodos size y capacity de un mismo string, pueden mostrar diferentes valores.\n";
}

PrimerYSegundoEjercicio::~PrimerYSegundoEjercicio()
{
	delete[] charArray;
}
