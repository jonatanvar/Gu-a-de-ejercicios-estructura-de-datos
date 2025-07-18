//
// Created by klain on 17/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>

using namespace std;

// Definición de la estructura para un nodo de la cola
struct Nodo {
    int dato;
    Nodo *siguiente;
};

void saludo();
bool funcionSeguir();
void funcionvalidar(int &x);

// Funciones para la cola
void enqueue(Nodo *&frente, Nodo *&fin, int dato);
int dequeue(Nodo *&frente, Nodo *&fin);
bool estaVacia(Nodo *frente);
#endif //FUNCIONES_H
