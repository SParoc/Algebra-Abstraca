#include <iostream>
#include <cstdlib>

using namespace std;

int mod(int a, int b);
void div_int(int a, int n, int &q, int &r);

int main ()
{
  int a, n, q = 0, r = 0;
  cout<<"a: "; cin>>a;
  cout<<"n: "; cin>>n;

  div_int(a,n,q,r);

  cout<<"\n"<<a<<" = "<< q << " * " << n << " + " << r;

}

int mod(int a, int b)
{
	int m;
	m = a + ((abs(a / b) + 1) * b);
	return m - ((m / b) * b);
}

void div_int(int a, int n, int &q, int &r)
{
  r = mod(a,n);
  q = (a - r)/n;
}
