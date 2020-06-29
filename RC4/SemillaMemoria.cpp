#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        MEMORYSTATUSEX estado;

        estado.dwLength = sizeof(estado);

        GlobalMemoryStatusEx(&estado);

        system("cls");
        cout << "\Porcentaje de memoria RAM usada: "<<estado.dwMemoryLoad<<"%";
        cout << "\nEspacio total en memoria RAM: " << estado.ullTotalPhys * 8 << " bits";
        cout << "\nEspacio libre en memoria RAM: " << estado.ullAvailPhys * 8 << " bits";
        cout << "\nEspacio utilizado en memoria RAM: " << (estado.ullTotalPhys * 8) - (estado.ullAvailPhys * 8) << " bits";
        cout << "\nEspacio total en el archivo de paginacion: " << estado.ullTotalPageFile * 8 << " bits";
        cout << "\nEspacio libre en el archivo de paginacion: " << estado.ullAvailPageFile * 8 << " bits";
        cout << "\nEspacio utilizado en el archivo de paginacion: " << (estado.ullTotalPageFile * 8) - (estado.ullAvailPageFile * 8) << " bits";

    }
}
