#include "Tercer_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

TercerEjercicio::TercerEjercicio()
{
	palabra = "computacion"; //puede cambiarse a cualquiera e igual funciona
	strx.assign(palabra.length(), 'X');
	intentos = 0;
}

void TercerEjercicio::jugar()
{
	ahorcar(intentos);

	if (strx == palabra)
	{
		cout << "\n\tGANASTE!!!";
		return;
	}
	if (intentos == 7)
	{
		cout << "\n\tPERDISTE D':";
		return;
	}

	cout << "\t\t\t" << strx <<"\n\n";

	cout << "\n\nIngresar letra: ";
	cin >> letra;
	
	for (int i = 0; i < palabra.length(); i++)
	{
		if (palabra[i] == letra[0])
		{
			strx[i] = letra[0];
		}
	}
	x = palabra.find(letra[0]);
	if (x == -1)
	{
		intentos += 1;
	}
	jugar();
}

void TercerEjercicio::ahorcar(int intentos)
{
	cout << horca[0] << horca[1];

	if (intentos <= 7)
	{
		for (int i = 0; i < intentos; i++)
		{
			cout << persona[i];
		}
	}
}
