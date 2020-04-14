#pragma once

#include <string>

class PrimerEjercicio
{
public:
	PrimerEjercicio();
	void cifrarMensaje();
	void descifrarMensaje();
	void responderPreguntaC();

private:
	std::string mensaje, mensajeCifrado, abc;
	int x;
};
