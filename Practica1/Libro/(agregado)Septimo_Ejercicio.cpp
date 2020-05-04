#include <iostream>
#include <string>

using namespace std;

bool ascendente(string arr, string b);
bool descendente(string arr, string b);
void ordenamiento(string arr[], int n, bool(*comparar)(string, string));

int main ()
{
    string arr[8] = {"computadora", "sebastian", "rocha", "videojuego", "amanecer",
									"galleta", "paz", "alumno"};

		for(int i = 0; i < 8; i++)
		{
				cout << arr[i] << " ";
		}
		cout << "\n";

    int opcion;
    cout << "\nOrdenar de forma...\n1. Ascendente\n2. Descendente\n";
    cin >> opcion;

		switch (opcion) {
			case 1:
				ordenamiento(arr,8,ascendente);
				break;
			case 2:
				ordenamiento(arr,8,descendente);
				break;
			default:
				break;
		}

		cout<<"\n";

		for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool ascendente(string arr, string b)
{
    return (arr.compare(b) < 0);
}

bool descendente(string arr, string b)
{
    return (arr.compare(b) > 0);
}

void ordenamiento(string arr[], int n, bool(*comparar)(string, string))
{
    int selecc;

    for (int i = 0; i < n-1; i++)
    {
        selecc = i;
        for (int j = i+1; j < n; j++)
				{
					if (!(*comparar)(arr[selecc],arr[j]))
					{
							selecc = j;
					}
				}
        swap(arr[selecc], arr[i]);
    }
}
