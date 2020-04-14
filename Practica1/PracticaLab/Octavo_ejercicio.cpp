#include "Octavo_ejercicio.h"
#include <iostream>
#include <string>

using namespace std;

OctavoEjercicio::OctavoEjercicio()
{
	str = "";
}

void OctavoEjercicio::leerString()
{
	cout << "Introducir palabra o frase: \n";
	getline(cin, str);
}

void OctavoEjercicio::imprimirString()
{
  
    string::iterator i;

    for (i = str.begin(); i != str.end(); i++)
    {
        cout << *i << '\n';
    }
}
