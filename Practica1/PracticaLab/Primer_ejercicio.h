#pragma once

#include <string>

class PrimerYSegundoEjercicio
{
public:
	PrimerYSegundoEjercicio();
	~PrimerYSegundoEjercicio();

	void leerString();
	void StringACharArray();
	void CharArrayAString();
	void SegundoEjercicio();

private:
	std::string str, str2;
	char* charArray;
	int x;
};
