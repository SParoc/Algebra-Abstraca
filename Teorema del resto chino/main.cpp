#include <iostream>
#include "Funciones.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> p;
    vector<int> P;
    vector<int> q;

    int n, numAux, znAux;

    cout << "Numero de ecuaciones: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n" << i+1<< ". Numero: "; cin >> numAux;
        a.push_back(numAux);
        cout << "\tEn modulo: "; cin >> znAux;
        p.push_back(znAux);
    }

    int mul = 1;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            if (mcd(p[i - 1], p[i]) != 1)
            {
                cout << "\nLos modulos deben ser primos entre si\n\n";
                return 0;
            }
        }
        mul *= p[i];
    }

    for (int i = 0; i < n; i++)
    {
        P.push_back(mul / p[i]);
        q.push_back(inversa(P[i], p[i]));
    }

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        x += (a[i] * P[i] * q[i]);
    }

    x = mod(x, mul);

    cout << "\n\nTodas las soluciones del problema seran: \n\tX = " << x << " + " << mul << "k\n\n";
}
