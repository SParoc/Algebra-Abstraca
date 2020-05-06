#pragma once
#include <string>
using namespace std;

class Myszkowski
{
public:
	Myszkowski();
	~Myszkowski();

	void cipherText(string plainText, string key);
	void drawMatrix(string plainText);
	void printCipherMessage();

private:
	int r, c, s, k;
	string** matrix;
	string auxKey, auxKey2;
	int *order;
	int io, jo;
	int index;
	bool repeat;
};
