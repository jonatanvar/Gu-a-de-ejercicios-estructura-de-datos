//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Programa principal para demostrar la validación de un número de teléfono según un formato específico.
//Autoría: Gemini
//Prompt: Genera el archivo `main.cpp` para el Ejercicio 98: 'Validar número de teléfono'. Incluye el nuevo bloque de encabezado, llama a `resolverEjercicio98` en un bucle para permitir múltiples ejecuciones, y maneja la entrada del usuario para la continuación. Asegura una limpieza adecuada del buffer.

#include <iostream>  // Se incluye la librería estándar para operaciones de entrada/salida.
#include <limits>    // Se incluye esta librería para numeric_limits y streamsize (necesarias para la validación de entrada).
#include "funciones.h" // Se incluye el archivo de cabecera que contiene las declaraciones de funciones.
using namespace std;

int main() {
    cout << "Bienvenido al Ejercicio 98 - Validar Numero de Telefono\n"; // Mensaje de bienvenida personalizado.
    char continuar; // Variable para controlar el bucle do...while.

    do {
        resolverEjercicio98(); // Llama a la función que contiene la lógica principal del ejercicio.

        // Pregunta al usuario si desea continuar con otra ejecución del programa.
        cout << "\n¿Deseas ejecutar de nuevo el Ejercicio 98? (s/n): ";
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