#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

Nodo* crearNodo(int valor);
Nodo* insertar(Nodo* raiz, int valor);
void recorridoInorden(Nodo* raiz);

#endif
