#include <iostream>
#include "AlgsCifrado.h"

int main()
{
    std::cout << "3 algoritmos de cifrado\nSe pueden cambiar todos los textos claros\nSe recomienda no cambiar las claves\n\n";

    AlgsCifrado cifrado;

    cout << "Cifrado monomio-binomio: \nTexto claro: el cifrado monomio-binomio no me gusta\nNumeros claves: 2, 7\nPalabra mnemotecnica: denarios\n";
    cout << "Cifrado: " << cifrado.monomioBinomio("el cifrado monomio-binomio no me gusta", "", 2, 7, "denarios") << "\n\n"; 
    cout << "Cifrado Rail Fence: \nTexto claro: el cifrado rail fence tampoco me gusta\nClave: 3\n";
    cout << "Cifrado: " << cifrado.railFence("el cifrado rail fence tampoco me gusta","", 3) << "\n\n";
    cout << "Cifrado Rail Fence: \nTexto claro(sin j) : el cifrado polybios me gusta menos\n";
    cout << "Cifrado: " << cifrado.polyBios("el cifrado polybios me gusta menos", "") << "\n\n";
}
