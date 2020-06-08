#include "Afin.h"
#include <ctime>
#include <cstdlib>

CifradoAfin::CifradoAfin()
{
	abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	generarClaves();
}

CifradoAfin::CifradoAfin(int _a, int _b)
{
	abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	a = inversa(_a, abc.length());
	b = _b;
}

void CifradoAfin::generarClaves()
{
	srand(time(NULL));
	do
	{
		a = rand() % abc.length();

	} while (mcd(a, abc.length()) != 1);

	b = rand() % abc.length();
}

int CifradoAfin::getA()
{
	return a;
}

int CifradoAfin::getB()
{
	return b;
}

int CifradoAfin::mcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return mcd(b, mod(a, b));
}

int CifradoAfin::mod(int a, int b)
{
	int m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a/b);

	return a - m*b;
}

int CifradoAfin::inversa(int a, int b)
{
	int t, q;
	int s1 = 1, s2 = 0, r = b;
	while (b > 0)
	{
		q = a / b;
		t = a - q * b;
		a = b; b = t;
		t = s1 - q * s2;
		s1 = s2; s2 = t;
	}
	if (s1 < 0) { s1 += r; }

	return s1;
}

string CifradoAfin::cifrarMensaje(string mensaje)
{
	string mensajeCifrado;

	for (int i = 0; i < mensaje.length(); i++)
	{
		mensajeCifrado += abc[mod((a * (abc.find(mensaje[i]))) + b, abc.length())];
	}
	return mensajeCifrado;
}

string CifradoAfin::descifrarMensaje(string mensajeCifrado)
{
	string mensajeDescifrado;

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		mensajeDescifrado += abc[mod(a * ((abc.find(mensajeCifrado[i])) - b), abc.length())];
	}
	return mensajeDescifrado;
}
