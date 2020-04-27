#include <iostream>
#include <ctime>
#include "MCD.h"

using namespace std;

int main()
{
    std::cout << "Introducir numero de algoritmo!\n";
    MCD mcd;
    int opcion;
    unsigned t0, t1;
    double tiempo;

    cin >> opcion; 
    
    t0 = clock();

    switch (opcion)
    {
    case 1:
        cout << mcd.algoritmo1(412, 260);
        break;
    case 2:
        cout << mcd.algoritmo2(412, 260);
        break;
    case 3: 
        cout << mcd.algoritmo3(412, 260);
        break;
    case 4:
        cout << mcd.algoritmo4(412, 260);
        break;
    case 5:
        cout << mcd.algoritmo5(412, 260);
        break;
    case 6:
        cout << mcd.algoritmo6(412, 260);
        break;
    default:
        break;
    }

    t1 = clock();
    cout<<"\n\nTiempo de ejecucion: "<< (double(t1-t0)/CLOCKS_PER_SEC);
 
}

