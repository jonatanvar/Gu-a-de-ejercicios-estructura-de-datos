#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        Fraccion fraccion1, fraccion2, resultado;

        cout << "\nIngresa la primera fraccion:" << endl;
        leerFraccion(fraccion1, "Fraccion 1");

        cout << "\nIngresa la segunda fraccion:" << endl;
        leerFraccion(fraccion2, "Fraccion 2");

        resultado = multiplicarFracciones(fraccion1, fraccion2);

        cout << "\nEl producto de ";
        mostrarFraccion(fraccion1);
        cout << " * ";
        mostrarFraccion(fraccion2);
        cout << " es: ";
        mostrarFraccion(resultado);
        cout << endl;

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}