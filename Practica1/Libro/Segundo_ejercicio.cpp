#include "Segundo_ejercicio.h"

#include <string>
#include <iostream>

using namespace std;

SegundoEjercicio::SegundoEjercicio()
{
	nombre = apellido = Ncompleto = "";
}

void SegundoEjercicio::ingresarDatos()
{
	cout << "Ingresar nombre(s): \n";
	getline(cin, nombre);
	cout << "Ingresar apellidos: \n";
	getline(cin, apellido);
}

void SegundoEjercicio::nombreCompleto()
{
	Ncompleto = nombre + ' ' + apellido;

	cout << "\nNombre completo: " << Ncompleto;
}
