#include "Primer_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

PrimerEjercicio::PrimerEjercicio()
{
	abc = "abcdefghijklmnopqrstuvwxyz";
	mensaje = mensajeCifrado = "";
}

void PrimerEjercicio::cifrarMensaje()
{
	cout << "Introducir mensaje para cifrarlo: \n";
	getline(cin, mensaje);

	for (int i = 0; i < mensaje.length(); i++)
	{
		x = abc.find(mensaje[i]);
		x += 13;
		if (x >= 26)
		{
			x = x % 26;
		}
		if (mensaje[i] != ' ')
		{
			mensaje[i] = abc[x];
		}
	}
	cout << "\nEl mensaje cifrado con rot13 es: \n"<<mensaje;
}

void PrimerEjercicio::descifrarMensaje()
{
	cout << "Introducir mensaje para descifrarlo: \n";
	getline(cin, mensajeCifrado);

	for (int i = 0; i < mensajeCifrado.length(); i++)
	{
		x = abc.find(mensajeCifrado[i]);
		x -= 13;

		if (x < 0)
		{
			x = 26+x;
		}
		if (mensajeCifrado[i] != ' ')
		{
			mensajeCifrado[i] = abc[x];
		}
	}
	cout << "\nEl mensaje descifrado con rot13 es: \n" << mensajeCifrado;
}

void PrimerEjercicio::responderPreguntaC()
{

	cout << "\nRespuesta a preguna C): Si no se conociera la clave de cifrado, seria  muy dificil descifrar el mensaje, "
		<< "pero no imposible. Habria que relacionar las letras del mensaje cifrado con las del alfabeto normal, "
		<< "para ver si se encuentrar coincidencias en las incidencias de ciertas letras en las palabras. "
		<< "Por ejemplo, las vocales son las letras mas comunes en una frase, y conociendo eso ya se puede ir relacionando "
		<< "y probando. Obviamente esta tarea seria mucho mas facil con una supercomputadora y una buena inteligencia artificial." << endl;

}
