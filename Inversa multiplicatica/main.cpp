#include <iostream>
#include "InversaModulo.h"

int main()
{
    InversaModulo inversa;
    int a, b;

    cout << "Encontrar la inversa de: ";
    cin >> b;

    cout << "\nEn base: ";
    cin >> a;

    inversa.EuclidesExtendido(a,b);
}
