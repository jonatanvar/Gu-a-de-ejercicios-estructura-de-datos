//Nombre: [Erinson Alvarez
//Fecha: 30/07/2025
//Descripción: Declaración de prototipos de funciones y la estructura del nodo para el ejercicio Eliminar Nodo en Árbol Binario de Búsqueda (ABB).
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.h` para el Ejercicio 86: 'Eliminar nodo en ABB'. Incluye el nuevo bloque de encabezado, define la `Nodo` struct, y declara las funciones `obtenerEnteroValido`, `crearNodo`, `insertar`, `recorridoInorden`, `encontrarMinimo`, `eliminarNodo`, `liberarArbol`, y `resolverEjercicio86` como se describe en el análisis.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// --- Estructura para el Nodo del Árbol Binario ---
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// --- Prototipos de Funciones de Árbol Binario de Búsqueda (ABB) ---

// Prototipo para crear un nuevo nodo del árbol.
Nodo* crearNodo(int dato);

// Prototipo para insertar un nodo en un árbol binario de búsqueda.
// Retorna la nueva raíz del subárbol después de la inserción.
Nodo* insertar(Nodo* raiz, int dato);

// Prototipo para encontrar el nodo con el valor mínimo en un subárbol.
Nodo* encontrarMinimo(Nodo* nodo);

// Prototipo para eliminar un nodo de un ABB.
// Retorna la nueva raíz del subárbol después de la eliminación.
Nodo* eliminarNodo(Nodo* raiz, int valor);

// Prototipo para realizar un recorrido en inorden (Izquierda-Raíz-Derecha).
void recorridoInorden(Nodo* nodo);

// Prototipo para liberar la memoria de todos los nodos del árbol.
void liberarArbol(Nodo* nodo);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 86.
void resolverEjercicio86();

#endif // FUNCIONES_H