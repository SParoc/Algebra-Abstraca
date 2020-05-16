#include "Vigenere.h"
#include <iostream>

int main()
{
    Vigenere vigenere;

    string mensaje, mensajeCifrado;
    int opcion;

    cout << "\nCifrado De Vigenere: \n\n1. Cifrar mensaje\n2. Descrifrar mensaje\n\n";
    cin >> opcion;
   
    switch (opcion)
    {
    case 1:
        cout << "Mensaje: \n";
        getline(cin.ignore(), mensaje);
        cout << endl;
        cout << vigenere.cipherText(mensaje) << endl;
        break;
    case 2:

        cout << "Mensaje cifrado: \n";
        getline(cin.ignore(), mensajeCifrado);
        cout << endl;
        cout << vigenere.decipherText(mensajeCifrado) << endl;
        break;

    default:
        break;
    }
}

