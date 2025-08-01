// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    Pila miPila{};
    miPila.cima = -1;

    int opcion;

    cout << "Bienvenido al programa de Pila. :)\n";

    do {
        // Mostrar menú de opciones al usuario.
        cout << "\n--- Menu de Operaciones de Pila ---\n";
        cout << "1. Push (Agregar elemento)\n";
        cout << "2. Pop (Eliminar y retornar elemento superior)\n";
        cout << "3. Verificar si la pila esta vacia\n";
        cout << "4. Salir\n";

        opcion = static_cast<int>(validarEntradaNumerica("Seleccione una opcion (1-4): "));

        switch (opcion) {
            case 1: // Operación Push (Agregar elemento)
                if (estaLlena(miPila)) { // Verifica si la pila está llena antes de intentar agregar.
                    cout << "Error: La pila esta llena. No se puede agregar mas elementos.\n";
                } else {
                    // Solicita el valor a agregar y lo valida.
                    long long valor = validarEntradaNumerica("Ingrese el valor a agregar a la pila: ");
                    miPila.cima++; // Incrementa el índice de la cima.
                    miPila.elementos[miPila.cima] = static_cast<int>(valor);
                    cout << "Elemento " << valor << " agregado a la pila.\n";
                }
                break;
            case 2: // Operación Pop (Eliminar y retornar elemento superior)
                if (estaVacia(miPila)) { // Verifica si la pila está vacía antes de intentar eliminar.
                    cout << "Error: La pila esta vacia. No se puede eliminar elementos.\n";
                } else {
                    int elementoEliminado = miPila.elementos[miPila.cima];
                    miPila.cima--; // Decrementa el índice de la cima, "eliminando" lógicamente el elemento.
                    cout << "Elemento " << elementoEliminado << " eliminado de la pila.\n";
                }
                break;
            case 3: // Verificar si la pila está vacía.
                if (estaVacia(miPila)) {
                    cout << "La pila esta vacia.\n";
                } else {
                    // Muestra cuántos elementos hay actualmente en la pila.
                    cout << "La pila NO esta vacia. Actualmente contiene " << (miPila.cima + 1) << " elemento(s).\n";
                }
                break;
            case 4: // Opción para salir del programa.
                cout << "\nGracias por usar el programa. :)\n";
                break;
            default: // Mensaje para opciones no válidas.
                cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
    return 0;
}