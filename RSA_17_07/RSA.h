#include "Funciones.h"
#include "RC4.h"

class RSA
{
public:
	RSA(int bits);
	RSA(ZZ _e, ZZ _N);
	string cifrar(string mensaje);
	string descifrar(string mensajeCifrado);
	void generarClaves(int bits);
	string firmar(string mensaje);
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	ZZ e, N;
private:
	ZZ p, q, d, phiN;

};
