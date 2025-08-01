// Autor: Jorge Mendoza.
// Fecha: 22/07/2025
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa de gestion de puntos en un plano 2D. :)\n";

    do {
        Punto miPunto;

        cout << "\n--- Ingrese las coordenadas del punto ---\n";

        miPunto.x = validarEntradaNumerica("Ingrese la coordenada X del punto: ");

        miPunto.y = validarEntradaNumerica("Ingrese la coordenada Y del punto: ");

        cout << "\nEl punto ingresado es: (" << miPunto.x << ", " << miPunto.y << ")\n";

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}