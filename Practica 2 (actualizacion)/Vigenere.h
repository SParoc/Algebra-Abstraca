#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vigenere
{
public:
	Vigenere();
	string cipherText(string plainText, string cipherText, string key, bool mod, int op);
	string decipherText(string cipherText, string plainText, string key, bool mod, int op);
	string kasiskiMethod(string cipherText, string key);
	string addAQUI(string Text, bool agregar);
	
	string abc;
	string num = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
	string ascii = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	bool k2;

private:
	int posText, posKey, k;

};