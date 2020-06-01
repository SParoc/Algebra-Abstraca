#include <iostream>
#include "InversaMultiplicativa.h"

int main()
{
    InversaMultiplicativa inversa;
    int a, b;

    cout << "Encontrar la inversa de: ";
    cin >> b;

    cout << "\nEn base: ";
    cin >> a;

    inversa.EuclidesExtendido(a,b);
}
