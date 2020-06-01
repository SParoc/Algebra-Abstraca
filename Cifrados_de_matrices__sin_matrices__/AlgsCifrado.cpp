#include "AlgsCifrado.h"

AlgsCifrado::AlgsCifrado()
{
	pb_pos = 0;
	mb_pos = 0;

	rf_key = 6;
}

string AlgsCifrado::monomioBinomio(string plainText, int num1, int num2, string mnemo)
{
	string cipherText;

	mnemo.insert(num1," ");
	mnemo.insert(num2, " ");

	mb_abc2.insert(0, mnemo);

	for (int i = 0; i < 26; i++)
	{
		if (mnemo.find(mb_abc[i]) == -1)
		{
			mb_abc2.push_back(mb_abc[i]);
		}
	}

	mb_abc2.push_back('-');
	
	while (plainText.find(' ') != -1)
	{
		plainText.erase(plainText.find(' '), 1);
	}
	for (int i = 0; i < plainText.length(); i++)
	{
		mb_pos = mb_abc2.find(plainText[i]);
		if (mb_pos < 10)
		{
			cipherText += to_string(mb_pos);
		}
		else if (mb_pos >= 10 && mb_pos < 20)
		{
			cipherText += to_string(num1);
			cipherText += to_string(mb_pos - 10);
		}
		else
		{
			cipherText += to_string(num2);
			cipherText += to_string(mb_pos - 20);
		}
	}

	return cipherText;
}

string AlgsCifrado::railFence(string plainText)
{
	string cipherText;

	int begin = 0, pos = 0;
	int space1 = rf_key *2 - 2, space2 = 0;

	while (plainText.find(' ') != -1)
	{
		plainText.erase(plainText.find(' '), 1);
	}

	for (int i = 0; i < plainText.length(); i++)
	{
		if (pos >= plainText.length())
		{
			begin++;
			pos = begin;
			space1 -= 2;
			space2 += 2;
		}

		if (begin == 0)
		{
			cipherText += plainText[pos];
			pos += space1;
		}
		else if (begin == rf_key - 1)
		{
			cipherText += plainText[pos];
			pos += space2;
		}
		else
		{
			cipherText += plainText[pos];
			pos += space1;

			if (pos < plainText.length())
			{
				cipherText += plainText[pos];
				pos += space2;
				i++;
			}
		}
	}
	return cipherText;
}

string AlgsCifrado::descRailFence(string cipherText)
{
	string plainText;
	/*
	for (int i = 0; i < cipherText.length(); i++)
	{

	}*/

	return plainText;
}
	
string AlgsCifrado::polyBios(string plainText)
{
	string cipherText;

	while (plainText.find(' ') != -1)
	{
		plainText.erase(plainText.find(' '), 1);
	}
	for (int i = 0; i < plainText.length(); i++)
	{
		pb_pos = pb_abc.find(plainText[i]);

		if (pb_pos < 5)
		{
			cipherText += pb_let[0];
		}
		else if (pb_pos >= 5 && pb_pos < 10)
		{
			cipherText += pb_let[1];
		}
		else if (pb_pos >= 10 && pb_pos < 15)
		{
			cipherText += pb_let[2];
		}
		else if (pb_pos >= 15 && pb_pos < 20)
		{
			cipherText += pb_let[3];
		}
		else
		{
			cipherText += pb_let[4];
		}

		switch (pb_pos % 5)
		{
		case 0:
			cipherText += pb_let[0];
			break;
		case 1:
			cipherText += pb_let[1];
			break;
		case 2:
			cipherText += pb_let[2];
			break;
		case 3:
			cipherText += pb_let[3];
			break;
		default:
			cipherText += pb_let[4];
			break;
		}
	}

	return cipherText;
}
