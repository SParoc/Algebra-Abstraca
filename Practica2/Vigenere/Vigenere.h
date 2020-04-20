#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vigenere
{
public:
	Vigenere();
	string cipherText(string plainText, string cipherText, string key, bool mod);
	string decipherText(string cipherText, string plainText, string key, bool mod);
	string kasiskiMethod(string cipherText, string key);
	string addAQUI(string Text, bool agregar);
	
	string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	bool k2;

private:
	int posText, posKey, k;

};
