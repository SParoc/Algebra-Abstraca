#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "RSA_Class.h"


RSA::RSA()
{
	e = d = N = phiN = 0;
	generarClaves();
}

RSA::RSA(ZZ _e, ZZ _N, ZZ _phiN)
{
	e = _e;
	d = inversa(_e, _phiN);
	N = _N;
	phiN = _phiN;
}


void RSA::generarClaves()
{
	cout << "\nGenerando numeros primos...";
	//********************************Criba de Eratóstenes****************************
	vector<long long> primos;

	primos.push_back(2);

	for (int i = 3; i <= 1000000; i += 2)
	{
		primos.push_back(i);
	}

	int j, k;
	j = 1, k = 2;

	while (k < primos.size() && primos[j] * primos[j] < 1000000)
	{
		if (primos[k] % primos[j] == 0)
		{
			primos.erase(primos.begin() + k);
		}
		else { k++; }
		if (k == primos.size())
		{
			j++; k = j + 1;
		}
	}

	cout << "\nNumeros primos generados.\n\nAsignando valores a las claves...";

	srand(time(NULL));
	int i1, i2;

	do
	{
		i1 = rand() % primos.size();
	} while (i1 < 9592); //Indices de los numeros de 6 cifras

	do
	{
		i2 = rand() % primos.size();
	} while (i2 < 9592);

	ZZ p = ZZ(primos[i1]), q = ZZ(primos[i2]);
	
	N = p * q;
	phiN = (p - 1) * (q - 1);

	do
	{
		e = rand();
		e = mod(e, phiN);
	} while (mcd(e, phiN) != 1);

	cout << "\nValores asignados.";

}

ZZ RSA::get_e()
{
	return e;
}

ZZ RSA::get_N()
{
	return N;
}

ZZ RSA::get_d()
{
	return d;
}

ZZ RSA::get_phiN()
{
	return phiN;
}

string RSA::aString(ZZ P)
{
	stringstream buffer;
	buffer << P;
	return buffer.str();
}

string RSA::cifrar(string mensaje)
{
	string mensajeCifrado;
	ZZ aux, p, expMod;

	for (int j = 0; j < mensaje.length(); j++)
	{
		expMod = 1;
		p = abc.find(mensaje[j]);
		aux = e;

		while (aux > 0)
		{
			if (mod(aux, ZZ(2)) == 1)
			{
				expMod = mod(expMod * p, N);
			}
			p = mod(p * p, N);
			aux = aux / 2;
		}

		mensajeCifrado = mensajeCifrado + aString(expMod) + " ";
	}
	return mensajeCifrado;
}

string RSA::descifrar(string mensajeCifrado)
{
	string mensaje, q_str;
	ZZ expMod, aux;
	
	int ini = 0, fin;

	while (mensajeCifrado.length() != 0)
	{
		fin = mensajeCifrado.find(" ");
		q_str = mensajeCifrado.substr(ini, fin);
		mensajeCifrado.erase(ini, fin + 1);

		ZZ q(NTL::INIT_VAL, q_str.c_str());
		expMod = 1;
		aux = d;

		while (aux > 0)
		{
			if (mod(aux, ZZ(2)) == 1)
			{
				expMod = mod(expMod * q, N);
			}
			q = mod(q * q, N);
			aux = aux / 2;
		}

		mensaje += abc[conv<int>(expMod)];
	}
	return mensaje;
}

ZZ RSA::mod(ZZ a, ZZ b)
{
	ZZ m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
	return a - m * b;
}

ZZ RSA::mcd(ZZ a, ZZ b)
{
	if (b == 0)
	{
		return a;
	}
	return mcd(b, mod(a, b));
}

ZZ RSA::inversa(ZZ a, ZZ b)
{
	ZZ t, q;
	ZZ s1 = conv<ZZ>(1), s2 = conv<ZZ>(0), r = b;
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

