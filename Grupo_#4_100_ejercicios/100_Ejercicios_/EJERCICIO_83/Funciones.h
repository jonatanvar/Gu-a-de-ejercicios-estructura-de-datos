#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) : dato(val), izq(NULL), der(NULL) {}
};

Nodo* insertarNodo(Nodo* raiz, int valor);
void mostrarInOrden(Nodo* raiz);
int leerNumeroParaInsertar();

#endif // FUNCIONES_H