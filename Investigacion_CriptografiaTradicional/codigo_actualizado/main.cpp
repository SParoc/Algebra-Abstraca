#include <iostream>
#include "Afin.h"
#include <string>
#include "Myszkowski.h"

using namespace std;

int main()
{
    Affine afin;
    Myszkowski myszkowski;

    string plainText;

    getline(cin, plainText);
    myszkowski.cipherText(plainText, "CELULAR");
}
