// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para determinar si un año es bisiesto.
// Un año es bisiesto si es divisible por 4,
// a menos que sea divisible por 100 pero no por 400.
bool esBisiesto(int anio) {
    // Si el año es menor o igual a 0, no lo consideramos bisiesto en este contexto.
    if (anio <= 0) {
        return false;
    }
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Implementación de la función para validar si una fecha es correcta.
// Verifica rangos de día, mes y año, y considera años bisiestos.
bool validarFecha(int dia, int mes, int anio) {
    // 1. Validar el año: Un año debe ser positivo. Podemos añadir un límite superior si es necesario.
    if (anio <= 0) {
        return false;
    }

    // 2. Validar el mes: El mes debe estar entre 1 y 12.
    if (mes < 1 || mes > 12) {
        return false;
    }

    // 3. Validar el día según el mes.
    // Usamos un switch para manejar los diferentes números de días por mes.
    switch (mes) {
        case 1:  // Enero
        case 3:  // Marzo
        case 5:  // Mayo
        case 7:  // Julio
        case 8:  // Agosto
        case 10: // Octubre
        case 12: // Diciembre
            // Estos meses tienen 31 días.
            if (dia < 1 || dia > 31) {
                return false;
            }
            break;
        case 4:  // Abril
        case 6:  // Junio
        case 9:  // Septiembre
        case 11: // Noviembre
            // Estos meses tienen 30 días.
            if (dia < 1 || dia > 30) {
                return false;
            }
            break;
        case 2:  // Febrero
            // Febrero tiene 29 días en años bisiestos, 28 en años comunes.
            if (esBisiesto(anio)) {
                if (dia < 1 || dia > 29) {
                    return false;
                }
            } else {
                if (dia < 1 || dia > 28) {
                    return false;
                }
            }
            break;
        default:
            // Esto no debería ocurrir si el mes ya se validó entre 1 y 12.
            return false;
    }

    // Si todas las validaciones pasan, la fecha es válida.
    return true;
}

// Implementación de la función para validar y leer una entrada numérica entera.
// Solicita al usuario un número entero y lo valida.
int validarEntradaNumericaInt(const char* mensaje) {
    int numero; // Variable para almacenar el número ingresado.

    while (true) { // Bucle infinito hasta que se ingrese un número válido.
        cout << mensaje; // Muestra el mensaje proporcionado.
        cin >> numero;   // Intenta leer el número entero.

        // Verifica si la lectura falló (ej. se ingresó texto en lugar de números).
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero valido." << endl; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de 'cin'.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer de entrada.
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura exitosa.
            break; // Sale del bucle si la entrada es válida.
        }
    }
    return numero; // Retorna el número válido.
}

// Implementación de la función para preguntar si el usuario desea repetir el programa.
// Contiene un bucle de validación para asegurar una entrada correcta (1 o 2).
int preguntarRepetir() {
    int repetir; // Opción del usuario: 1 para sí, 2 para no.

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir; // Intenta leer la entrada del usuario.

        // Valida si la entrada es un número y está en el rango [1, 2].
        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error del flujo de entrada.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer.
        } else if (repetir < 1 || repetir > 2) { // Validación de rango después de la validación numérica.
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura válida.
            break; // Sale del bucle de validación.
        }
    }
    return repetir; // Retorna la opción válida.
}