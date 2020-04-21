#include "PlayFair.h"
#include <iostream>
#include <string>

using namespace std;

PlayFair::PlayFair()
{
}

void PlayFair::initMat(string key)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < key.length(); k++)
			{
				if (key[k] == matrix[i][j])//No deja hacer comparacion si la matriz es string
				{
					key.erase(k, 1);
				}
				else
				{
					matrix[i][j] = key[k];
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << " " << matrix[i][j];
		}
		cout << "\n";
	}
}
