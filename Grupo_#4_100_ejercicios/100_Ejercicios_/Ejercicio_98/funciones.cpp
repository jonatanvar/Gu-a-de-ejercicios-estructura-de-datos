//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Implementa la validación de un número de teléfono según un formato específico (8 dígitos, guion opcional, prefijos de Honduras).
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.cpp` para el Ejercicio 98: 'Validar número de teléfono'. Incluye el nuevo bloque de encabezado, implementa las funciones `obtenerCadena`, `validarFormatoTelefono` (incluyendo lógica para limpieza, conteo/posición del guion, extracción de dígitos, longitud de 8 dígitos, y validación de prefijo para Honduras - 2, 3, 7, 8, 9), y `resolverEjercicio98` como se describe en el análisis. Usa <string>, <algorithm>, <cctype>, y <limits> donde sea apropiado. Asegura una limpieza adecuada del buffer para la entrada.

#include <iostream>  // Para operaciones de entrada/salida (cout, cin).
#include <string>    // Para el uso de std::string.
#include <algorithm> // Para std::remove y std::count.
#include <cctype>    // Para isdigit.
#include <limits>    // Para numeric_limits (validación de entrada).
#include "funciones.h" // Incluye el archivo de cabecera con los prototipos de funciones.

// Se asume el uso de namespace std para simplificar.
using namespace std;

// --- Funciones Auxiliares Generales ---

// Función para obtener una cadena de texto del usuario.
std::string obtenerCadena(const char* prompt) {
    std::string entrada;
    cout << prompt;
    // Usar getline para leer la línea completa, incluyendo espacios si los hubiera.
    getline(cin, entrada); 
    return entrada;
}

// --- Funciones de Validación del Número de Teléfono ---

// Función para validar el formato de un número de teléfono.
bool validarFormatoTelefono(const std::string& numero_crudo) {
    std::string numero = numero_crudo;

    // 1. Eliminar todos los espacios en blanco de la cadena.
    numero.erase(remove(numero.begin(), numero.end(), ' '), numero.end());

    // 2. Contar guiones y validar su posición.
    size_t count_hyphens = std::count(numero.begin(), numero.end(), '-');

    if (count_hyphens > 1) {
        cout << "  Error: El numero no puede contener mas de un guion.\n";
        return false;
    }

    if (count_hyphens == 1) {
        // Si hay un guion, debe estar en la posición 4 (índice 4).
        if (numero.find('-') != 4) {
            cout << "  Error: El guion debe estar en la posicion 5 (ej. XXXX-XXXX).\n";
            return false;
        }
    }

    // 3. Extraer solo los dígitos del número.
    std::string solo_digitos;
    for (char c : numero) {
        if (isdigit(c)) {
            solo_digitos += c;
        } else if (c != '-') { // Si no es un dígito y no es un guion, es un caracter no permitido.
            cout << "  Error: El numero contiene caracteres no numericos o guiones en posiciones invalidas.\n";
            return false;
        }
    }

    // 4. Validar la longitud de los dígitos.
    if (solo_digitos.length() != 8) {
        cout << "  Error: El numero debe contener exactamente 8 digitos.\n";
        return false;
    }

    // 5. Validar el prefijo (primer dígito para Honduras).
    if (solo_digitos.empty()) { // Debería haber sido detectado por la longitud, pero como seguridad.
        return false;
    }

    char primer_digito_char = solo_digitos[0];
    // Convertir char a int para comparación numérica
    int primer_digito_int = primer_digito_char - '0';

    if (!(primer_digito_int == 2 || primer_digito_int == 3 || primer_digito_int == 7 || primer_digito_int == 8 || primer_digito_int == 9)) {
        cout << "  Error: El numero debe iniciar con 2, 3, 7, 8 o 9 (prefijos de Honduras).\n";
        return false;
    }

    // Si todas las validaciones pasan
    return true;
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio98() {
    cout << "\n--- Ejercicio 98: Validar Numero de Telefono ---\n";
    cout << "Este programa valida numeros de telefono de 8 digitos con formato XXXX-XXXX (guion opcional).\n";
    cout << "Los numeros deben iniciar con 2, 3, 7, 8 o 9 (prefijos comunes en Honduras).\n";

    // Limpiar el buffer de entrada para asegurar que getline lea correctamente
    // después de una posible lectura de cin en main().
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    std::string telefono_ingresado = obtenerCadena("Ingresa un numero de telefono para validar: ");

    if (validarFormatoTelefono(telefono_ingresado)) {
        cout << "\nEl numero de telefono '" << telefono_ingresado << "' es VALIDO.\n";
    } else {
        cout << "\nEl numero de telefono '" << telefono_ingresado << "' es NO VALIDO.\n";
    }
    cout << "--------------------------------------------------------\n";
}