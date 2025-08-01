//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Programa principal para demostrar el ordenamiento de un arreglo en forma descendente usando el algoritmo de burbuja.

#include <iostream> // Se incluye la librería estándar para operaciones de entrada/salida.
#include <limits>   // Se incluye esta librería para numeric_limits y streamsize (necesarias para la validación de entrada).
#include <algorithm>
#include "funciones.h" // Se incluye el archivo de cabecera que contiene las declaraciones de funciones y constantes.
using namespace std;

int main() {
    cout << "Bienvenido al Ejercicio 32 - Ordenar Arreglo Descendente (Burbuja)\n"; // Mensaje de bienvenida personalizado.
    char continuar; // Variable para controlar el bucle do...while.

    do {
        resolverEjercicio32(); // Llama a la función que contiene la lógica principal del ejercicio.

        // Pregunta al usuario si desea continuar con otra ejecución del programa.
        cout << "\n¿Deseas continuar? (s/n): ";
        cin >> continuar;

        // Limpia el buffer de entrada para evitar problemas con futuras lecturas.
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (continuar == 'S' || continuar == 's'); // El bucle continúa si el usuario ingresa 's' o 'S'.

    cout << "Gracias por usar el programa. Adiós!\n"; // Mensaje de despedida final.
    return 0; // El programa termina con éxito.
}