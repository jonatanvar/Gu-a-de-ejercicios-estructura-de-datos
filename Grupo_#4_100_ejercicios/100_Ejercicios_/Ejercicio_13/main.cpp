//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Programa que determina e imprime el menor valor entre tres números ingresados.

#include <iostream>
#include <limits>   
#include "funciones.h" // Se incluye el archivo de cabecera que contiene las declaraciones de funciones.
using namespace std;

int main() {
    cout << "Bienvenido al Ejercicio 13 - Menor de Tres Numeros\n"; // Mensaje de bienvenida personalizado.
    char continuar; // Variable para controlar el bucle do...while.

    do {
        resolverEjercicio13(); // Llama a la función que contiene la lógica principal del ejercicio.

        // Pregunta al usuario si desea continuar con otra ejecución del programa.
        cout << "\n¿Deseas continuar? (s/n): ";
        cin >> continuar;

        // Limpia el buffer de entrada para evitar problemas con futuras lecturas.
        // Se asume que el usuario ingresará un solo carácter 's' o 'n' seguido de Enter.
        // Si hay más caracteres, esta línea limpiará el resto del buffer.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continuar == 'S' || continuar == 's'); // El bucle continúa si el usuario ingresa 's' o 'S'.

    cout << "Gracias por usar el programa. Adios! \n"; // Mensaje de despedida final.
    return 0; // El programa termina con éxito.
}