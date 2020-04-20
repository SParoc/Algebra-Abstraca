#include "Vigenere.h"
#include <iostream>
#include <string>

using namespace std;

Vigenere::Vigenere()
{
	posText = 0;
	posKey = 0;
	k = 0;
	k2 = false;
}

string Vigenere::cipherText(string plainText, string cipherText, string key, bool mod)
{
	for (int i = 0; i < plainText.length(); i++)
	{
		posText = abc.find(plainText[i]);

		if (mod && k2)
		{
			posKey = abc.find(plainText[k]);
			k += 1;
			if (k >= key.length())
			{
				k = 0;
			}
		}
		else
		{
			posKey = abc.find(key[k]);
			k += 1;
			if (k >= key.length())
			{
				k = 0;
				if (mod)
				{
					k2 = true;
				}
			}
		}

		posText += posKey;

		if (posText >= abc.length())
		{
			posText = posText % abc.length();
		}

		if (plainText[i] != ':')
		{
			cipherText += abc[posText];
		}
		else
		{
			cipherText += ':';
		}
	}
	return cipherText;
}

string Vigenere::decipherText(string cipherText, string plainText, string key, bool mod)
{
	for (int i = 0; i < cipherText.length(); i++)
	{
		posText = abc.find(cipherText[i]);

		if (mod && k2)
		{
			posKey = abc.find(decipherText(cipherText, plainText, key, false)[k]);
			k += 1;
			if (k >= key.length())
			{
				k = 0;
			}
		}
		else
		{
			posKey = abc.find(key[k]);
			k += 1;
			if (k >= key.length())
			{
				k = 0;
				if (mod)
				{
					k2 = true;
				}
			}
		}

		posText -= posKey;

		if (posText < 0)
		{
			posText = posText + abc.length();
		}

		if (cipherText[i] != ':')
		{
			plainText += abc[posText];
		}
		else
		{
			plainText += ':';
		}
	}
	return plainText;
}

string Vigenere::kasiskiMethod(string cipherText, string key)
{
	return key;
}

string Vigenere::addAQUI(string Text, bool agregar)
{
	if (agregar)
	{
		for (int i = 10; i < Text.length(); i += 14)
		{
			Text.insert(i, "AQUI");
		}

		if (Text.length() % 4 != 0)
		{
			Text.append(4 - (Text.length() % 4), 'W');
		}
	}
	else
	{
		for (int i = 10; i < Text.length()+14; i += 14)
		{
			Text.erase(Text.find("AQUI"), 4);
		}

		while (Text.back() == 'W')
		{
			Text.pop_back();
		}
	}
	
	return Text;
}
