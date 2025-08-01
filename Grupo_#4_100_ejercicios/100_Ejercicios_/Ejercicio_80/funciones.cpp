//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Implementación de funciones para el recorrido postorden (izquierda-derecha-raíz) de un árbol binario de búsqueda.
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.cpp` para el Ejercicio 80: 'Recorrido postorden'. Incluye el nuevo bloque de encabezado, implementa las funciones `crearNodo`, `insertar` (como inserción en un BST), `recorridoPostorden`, `liberarArbol`, `obtenerEnteroValido`, y `resolverEjercicio80` como se describe en el análisis. Asegura una gestión de memoria adecuada.

#include <iostream>  // Para operaciones de entrada/salida (cout, cin).
#include <limits>    // Para numeric_limits (validación de entrada).
#include <string>    // Para std::string y std::to_string.
#include "funciones.h" // Incluye el archivo de cabecera con la definición de Nodo y prototipos.

// Se asume el uso de namespace std para simplificar.
using namespace std;

// --- Funciones Auxiliares Generales ---

// Función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de una lectura exitosa.
            break;
        }
    }
    return valor;
}

// --- Funciones de Árbol Binario ---

// Función para crear un nuevo nodo.
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Función para insertar un nodo en un árbol binario de búsqueda (BST).
// Retorna la nueva raíz del subárbol después de la inserción.
Nodo* insertar(Nodo* raiz, int dato) {
    // Si el árbol está vacío, crea un nuevo nodo y lo retorna como raíz.
    if (raiz == nullptr) {
        return crearNodo(dato);
    }

    // Si el dato es menor, va al subárbol izquierdo.
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    }
    // Si el dato es mayor, va al subárbol derecho.
    else if (dato > raiz->dato) { // Maneja solo inserciones de valores únicos o mayores.
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    // Si el dato es igual, no se inserta (se ignora para este BST simple).
    else {
        cout << "El valor " << dato << " ya existe en el arbol. Ignorando duplicado.\n";
    }

    // Retorna el puntero (sin cambios)
    return raiz;
}

// Función para realizar un recorrido en postorden (Izquierda-Derecha-Raíz).
void recorridoPostorden(Nodo* nodo) {
    // Caso base: si el nodo es nulo, no hay nada que recorrer.
    if (nodo == nullptr) {
        return;
    }

    // 1. Recorre el subárbol izquierdo.
    recorridoPostorden(nodo->izquierdo);

    // 2. Recorre el subárbol derecho.
    recorridoPostorden(nodo->derecho);

    // 3. Procesa (imprime) el nodo actual.
    cout << nodo->dato << " ";
}

// Función para liberar la memoria del árbol (postorden para evitar fugas de memoria).
void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    delete nodo; // Libera el nodo actual después de liberar a sus hijos.
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio80() {
    Nodo* raiz = nullptr; // Inicializa la raíz del árbol como nula.
    int num_elementos;
    int elemento;
    char opcion;

    cout << "\n--- Ejercicio 80: Recorrido Postorden de Arbol Binario ---\n";

    // Limpiar el buffer de entrada antes del primer menu de opciones.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Opciones para construir el árbol
    cout << "¿Deseas insertar elementos en el arbol? (s/n): ";
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer.

    if (opcion == 's' || opcion == 'S') {
        num_elementos = obtenerEnteroValido(std::string("¿Cuantos elementos deseas insertar en el arbol? ").c_str());
        for (int i = 0; i < num_elementos; ++i) {
            elemento = obtenerEnteroValido(std::string("Ingresa el elemento " + to_string(i + 1) + ": ").c_str());
            raiz = insertar(raiz, elemento); // Actualiza la raíz después de la inserción.
        }
    } else {
        // Árbol de ejemplo predefinido si el usuario no quiere insertar.
        // Elementos de ejemplo de Semana 8.pdf: 5, 3, 7, 6, 9, 15, 0
        cout << "Creando un arbol con elementos de ejemplo: 5, 3, 7, 6, 9, 15, 0\n";
        raiz = insertar(raiz, 5);
        raiz = insertar(raiz, 3);
        raiz = insertar(raiz, 7);
        raiz = insertar(raiz, 6);
        raiz = insertar(raiz, 9);
        raiz = insertar(raiz, 15);
        raiz = insertar(raiz, 0);
    }
    
    // Realizar y mostrar el recorrido postorden.
    cout << "\nRecorrido Postorden (Izquierda-Derecha-Raiz): ";
    recorridoPostorden(raiz);
    cout << "\n";

    // Liberar la memoria asignada al árbol para evitar fugas.
    liberarArbol(raiz);
    cout << "Memoria del arbol liberada.\n";
    cout << "--------------------------------------------------------\n";
}