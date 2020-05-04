#include <iostream>
#include <ctime>
#include "MCD.h"
#include <NTL/ZZ.h>
NTL_CLIENT

using namespace std;

int main()
{
    std::cout << "Introducir numero de algoritmo!\n";
    MCD mcd;
    int opcion;
    ZZ a, b, d;
    d = 2;
    unsigned t0, t1;
    double tiempo;

    cin >> opcion; 

    cout << "Introducir primer numero: ";
    cin >> a;
    cout << "Introducir segundo numero: ";
    cin >> b;

    t0 = clock();

    switch (opcion)
    {
    case 1:
        cout << mcd.algoritmo1(a, b);
        break;
    case 2:
        cout << mcd.algoritmo2(a, b);
        break;
    case 3: 
        cout << mcd.algoritmo3(a, b);
        break;
    case 4:
        cout << mcd.algoritmo4(a, b);
        break;
    case 5:
        cout << mcd.algoritmo5(a, b);
        break;
    case 6:
        cout << mcd.algoritmo6(a, b);
        break;
    case 7:
        cout << mcd.algIterativo(a, b);
        break; 
    case 8:
        cout << mcd.algRecursivo(a, b);
        break;
    default:
        break;
    }
    t1 = clock();
    
    cout<<"\n\nTiempo de ejecucion: "<< (double(t1-t0)/CLOCKS_PER_SEC);
}
