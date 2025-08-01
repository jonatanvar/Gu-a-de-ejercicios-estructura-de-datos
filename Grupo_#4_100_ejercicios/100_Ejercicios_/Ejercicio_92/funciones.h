//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Declaración de prototipos de funciones para el cálculo del Coeficiente de Correlación de Pearson.
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.h` para el Ejercicio 92: 'Coeficiente de Pearson'. Incluye el nuevo bloque de encabezado, y declara las funciones `obtenerEnteroValido`, `obtenerDobleValido`, `solicitarDatos`, `calcularMedia`, `calcularDesviacionEstandar`, `calcularCovarianza`, `calcularCoeficientePearson`, y `resolverEjercicio92` como se describe en el análisis. Asegura necesarias includes como <vector> y <string>.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector> // Para el uso de std::vector.
#include <string> // Para el uso de std::string.

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// Prototipo de la función para obtener y validar un número de punto flotante (double).
double obtenerDobleValido(const char* prompt);

// Prototipo de la función para solicitar un conjunto de datos (vector de doubles).
std::vector<double> solicitarDatos(int n, const std::string& varName);

// --- Prototipos de Funciones de Cálculo Estadístico ---

// Prototipo de la función para calcular la media de un conjunto de datos.
double calcularMedia(const std::vector<double>& datos);

// Prototipo de la función para calcular la desviación estándar de un conjunto de datos.
double calcularDesviacionEstandar(const std::vector<double>& datos, double media);

// Prototipo de la función para calcular la covarianza entre dos conjuntos de datos.
double calcularCovarianza(const std::vector<double>& x, const std::vector<double>& y, double mediaX, double mediaY);

// Prototipo de la función para calcular el Coeficiente de Correlación de Pearson.
double calcularCoeficientePearson(const std::vector<double>& x, const std::vector<double>& y);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 92.
void resolverEjercicio92();

#endif // FUNCIONES_H