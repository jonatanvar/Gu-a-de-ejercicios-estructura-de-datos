#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        int cantidadEstudiantes;
        Estudiante* grupo = 0;

        cout << "\nCuantos estudiantes deseas ingresar: ";
        cin >> cantidadEstudiantes;
        funcionvalidarCantidadEstudiantes(cantidadEstudiantes);
        cin.ignore(100, '\n');

        grupo = new Estudiante[cantidadEstudiantes];

        leerArregloEstudiantes(grupo, cantidadEstudiantes);
        mostrarArregloEstudiantes(grupo, cantidadEstudiantes);

        delete[] grupo;
        grupo = 0;

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}