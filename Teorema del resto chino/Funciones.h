#ifndef FUNCIONES_H
#define FUNCIONES_H

int mod(int a, int b)
{
	int m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);

	return a - m * b;
}

int mcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return mcd(b, mod(a, b));
}

int inversa(int a, int b)
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

#endif
