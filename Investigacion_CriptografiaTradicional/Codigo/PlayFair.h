#pragma once

#include <string>

using namespace std;

class PlayFair
{
public:
	PlayFair();
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	void printMat();
	string process(string plainText);
	string cipher(string plainText);

private:

	char matrix[5][5] =
	{
		{'A','B','S','T','R'},
		{'C','D','E','F','G'},
		{'H','I','K','L','M'},
		{'N','O','P','Q','U'},
		{'V','W','X','Y','Z'}
	};
	int x;
};

