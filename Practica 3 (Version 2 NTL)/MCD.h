#pragma once
#include <NTL/ZZ.h>
NTL_CLIENT

class MCD
{
public:
	MCD();

	ZZ algoritmo1(ZZ a, ZZ b);
	ZZ algoritmo2(ZZ a, ZZ b);
	ZZ algoritmo3(ZZ a, ZZ b);
	ZZ algoritmo4(ZZ a, ZZ b);
	ZZ algoritmo5(ZZ a, ZZ b);
	ZZ algoritmo6(ZZ a, ZZ b);
	ZZ algIterativo(ZZ a, ZZ b);
	ZZ algRecursivo(ZZ a, ZZ b);
	ZZ mod(ZZ a, ZZ b);

	ZZ r,i,g,d;
};
