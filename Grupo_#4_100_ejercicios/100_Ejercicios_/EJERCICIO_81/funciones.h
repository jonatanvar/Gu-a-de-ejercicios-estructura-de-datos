// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definición de la estructura (struct) para un nodo de un Árbol Binario de Búsqueda (BST).
// Cada nodo contiene un 'valor' y punteros a sus hijos 'izquierda' y 'derecha'.
struct Nodo {
    int valor;    // El dato almacenado en el nodo.
    Nodo* izquierda; // Puntero al subárbol izquierdo (valores menores).
    Nodo* derecha;   // Puntero al subárbol derecho (valores mayores).
};

// Declaración de la función para insertar un nuevo nodo en el árbol BST.
// Recibe un puntero a la raíz del árbol y el valor a insertar.
// Retorna el puntero a la nueva raíz del árbol (o la misma si no cambió).
Nodo* insertarNodo(Nodo* raiz, int valor);

// Declaración de la función para buscar un valor en el árbol BST.
// Recibe un puntero a la raíz del árbol y el valor a buscar.
// Retorna 'true' si el valor se encuentra en el árbol, 'false' en caso contrario.
bool buscarNodo(Nodo* raiz, int valorBuscado);

// Declaración de la función para validar y leer una entrada numérica (int).
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor int válido.
int validarEntradaNumerica(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
// Retorna 1 para 'Sí', 2 para 'No'. Incluye validación de entrada.
int preguntarRepetir();

#endif // FUNCIONES_H