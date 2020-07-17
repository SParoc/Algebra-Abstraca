#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "NTL/ZZ.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;
NTL_CLIENT

inline ZZ mod(ZZ a, ZZ b)
{
	ZZ m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
	return a - m * b;
}

inline int modInt(long long a, int b)
{
	int m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
	return a - m * b;
}

inline ZZ mcd(ZZ a, ZZ b)
{
	if (abs(b) > abs(a)) { return mcd(b, a); }
	else if (b == 0) { return a; }
	else if (mod(a, ZZ(2)) == 0 && mod(b, ZZ(2)) == 0) { return mcd(a >> 1, b >> 1) << 1; }
	else if (mod(a, ZZ(2)) == 0 && mod(a, ZZ(2)) != 0) { return mcd(a >> 1, b); }
	else if (mod(a, ZZ(2)) != 0 && mod(a, ZZ(2)) == 0) { return mcd(a, b >> 1); }
	else { return mcd((abs(a) - abs(b)) >> 1, b); }
}

inline ZZ inversa(ZZ a, ZZ b)
{
	ZZ t, q;
	ZZ s1 = ZZ(1), s2 = ZZ(0), r = b;
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

inline ZZ expMod(ZZ b, ZZ e, ZZ N)
{
	ZZ expmod = ZZ(1);
	while (e > 0)
	{
		if (mod(e, ZZ(2)) == 1)
		{
			expmod = mod(expmod * b, N);
		}
		b = mod(b * b, N);
		e = e / 2;
	}
	return expmod;
}

inline string ZZaString(ZZ Q)
{
	stringstream buffer;
	buffer << Q;
	return buffer.str();
}

inline string insertCeros(string str, int len1, int len2)
{
	for (len1; len1 < len2; len1++)
	{
		str.insert(0, "0");
	}

	return str;
}

#endif
