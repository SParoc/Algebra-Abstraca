#include "RSA.h"

int main()
{
    int bits = 0;
    //cout << "Ingresar numero de bits: "; cin >> bits;
    RSA receptor(bits);
    RSA emisor(receptor.e, receptor.N);

    string msg, cif;
    cout << "Escriba el mensaje: ";
    getline(cin.ignore(), msg);
    cout << "\n\ne : " << receptor.e;
    cout << "\n\nN: " << receptor.N;
    cif = emisor.cifrar(msg);
    cout << "\n\nMENSAJE CIFRADO: "<<cif << endl;
    cout<<"\n\nMENSAJE DESCIFRADO: "<<receptor.descifrar(cif);
}


