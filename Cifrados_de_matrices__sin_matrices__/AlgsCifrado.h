#pragma once
#include <string>

using namespace std;

class AlgsCifrado
{
public:
	AlgsCifrado();

	string monomioBinomio(string plainText, string cipherText, int num1, int num2, string mnemo);
	string railFence(string plainText, string cipherText, int keylave);
	string polyBios(string plainText, string cipherText);
	string pb_abc = "abcdefghiklmnopqrstuvwxyz", pb_let = "ABCDE";
	string mb_abc = "abcdefghijklmnopqrstuvwxyz", mb_num = "0123456789";


	
private:
	int rf_space, rf_space2, rf_begin, rf_pos;
	bool rf_swap;
	int pb_pos;
	int mb_pos;
	string mb_abc2;
};
