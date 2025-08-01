//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Declaración de prototipos de funciones para la validación de un número de teléfono.
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.h` para el Ejercicio 98: 'Validar número de teléfono'. Incluye el nuevo bloque de encabezado, y declara las funciones `obtenerCadena`, `validarFormatoTelefono`, y `resolverEjercicio98` como se describe en el análisis. Asegura necesarias includes como <string>.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para el uso de std::string.

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener una cadena de texto del usuario.
std::string obtenerCadena(const char* prompt);

// --- Prototipos de Funciones de Validación del Número de Teléfono ---

// Prototipo de la función para validar el formato de un número de teléfono.
bool validarFormatoTelefono(const std::string& numero_crudo);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 98.
void resolverEjercicio98();

#endif // FUNCIONES_H