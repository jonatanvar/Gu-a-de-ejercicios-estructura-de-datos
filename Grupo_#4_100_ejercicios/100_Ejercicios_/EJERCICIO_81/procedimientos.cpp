// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para insertar un nuevo nodo en el árbol BST de forma recursiva.
// Un BST mantiene los valores menores a la izquierda y los mayores a la derecha.
Nodo* insertarNodo(Nodo* raiz, int valor) {
    // Caso base: Si la raíz es NULL (subárbol vacío), se crea un nuevo nodo y se devuelve.
    if (raiz == nullptr) {
        Nodo* nuevoNodo = new Nodo; // Crea un nuevo nodo en la memoria dinámica.
        nuevoNodo->valor = valor;   // Asigna el valor al nuevo nodo.
        nuevoNodo->izquierda = nullptr; // Inicializa los punteros de los hijos a NULL.
        nuevoNodo->derecha = nullptr;
        return nuevoNodo; // Retorna el nuevo nodo como la raíz de este subárbol.
    }

    // Si el valor a insertar es menor que el valor de la raíz, se inserta en el subárbol izquierdo.
    if (valor < raiz->valor) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    }
    // Si el valor a insertar es mayor que el valor de la raíz, se inserta en el subárbol derecho.
    else if (valor > raiz->valor) { // No permite duplicados si es 'else if (valor > raiz->valor)'
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }
    // Si el valor ya existe (valor == raiz->valor), no se hace nada para evitar duplicados en este ejemplo simple.
    // Podrías manejar los duplicados de otra forma si fuera necesario.

    return raiz; // Retorna la raíz actual sin cambios (si el valor ya existía) o con el nuevo nodo adjunto.
}

// Implementación de la función para buscar un valor en el árbol BST de forma recursiva.
// Aprovecha la propiedad de un BST para buscar eficientemente.
bool buscarNodo(Nodo* raiz, int valorBuscado) {
    // Caso base 1: Si la raíz es NULL, el valor no se encontró en este subárbol.
    if (raiz == nullptr) {
        return false;
    }

    // Caso base 2: Si el valor de la raíz coincide con el valor buscado, se encontró.
    if (raiz->valor == valorBuscado) {
        return true;
    }

    // Si el valor buscado es menor que el valor de la raíz, busca en el subárbol izquierdo.
    if (valorBuscado < raiz->valor) {
        return buscarNodo(raiz->izquierda, valorBuscado);
    }
    // Si el valor buscado es mayor que el valor de la raíz, busca en el subárbol derecho.
    else { // valorBuscado > raiz->valor
        return buscarNodo(raiz->derecha, valorBuscado);
    }
}

// Implementación de la función para validar y leer una entrada numérica (int).
// Solicita al usuario un número y lo valida. Si la entrada es inválida, muestra un error y pide de nuevo.
int validarEntradaNumerica(const char* mensaje) {
    int numero; // Variable para almacenar el número ingresado.

    while (true) { // Bucle infinito hasta que se ingrese un número válido.
        cout << mensaje; // Muestra el mensaje proporcionado.
        cin >> numero;   // Intenta leer el número.

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