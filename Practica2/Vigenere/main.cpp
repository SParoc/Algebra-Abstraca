#include "Vigenere.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Vigenere vigenere;

    string plainText, cipherText, key;
    int option;
    cout << "Practica 2!\n"<<endl;
    cin >> option;

    cin.clear();
    cin.ignore();

    switch (option)
    {
    case 1:

        getline(cin, plainText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.cipherText(plainText, cipherText, key, false);
        break;
    case 2:

        getline(cin, cipherText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.decipherText(cipherText, plainText, key, false);
        break;
    case 3:

        getline(cin, plainText);
        getline(cin, key);
        cout << "\n" << vigenere.addAQUI(plainText);
        cout << endl;
        cout << vigenere.cipherText(vigenere.addAQUI(plainText), cipherText, key, false);
        break;
    case 4:

        getline(cin, plainText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.cipherText(plainText, cipherText, key, true);

        break;
    case 5:

        getline(cin, plainText);
        

    default:
        break;
    }
}
