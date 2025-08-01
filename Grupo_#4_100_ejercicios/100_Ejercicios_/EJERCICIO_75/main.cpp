// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    Cola miCola = {-1, -1, 0};

    int opcion;

    cout << "Bienvenido al programa de Cola Circular. :)\n";
    cout << "Maximo 3 elementos para llenar \n";

    do {
        // Mostrar menú de operaciones de cola.
        cout << "\n--- Menu de Operaciones de Cola ---\n";
        cout << "1. Enqueue (Agregar elemento al final)\n";
        cout << "2. Dequeue (Eliminar y retornar elemento del frente)\n";
        cout << "3. Verificar si la cola esta vacia\n";
        cout << "4. Verificar si la cola esta llena\n";
        cout << "5. Salir\n";

        opcion = validarEntradaNumerica("Seleccione una opcion (1-5): ");

        // Estructura 'switch' para manejar las diferentes operaciones de la cola.
        switch (opcion) {
            case 1: { // Operación Enqueue (Agregar elemento)
                int valor = validarEntradaNumerica("Ingrese el valor a agregar a la cola: ");
                enqueue(miCola, valor); // Llama a la función para agregar.
                break;
            }
            case 2: { // Operación Dequeue (Eliminar elemento)
                dequeue(miCola);
                break;
            }
            case 3: // Verificar si la cola está vacía.
                if (estaVacia(miCola)) {
                    cout << "La cola esta vacia.\n";
                } else {
                    cout << "La cola NO esta vacia. Actualmente contiene " << miCola.contador << " elemento(s).\n";
                    cout << "Elemento en el frente: " << miCola.elementos[miCola.frente] << "\n";
                }
                break;
            case 4: // Verificar si la cola está llena.
                if (estaLlena(miCola)) {
                    cout << "La cola esta llena.\n";
                } else {
                    cout << "La cola NO esta llena. Le quedan " << (MAX_TAMANIO_COLA - miCola.contador) << " espacios.\n";
                }
                break;
            case 5:
                cout << "\nGracias por usar el programa. :)\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}