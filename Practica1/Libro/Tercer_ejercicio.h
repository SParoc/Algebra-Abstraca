#pragma once

#include <string>

class TercerEjercicio
{
public:
	TercerEjercicio();
	void jugar();
	void ahorcar(int intentos);

private:

	std::string palabra, letra, strx
		, horca[2] = { "-----------\n", "          |\n          |\n          |\n" }
		, persona[7] = { "          O\n", "         /", "|","\\ \n",
						"          |\n","         /"," \\\n\n" };
	int intentos, x;
};
