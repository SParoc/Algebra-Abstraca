#include "Afin.h"
#include <string>

using namespace std;

Affine::Affine()
{
	abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

string Affine::cifrar(int a, int b, string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = abc[(abc.find(text[i])*a + b) % 26];
	}
	return text;
}
