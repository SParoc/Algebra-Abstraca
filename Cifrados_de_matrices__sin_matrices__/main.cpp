#include "AlgsCifrado.h"
#include <iostream>

int main()
{
    cout << "3 algoritmos de cifrado\n\n";

    AlgsCifrado cifrado;
    string rf_str, pb_str, mb_str;
   
    int op;

    cout << "1. Monomio-Binomio\n2. Rail Fence\n3. Polybios\n\n";
    cin >> op;

    switch (op)
    {
    case 1:
        getline(cin.ignore(), mb_str);
        cout << "Cifrado: " << cifrado.monomioBinomio(mb_str, 2, 7, "denarios") << "\n\n";
        break;
    case 2:
        getline(cin.ignore(), rf_str);
        cout << "Cifrado: " << cifrado.railFence(rf_str) << "\n\n";
        break;
    case 3:
        getline(cin.ignore(), pb_str);
        cout << "Cifrado: " << cifrado.polyBios(pb_str) << "\n\n";
        break;
    default:
        cout << "Opcion no valida\n"; 
        break;
    }
}
