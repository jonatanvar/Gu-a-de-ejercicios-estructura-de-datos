//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Programa que concatena dos cadenas de caracteres sin usar funciones de biblioteca estándar.

#include <iostream> // Se incluye la librería estándar para operaciones de entrada/salida.
#include <limits>   // Se incluye esta librería para numeric_limits y streamsize (necesarias para la validación de entrada).
#include <string>
#include "funciones.h" // Se incluye el archivo de cabecera que contiene las declaraciones de funciones.
using namespace std;

int main() {
    cout << "Bienvenido al Ejercicio 38 - Concatenar Dos Cadenas\n"; // Mensaje de bienvenida personalizado.
    char continuar; // Variable para controlar el bucle do...while.

    do {
        resolverEjercicio38(); // Llama a la función que contiene la lógica principal del ejercicio.

        // Pregunta al usuario si desea continuar con otra ejecución del programa.
        cout << "\n¿Deseas continuar? (s/n): ";
        cin >> continuar;

        // Después de leer 's' o 'n', hay un '\n' en el buffer que puede afectar la siguiente lectura de cadena.
        // Se limpia el buffer, pero solo si no hay un error en cin (es decir, si se leyó 's' o 'n' correctamente).
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Si hubo un error (ej. el usuario ingresó algo que no es un carácter),
            // se limpia el error y el buffer para que no afecte el siguiente intento.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (continuar == 'S' || continuar == 's'); // El bucle continúa si el usuario ingresa 's' o 'S'.

    cout << "Gracias por usar el programa. Adios! \n"; // Mensaje de despedida final.
    return 0; // El programa termina con éxito.
}