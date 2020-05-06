#include "Myszkowski.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

Myszkowski::Myszkowski()
{
	r = c = s = k = 0;
	io = jo = 0;
	index = 0;
	repeat = false;
}

void Myszkowski::cipherText(string plainText, string key)
{
	while (plainText.find(' ') != -1)
	{
		plainText.erase(plainText.find(' '), 1);
	}

	c = key.length();

	while (plainText.length() % c != 0)
	{
		plainText.append(" ");
	}

	r = (plainText.length() / key.length());

	auxKey = key;
	sort(auxKey.begin(), auxKey.end());

	cout << key << endl;

	matrix = new string * [r];
	order = new int[c];

	for (int i = 0; i < key.length(); i++)
	{
		order[i] = auxKey.find(key[i]);
		cout << order[i];
	}
	cout << "\n";
	
	for (io = key.length() - 1; io >= 0; io--)
	{
		if (order[io] == order[jo])
		{
			order[io] = order[jo] + 1;
			break;
		}
		jo += 1;
	}

	for (int i = 0; i < r; i++) 
	{
		matrix[i] = new string[c];
	}
	drawMatrix(plainText);
	cout << "\nMensaje cifrado: ";
	printCipherMessage();
}



void Myszkowski::drawMatrix(string plainText)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			matrix[i][j] = plainText[k];
			cout << matrix[i][j];
			k+=1;
		}
		cout << "\n";
	}
}

void Myszkowski::printCipherMessage()
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			auto itr = find(order, order + c, i);
			index = distance(order, itr);
			if (index == jo && repeat == false)
			{
				for (int i = 0; i < r; i++)
				{
					cout << matrix[i][jo] << matrix[i][io];
				}
				repeat = true;
			}
			else if (index != io && index != jo)
			{
				cout << matrix[j][index];
			}
		}
	}
}

Myszkowski::~Myszkowski()
{
	for (int i = 0; i < r; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	delete[] order;
}



