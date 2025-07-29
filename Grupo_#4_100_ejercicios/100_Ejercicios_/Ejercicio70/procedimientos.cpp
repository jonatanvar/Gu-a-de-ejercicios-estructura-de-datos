//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA DE COLAS" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea realizar otra operacion? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void enqueue(Nodo *&frente, Nodo *&fin, int dato) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = nullptr;

    if (estaVacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "Elemento " << dato << " encolado correctamente." << endl;
}

int dequeue(Nodo *&frente, Nodo *&fin) {
    if (estaVacia(frente)) {
        cout << "La cola esta vacia. No se puede desencolar." << endl;
        return -1; // Valor para indicar error o cola vacía
    }
    int dato_desencolado = frente->dato;
    Nodo *temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) {
    }
    delete temp;
    cout << "Elemento " << dato_desencolado << " desencolado correctamente." << endl;
    return dato_desencolado;
}

bool estaVacia(Nodo *frente) {
    return (frente == nullptr);
}