#include "AlgsCifrado.h"
#include <iostream>

int main()
{
    cout << "3 algoritmos de cifrado\n\n";

    AlgsCifrado cifrado;
    string str;
   
    int op;

    cout << "1. Monomio-Binomio\n2. Rail Fence\n3. Polybios\n4. Descifrado PolyBios\n\n";
    cin >> op;

    switch (op)
    {
    case 1:
        getline(cin.ignore(), str);
        cout << "Cifrado: " << cifrado.monomioBinomio(str, 2, 7, "denarios") << "\n\n";
        break;
    case 2:
        getline(cin.ignore(), str);
        cout << "Cifrado: " << cifrado.railFence(str) << "\n\n";
        break;
    case 3:
        getline(cin.ignore(), str);
        cout << "Cifrado: " << cifrado.polyBios(str) << "\n\n";
        break;
    case 4:
        getline(cin.ignore(), str);
        cout << "Descifrado: " << cifrado.descPolyBios(str) << "\n\n";
        break;
    default:
        cout << "Opcion no valida\n"; 
        break;
    }
}
