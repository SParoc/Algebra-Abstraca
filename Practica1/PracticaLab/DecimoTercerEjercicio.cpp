/*Disculpe por no agregarlo antes, como estuve trabajando con clases en la primer version
por alguna razon, no funcionaba esta misma implementacion, es por eso que decidi
hacer este ejercicio con un archivo .cpp aparte*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream archivo;
	archivo.open("numeros.txt", ios::in);

	string dato;
	int numero;
	int sumatoria = 0;

	while(!archivo.eof())
	{
		archivo >> dato;
		numero= stoi(dato);

		cout << numero<<endl;
		sumatoria += numero;
	}
	cout << "\nSuma: " << sumatoria;
	archivo.close();
}
