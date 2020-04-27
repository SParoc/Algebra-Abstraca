#include "MCD.h"
#include <cstdlib>
#include <iostream>

using namespace std;

MCD::MCD()
{
	r = 0;
	i = 1;
	g = 1;
}

int MCD::algoritmo1(int a, int b)
{
	while (true)
	{
		r = mod(a, b);
		if (r == 0)
		{
			break;
		}
		cout << "Iteracion " << i << ": \n a = " << a << ", b = " << b << "\n a = b = " << b << ", b = r = " << r << "\n\n";
		a = b; b = r;
		i += 1;
	}
	return b;
}

int MCD::algoritmo2(int a, int b)
{
	while (true)
	{
		r = mod(a, b);
		if (r == 0)
		{
			break;
		}
		cout << "Iteracion " << i << ": \na = " << a << ", b = " << b;
		if (r > (b / 2))
		{
			cout << "\nr = " << r << " > b/2 = " << b / 2 << " ---> r = " << b << " - " << r;
			r = b - r;
		}
		cout << "\na = b = " << b << ", b = r = " << r << "\n\n";
		a = b; b = r;
		i += 1;
	}
	return b;
}

int MCD::algoritmo3(int a, int b)
{
	cout << "Iteracion " << i << ": \n";
	if (i != 1)
	{
		cout << "a = b = " << a << ", b = a mod b = " << b << "\n\n";
	}
	else
	{
		cout << "a = " << a << ", b = " << b << "\n\n";
	}
	if (b == 0)
	{
		return a;
	}
	i += 1;
	return algoritmo3(b, mod(a, b));
}

int MCD::algoritmo4(int a, int b)
{
	if (abs(b) > abs(a))
	{
		return algoritmo4(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	if (mod(a, 2) == 0 && mod(b, 2) == 0)
	{
		return 2 * algoritmo4(a / 2, b / 2);
	}
	else if (mod(a, 2) == 0 && mod(b, 2) != 0)
	{
		return algoritmo4(a / 2, b);
	}
	else if (mod(a, 2) != 0 && mod(b, 2) == 0)
	{
		return algoritmo4(a, b/2);
	}
	else
	{
		return algoritmo4((abs(a) - abs(b) / 2), b);
	}

}

int MCD::algoritmo4Opcional(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	int g = 0;
	while (!(mod(a, 2)) && !(mod(b, 2)))
	{
		a /= 2;
		b /= 2;
		g++;
	}
	while (!(mod(b, 2)))
	{
		b /= 2;
	}
	while (a != 0)
	{
		while (!(mod(a, 2))) {
			a /= 2;
		}
		if (a < b)
			swap(a, b);
		a -= b;
		b /= 2;
	}
	return (pow(2, g) * b);
}

int MCD::algoritmo5(int a, int b)
{
	while (mod(a, 2) == 0 && mod(b, 2) == 0)
	{
		a = a / 2; b = b / 2; g = 2 * g;
	}
	while (a != 0)
	{
		while (mod(a, 2) == 0)
		{
			a = a / 2;
		}
		while (mod(b, 2) == 0)
		{
			b = b / 2;
		}
		r = abs(a - b) / 2;

		(a >= b) ? (a = r) : (b = r);
	}

	return(g * r);
}

int MCD::algoritmo6(int a, int b)
{
	while (a != b)
	{
		cout << "Iteracion " << i << ": \n" << a <<" != "<< b << " --> \n";
		if (a > b)
		{
			cout << "a = " << a << " > b = " << b << " --> a = " << a << " - " << b << endl;
			a -= b;
			cout << "a = " << a << "\n\n";
		}
		else
		{
			cout << "b = " << b << " > a = " << a << " --> b = " << b << " - " << a << endl;
			b -= a;
			cout << "b = " << b << "\n\n";
		}
		i += 1;
	}
	return a;
}


int MCD::mod(int a, int b)
{
	int m;
	m = a + ((abs(a / b) + 1) * b);
	return m - ((m / b) * b);
}
