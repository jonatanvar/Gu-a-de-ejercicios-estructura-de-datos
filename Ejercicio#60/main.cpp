//Nombre: Jonatan Varela
//Fecha: 13/07/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
    Fraccion f;
    char continuar;

    do {
        cout << "\nINGRESE UNA FRACCION PARA SIMPLIFICAR\n";
        cout << "Numerador: ";
        cin >> f.numerador;

        cout << "Denominador: ";
        cin >> f.denominador;

        if(f.denominador == 0) {
            cout << "Error: El denominador no puede ser cero.\n";
            continue;
        }

        cout << "\nFraccion original: ";
        mostrarFraccion(f);

        simplificarFraccion(f);

        cout << "Fraccion simplificada: ";
        mostrarFraccion(f);

        cout << "\nDesea simplificar otra fraccion? (s/n): ";
        cin >> continuar;

    } while(continuar == 's' || continuar == 'S');

    cout << "Fin del programa.\n";
    return 0;
}