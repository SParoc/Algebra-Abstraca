#include <iostream>

using namespace std;

int mod(int a, int b)
{
	int m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
	return a - m * b;
}

int expMod(int b, int e, int N)
{
	int expmod = 1;
	while (e > 0)
	{
		if (mod(e, 2) == 1)
		{
			expmod = mod(expmod * b, N);
		}
		b = mod(b * b, N);
		e = e / 2;
	}
	return expmod;
}
int main()
{
	int b, e, N;

	cout << "\nBase: "; cin >> b;
	cout << "\nExponente: "; cin >> e;
	cout << "\nZn: "; cin >> N;

	cout << "\nRespuesta: " << expMod(b, e, N) << endl;
}
