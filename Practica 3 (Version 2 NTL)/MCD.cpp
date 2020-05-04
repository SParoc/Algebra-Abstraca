#include "MCD.h"
#include <cstdlib>
#include <iostream>
#include <NTL/ZZ.h>
NTL_CLIENT

using namespace std;

MCD::MCD()
{
	r = 0;
	i = 1;
	g = 1;
	d = 2;
}

ZZ MCD::algoritmo1(ZZ a, ZZ b)
{
	do
	{
		r = mod(a, b);
		cout << "Iteracion " << i << ": \n a = " << a << ", b = " << b << "\n a = b = " << b << ", b = r = " << r << "\n\n";
		a = b; b = r;
		i += 1;
	} while (mod(a, b) != 0);
	return b;
}

ZZ MCD::algoritmo2(ZZ a, ZZ b)
{
	do
	{
		r = mod(a, b);
		cout << "Iteracion " << i << ": \na = " << a << ", b = " << b;
		if (r > (b / 2))
		{
			cout << "\nr = " << r << " > b/2 = " << b / 2 << " ---> r = " << b << " - " << r;
			r = b - r;
		}
		cout << "\na = b = " << b << ", b = r = " << r << "\n\n";
		a = b; b = r;
		i += 1;
	} while (mod(a, b) != 0);
	return b;
}

ZZ MCD::algoritmo3(ZZ a, ZZ b)
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

ZZ MCD::algoritmo4(ZZ a, ZZ b)
{
	cout << "\nIteracion " << i << " :" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	if (abs(b) > abs(a))
	{
		return algoritmo4(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	if (mod(a, d) == 0 && mod(b, d) == 0)
	{
		return 2 * algoritmo4(a / 2, b / 2);
	}
	if (mod(a, d) == 0 && mod(b, d) == 1)
	{
		return algoritmo4(a / 2, b);
	}
	if (mod(a, d) == 1 && mod(b, d) == 0)
	{
		return algoritmo4(a, b / 2);
	}
	return algoritmo4((abs(a) - abs(b)) / 2, b);
}

ZZ MCD::algoritmo5(ZZ a, ZZ b)
{
	while (mod(a, d) == 0 && mod(b, d) == 0)
	{
		cout << "\n\nIteracion " << i << ": " << endl;
		a /= 2; b /= 2; g *= 2;
		i += 1;
	}

	while (a != 0)
	{
		cout << "\n\nIteracion " << i << ": " << endl;
		while (mod(a, d) == 0)
		{
			a /= 2;
		}
		while (mod(b, d) == 0)
		{
			b /= 2;
		}
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		
		if (((abs(a - b)) / 2 != 0) || (a == 1 && b == 1))
		{
			r = (abs(a - b)) / 2;
		}
		else { break; }
		
		cout << "r = " << r << endl;
		(a >= b) ? (a = r) : (b = r);
		i += 1;
	};
	cout << "\nMCD: ";
	if (r == 0) { return(g + r); }
	else { return(g * r ); }	
}

ZZ MCD::algoritmo6(ZZ a, ZZ b)
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

ZZ MCD::algIterativo(ZZ a, ZZ b)
{
	while (b != 0) 
	{
		cout << "\nIteracion " << i << " :" << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		ZZ r = b;
		b = mod(a, b);
		a = r;
		i += 1;
	}
	return a;
}

ZZ MCD::algRecursivo(ZZ a, ZZ b)
{
	cout << "\nIteracion " << i << " :" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	i += 1;

	if (b == 0) { return a; }	
	return algRecursivo(b, mod(a, b));
}

ZZ MCD::mod(ZZ a, ZZ b)
{
	ZZ m;
	m = a + ((abs(a / b) + 1) * b);
	return m - ((m / b) * b);
}
