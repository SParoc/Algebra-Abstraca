#include "InversaModulo.h"

InversaModulo::InversaModulo()
{
	r = q = s = t = 0;
}

void InversaModulo::EuclidesExtendido(int a, int b)
{
	int s1 = 1, s2 = 0, t1 = 0, t2 = 1;

	while (b > 0)
	{
		q = a / b;

		r = a - q * b;
		a = b; b = r;

		s = s1 - q * s2;
		s1 = s2; s2 = s;

		t = t1 - q * t2;
		t1 = t2; t2 = t;
	}

	cout << "MCD = " << a << "\nInversa: " << t1;

	return;
}
