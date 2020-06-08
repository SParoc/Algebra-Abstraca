#pragma once
#include <string>
using namespace std;

class CifradoAfin
{
public:
  CifradoAfin();
  CifradoAfin(int, int);
  string cifrarMensaje(string mensaje);
  string descifrarMensaje(string mensajeCifrado);
  int getA(); int getB();
  string abc;

private:
  int a, b;
  void generarClaves();
  int mcd(int a, int b);
  int mod(int a, int b);
  int inversa(int a, int b);
};
