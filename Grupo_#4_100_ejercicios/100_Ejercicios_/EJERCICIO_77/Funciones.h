#ifndef FUNCIONES_H
#define FUNCIONES_H

// Solo necesitamos iostream para la definicion de Nodo si se usa std::cout en el constructor,
// pero es mas comun incluirlo en el .cpp
// Si se usa "using namespace std;" aqui, afectaria a todos los archivos que lo incluyan.
// Es preferible incluirlo en cada .cpp o usar std:: prefijos en el .h

// Definicion de la estructura de un Nodo del arbol
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) : dato(val), izq(NULL), der(NULL) {}
};

// Prototipos de las funciones del arbol
Nodo* insertarNodo(Nodo* raiz, int valor);
void mostrarPreOrden(Nodo* raiz);
void mostrarInOrden(Nodo* raiz);
void mostrarPostOrden(Nodo* raiz);

// Prototipos de las funciones de UI (User Interface)
void mostrarMenu();
int leerOpcion(); // Funcion para leer la opcion del menu
int leerNumero(); // Funcion para leer el numero a insertar

#endif // FUNCIONES_H