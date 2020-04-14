#include "DecimoSegundo_ejercicio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

DecimoSegundo::DecimoSegundo()
{
	outNumeros.open("numeros.txt", ios::out);
	inNumeros.open("numeros.txt", ios::in);
	N = x = y = suma = 0;
}

void DecimoSegundo::ingresarNumeros()
{
	do
	{
		cout << "Ingresar N (1 al 10): ";
		cin >> N;
	} while (N < 1 || N>10);

	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		x = rand() % 1000 + 1;
		numerosArray[i] = to_string(x);
		
		outNumeros << x << "\n";
	}
}

void DecimoSegundo::operar()
{

	ingresarNumeros();

	string line;
	
	while (getline(inNumeros, line))  
	{
		suma = suma + stoi(line);  
	}

	cout << "La suma es: " << suma;  

}


