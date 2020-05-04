#include "Vigenere.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Vigenere vigenere;

    string plainText, cipherText, key;
    string poema[6] = 
    { 
        "Puedo escribir los versos mas tristes esta noche. ",
        "Escribir, por ejemplo: La noche esta estrellada, ",
        "y tiritan, azules, los astros, a lo lejos. ",
        "El viento de la noche gira en el cielo y canta. ",
        "Puedo escribir los versos mas tristes esta noche. ",
        "Yo la quise, y a veces ella tambien me quiso." 
     };
    int option, opcion2;
   
    cout << "Practica 2!\n"<<endl;
    cout << "1. Cifrado de Vigenere\n2. Descifrado de Vigenere\n3. Poema Neruda\n4. Cifrado con AQUI - W\n5. Descifrado con AQUI - W"
        << "\n6. Cifrado modificado\n7 .Descifrado modificado\n\n";
    cin >> option;

    cout << "\nTipo de alfabeto: \n1. Numerico (abecedario normal)\n2. ASCII\n";
    cin >> opcion2;

    cin.clear();
    cin.ignore();

    switch (option)
    {
    case 1:

        getline(cin, plainText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.cipherText(plainText, cipherText, key, false, opcion2);
        break;
    case 2:

        cout << "Mensaje: \n";
        getline(cin, cipherText);
        cout << "Clave: \n";
        getline(cin, key);
        cout << endl;
        cout << vigenere.decipherText(cipherText, plainText, key, false, opcion2);
        cout << endl;
        break;

    case 3:

        key = "Pablo Neruda";

        /*for (int i = 0; i < 6; i++)
        {
            cout << "\t" << poema[i] << "\n";
        }*/
        for (int i = 0; i < 6; i++)
        {
            cout << "\t" << vigenere.cipherText(poema[i], cipherText, key, false, opcion2) << "\n";
        }
        cout << "\n\n";
       /* for (int j = 0; j < 6; j++)
        {
            poema[j] = vigenere.decipherText(poema[j], plainText, key, false);
            cout << "\t" << poema[j] << "\n";
        }*/

    case 4:

        getline(cin, plainText);
        getline(cin, key);
        cout << "\n" << vigenere.addAQUI(plainText, true);
        cout << endl;
        cout << vigenere.cipherText(vigenere.addAQUI(plainText,true), cipherText, key, false, opcion2);
        break;

    case 5:

        getline(cin, cipherText);
        getline(cin, key);
        cout << endl;
        cout << "\n" << vigenere.addAQUI(vigenere.decipherText(cipherText, plainText, key, false, opcion2), false);
        break;
    case 6:

        getline(cin, plainText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.cipherText(plainText, cipherText, key, true, opcion2);

        break;
   /* case 7:

        getline(cin, cipherText);
        getline(cin, key);
        cout << endl;
        cout << vigenere.decipherText(cipherText, plainText, key, true, opcion2);
        break;
        */

    default:
        break;
    }
}

