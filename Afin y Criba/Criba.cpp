#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int mod(int a, int b)
{
	int m;
	(a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
	return a - m * b;
}

int main()
{
	unsigned t0, t1;
	vector<long long> primos;
	primos.push_back(2);
	int i1, i2;
	i1 = i2 = 0;

	long long num;
	cin >> num;

	t0 = clock();

	for (int i = 3; i <= num; i+=2)
	{
		primos.push_back(i);
		i1++;
	}

	int j = 1, k = 2;

	while(k < primos.size() && primos[j] * primos[j] < num)
	{
		i2++;
		if (mod(primos[k] , primos[j]) == 0)
		{
			primos.erase(primos.begin() + k);
		}
		else { k++; }

		if (k == primos.size())
		{
			j++; k = j + 1;
		}
	}
	for (int i = 0; i < primos.size(); i++)
	{
		cout << primos[i] << " ";
	}

	t1 = clock();

	cout << "\n\nTotal de numeros primos: " << primos.size();
	cout << "\n\nIteraciones totales para operar: " << i1 + i2;
	cout << "\n\nTiempo: " << (double(t1 - t0) / CLOCKS_PER_SEC) << endl << endl;
}
