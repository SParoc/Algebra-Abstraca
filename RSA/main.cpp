#include "RSA_Class.h"

int main()
{
    RSA claves;
    RSA rsa(claves.get_e(), claves.get_N(), claves.get_phiN());
    
    string mensaje, mensajeCifrado;
    cout << "\n\nIngrese mensaje: ";
    getline(cin, mensaje);

    cout << "Clave publica = <" << claves.get_e() << ", " << claves.get_N() << ">\n";
    cout << "Clave privada = <" << rsa.get_d() << ", " << claves.get_N() << ">\n";
    cout << "phiN = " << claves.get_phiN();
    mensajeCifrado = rsa.cifrar(mensaje);
    cout << "\n\nCifrado: "<<mensajeCifrado;
    cout << "\n\nDescifrado: "<< rsa.descifrar(mensajeCifrado) << endl << endl;
}
