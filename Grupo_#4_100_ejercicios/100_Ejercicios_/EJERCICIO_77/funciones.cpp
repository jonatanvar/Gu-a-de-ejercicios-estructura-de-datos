#include <iostream>
#include "Funciones.h" 

using namespace std; 

Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return new Nodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izq = insertarNodo(raiz->izq, valor);
    }
    else {
        raiz->der = insertarNodo(raiz->der, valor);
    }

    return raiz;
}

void mostrarPreOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        mostrarPreOrden(raiz->izq);
        mostrarPreOrden(raiz->der);
    }
}

void mostrarInOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarInOrden(raiz->izq);
        cout << raiz->dato << " ";
        mostrarInOrden(raiz->der);
    }
}

void mostrarPostOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarPostOrden(raiz->izq);
        mostrarPostOrden(raiz->der);
        cout << raiz->dato << " ";
    }
}

void mostrarMenu() {
    cout << "\n--- MENU DE ARBOLES BINARIOS ---" << endl;
    cout << "1. Insertar elemento" << endl;
    cout << "2. Recorrido Pre-Orden" << endl;
    cout << "3. Recorrido In-Orden" << endl;
    cout << "4. Recorrido Post-Orden" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

int leerOpcion() {
    int opcion;
    cin >> opcion;
    return opcion;
}

int leerNumero() {
    int num;
    cout << "Ingrese el numero entero: ";
    cin >> num;
    return num;
}