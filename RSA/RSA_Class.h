#pragma once

#include <NTL/ZZ.h>
#include <string>
#include <iostream>

NTL_CLIENT

using namespace std;

class RSA
{
public:
	RSA();
	RSA(ZZ, ZZ, ZZ);
	ZZ mcd(ZZ a, ZZ b);
	ZZ inversa(ZZ a, ZZ b);
	ZZ get_e(); ZZ get_d(); ZZ get_N(); ZZ get_phiN();
	string cifrar(string mensaje);
	string aString(ZZ P);
	string descifrar(string mensajeCifrado);
	void generarClaves();
	ZZ mod(ZZ a, ZZ b);

	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";

private:
	ZZ e, d, N, phiN;

};

