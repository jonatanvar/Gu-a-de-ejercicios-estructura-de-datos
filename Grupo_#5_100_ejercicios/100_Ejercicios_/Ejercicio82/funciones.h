//
// Created by klain on 17/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>

using namespace std;

// Definición de la estructura para un nodo de árbol binario
struct NodoArbol {
    int dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

void saludo();
bool funcionSeguir();
void funcionvalidar(int &x);

// Funciones para el árbol binario
NodoArbol* crearNodo(int dato);
void insertar(NodoArbol *&arbol, int dato);
void preOrden(NodoArbol *arbol);
int contarNodos(NodoArbol *arbol);

#endif //FUNCIONES_H
