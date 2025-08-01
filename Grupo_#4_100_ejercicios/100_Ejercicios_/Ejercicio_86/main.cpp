//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Programa principal para demostrar la eliminación de un nodo en un Árbol Binario de Búsqueda (ABB).
//Autoría: Gemini
//Prompt: Genera el archivo `main.cpp` para el Ejercicio 86: 'Eliminar nodo en ABB'. Incluye el nuevo bloque de encabezado, llama a `resolverEjercicio86` en un bucle para permitir múltiples ejecuciones, y maneja la entrada del usuario para la continuación.

#include <iostream>  // Se incluye la librería estándar para operaciones de entrada/salida.
#include <limits>    // Se incluye esta librería para numeric_limits y streamsize (necesarias para la validación de entrada).
#include <string>
#include "funciones.h" // Se incluye el archivo de cabecera que contiene las declaraciones de funciones y estructuras.
using namespace std;

int main() {
    cout << "Bienvenido al Ejercicio 86 - Eliminar Nodo en ABB\n"; // Mensaje de bienvenida personalizado.
    char continuar; // Variable para controlar el bucle do...while.

    do {
        resolverEjercicio86(); // Llama a la función que contiene la lógica principal del ejercicio.

        // Pregunta al usuario si desea continuar con otra ejecución del programa.
        cout << "\n¿Deseas ejecutar de nuevo el Ejercicio 86? (s/n): ";
        cin >> continuar;

        // Limpia el buffer de entrada para evitar problemas con futuras lecturas.
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (continuar == 'S' || continuar == 's'); // El bucle continúa si el usuario ingresa 's' o 'S'.

    cout << "Gracias por usar el programa. ¡Adiós!\n"; // Mensaje de despedida final.
    return 0; // El programa termina con éxito.
}