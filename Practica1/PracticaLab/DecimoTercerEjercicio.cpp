/*Disculpe por no agregarlo antes, como estuve trabajando con clases en la primer
version por alguna razon, no funcionaba esta misma implementacion, es por eso que
decidi hacer este ejercicio con un archivo .cpp aparte*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	string numStr;
	int num;
	int sum = 0;

	file.open("numeros.txt", ios::in);

	while(!file.eof())
	{
		file >> numStr;
		num= stoi(numStr);

		cout << num <<endl;
		sum += num;
	}
	cout << "\nSuma: " << sum;
}
