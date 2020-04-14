#include "Sexto_ejercicio.h"

#include <iostream>
#include <string>

using namespace std;

SextoEjercicio::SextoEjercicio()
{
	str = "Yo desaprobe el curso de Algebra Abstracta.";
}

void SextoEjercicio::cambiarString()
{
	cout << str << "\nCambio: \n";
	
	str.erase(3, 3);

	cout << str; 
}

