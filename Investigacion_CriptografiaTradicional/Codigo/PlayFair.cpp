#include "PlayFair.h"
#include <iostream>
#include <string>

using namespace std;

PlayFair::PlayFair()
{
	x = -1;
}

void PlayFair::printMat()
{
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << " " << matrix[i][j];
		}
		cout << "\n";
	}
}

string PlayFair::process(string plainText)
{
	for (int i = 0; i < plainText.length(); i++)
	{
		x = plainText.find(" ");
		if (x > 0)
		{
			plainText.erase(x, 1);
		}

		if (plainText[i] == plainText[i + 1])
		{
			plainText[i + 1] = 'X';
		}
	}

	if (plainText.length() % 2 != 0)
	{
		plainText.push_back('X');
	}

	for (int i = 2; i < plainText.length(); i+=3)
	{
		plainText.insert(i, " ");
	}
	return plainText;
}

string PlayFair::cipher(string plainText)
{
	for (int k = 0; k < plainText.length(); k++)
	{
		if (plainText[k] != ' ')
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (plainText[k])
					{

					}
				}
			}
		}
	}
	return plainText;
}
