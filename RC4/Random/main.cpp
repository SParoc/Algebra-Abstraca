#include "Funciones.h"
#include <iostream>
#include <ctime>

int main() 
{
    unsigned t0, t1, t2, t3;

    cout << "\Numeros aleatorios de 128 bits: \n\n";
    t0 = clock();
    for (int i = 0; i < 10; i++) 
    {
        t2 = clock();
        ZZ _128 = rand(128);
        t3 = clock();

        cout << _128 << "\nTiempo: " << (double(t3 - t2) / CLOCKS_PER_SEC) << "\n";
    }
    t1 = clock();
    cout << "\nTIEMPO TOTAL: " << (double(t1 - t0) / CLOCKS_PER_SEC) << "\n\n";

    cout << "\Numeros aleatorios de 512 bits: \n\n";
    t0 = clock();
    for (int i = 0; i < 10; i++)
    {
        t2 = clock();
        ZZ _512 = rand(512);
        t3 = clock();

        cout << _512 << "\nTiempo: " << (double(t3 - t2) / CLOCKS_PER_SEC) << "\n";
    }
    t1 = clock();
    cout << "\nTIEMPO TOTAL: " << (double(t1 - t0) / CLOCKS_PER_SEC) << "\n\n";

    cout << "\Numeros aleatorios de 1024 bits: \n\n";
    t0 = clock();
    for (int i = 0; i < 10; i++)
    {
        t2 = clock();
        ZZ _1024 = rand(1024);
        t3 = clock();

        cout << _1024 << "\nTiempo: " << (double(t3 - t2) / CLOCKS_PER_SEC) << "\n";
    }
    t1 = clock();
    cout << "\nTIEMPO TOTAL: " << (double(t1 - t0) / CLOCKS_PER_SEC) << "\n\n";

}
