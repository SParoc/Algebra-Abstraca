#include "AlgsCifrado.h"

AlgsCifrado::AlgsCifrado()
{
	rf_space = 0;
	rf_space2 = 0;
	rf_begin = 0;
	rf_pos = 0;
	pb_pos = 0;
	mb_pos = 0;
	rf_swap = false;
}

string AlgsCifrado::monomioBinomio(string plainText, string cipherText, int num1, int num2, string mnemo)
{
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

string AlgsCifrado::railFence(string plainText, string cipherText, int clave)
{
	while (plainText.find(' ') != -1)
	{
		plainText.erase(plainText.find(' '), 1);
	}

	// ta mal ---> rf_space = clave + (clave - 2);

	for (int i = 0; i < plainText.length(); i++)
	{
		if (rf_pos >= plainText.length())
		{
			rf_begin++;
			rf_pos = rf_begin;
			rf_space -= 2;
			rf_space2 += 2;
			rf_swap = false;
		}
		if (rf_begin == 0) //Primera fila
		{
			cipherText += plainText[rf_pos];
			rf_pos += rf_space;
		}
		else if (rf_begin == clave - 1)//Ultima fila
		{
			cipherText += plainText[rf_pos];
			rf_pos += rf_space2 ;
		}
		else//Filas del medio, donde hay dos espaciados diferentes. Se intercalan
		{
			cipherText += plainText[rf_pos];
			if (rf_swap == false)
			{
				rf_pos += rf_space;
				rf_swap == true;
			}
			else
			{
				if (rf_pos + rf_space2 < plainText.length())
				{
					rf_pos += rf_space2;
				}
				rf_swap = false;
			}
		}
	}
	return cipherText;
}
	
string AlgsCifrado::polyBios(string plainText, string cipherText)
{
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

		if (pb_pos % 5 == 0)
		{
			cipherText += pb_let[0];
		}
		else if (pb_pos % 5 == 1)
		{
			cipherText += pb_let[1];
		}
		else if (pb_pos % 5 == 2)
		{
			cipherText += pb_let[2];
		}
		else if (pb_pos % 5 == 3)
		{
			cipherText += pb_let[3];
		}
		else
		{
			cipherText += pb_let[4];
		}
	}

	return cipherText;
}
