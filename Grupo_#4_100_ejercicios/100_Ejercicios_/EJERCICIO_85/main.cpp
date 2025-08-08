//
// Created by Admin on 7/17/2025.
//
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    Nodo* raiz = nullptr;
    int opcion;

    cout << "Bienvenido al programa de Arbol Binario de Busqueda (ABB). :)\n";

    do {
        // Mostrar menú de opciones.
        cout << "\n--- Menu de Operaciones de ABB ---\n";
        cout << "1. Insertar un valor en el arbol\n";
        cout << "2. Buscar un valor en el arbol\n";
        cout << "3. Salir\n";

        // Solicita y valida la opción del menú.
        opcion = validarEntradaNumericaInt("Seleccione una opcion (1-3): ");

        // Estructura 'switch' para manejar las diferentes operaciones del árbol.
        switch (opcion) {
            case 1: { // Insertar un valor.
                int valor = validarEntradaNumericaInt("Ingrese el valor a insertar en el arbol: ");
                raiz = insertarNodo(raiz, valor); // Llama a la función para insertar.
                cout << "Valor " << valor << " insertado.\n";
                break;
            }
            case 2: { // Buscar un valor.
                if (raiz == nullptr) {
                    cout << "El arbol esta vacio. No hay elementos para buscar.\n";
                    break;
                }
                int valorBuscar = validarEntradaNumericaInt("Ingrese el valor a buscar en el arbol: ");
                if (buscarNodo(raiz, valorBuscar)) { // Llama a la función para buscar.
                    cout << "El valor " << valorBuscar << " SI se ha encontrado en el arbol.\n";
                } else {
                    cout << "El valor " << valorBuscar << " NO se ha encontrado en el arbol.\n";
                }
                break;
            }
            case 3: // Salir del programa.
                cout << "\nGracias por usar el programa. :)\n";
                break;
            default: // Opción no válida.
                cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}