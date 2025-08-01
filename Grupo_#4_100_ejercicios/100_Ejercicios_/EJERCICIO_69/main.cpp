// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    Cola miCola = {-1, -1, 0};

    int opcion;
    cout << "Bienvenido al programa de Cola (Enqueue). :)\n";

    do {
        // Mostrar menú de opciones al usuario.
        cout << "\n--- Menu de Operaciones de Cola ---\n";
        cout << "1. Enqueue (Agregar elemento al final)\n";
        cout << "2. Salir\n";

        opcion = validarEntradaNumerica("Seleccione una opcion (1-2): ");

        // Estructura 'switch' para manejar las diferentes operaciones de la cola.
        switch (opcion) {
            case 1: { // Operación Enqueue (Agregar elemento)
                int valor = validarEntradaNumerica("Ingrese el valor a agregar a la cola: ");
                enqueue(miCola, valor);
                break;
            }
            case 2: // Opción para salir del programa.
                cout << "\nGracias por usar el programa. :)\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }
    } while (opcion != 2);
    return 0;
}
