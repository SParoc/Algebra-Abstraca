#include <iostream>
#include "Afin.h"

int main()
{
	CifradoAfin emisor;
	CifradoAfin receptor(emisor.getA(), emisor.getB());
	string mensaje, mensajeCifrado;

	cout << "\nIntroducir mensaje: ";
	getline(cin, mensaje);
	cout << "\nClave a: " << emisor.getA() << "\nClave b: " << emisor.getB();
	mensajeCifrado = emisor.cifrarMensaje(mensaje);
	cout<<"\nMensaje cifrado: "<< mensajeCifrado;

	cout << "\n\nDescifrar mensaje cifrado: ";
	cout << "\nClave a (inversa): " << receptor.getA() << "\nClave b: " << receptor.getB();
	cout<<"\nMensaje descifrado: "<< receptor.descifrarMensaje(mensajeCifrado);

}
