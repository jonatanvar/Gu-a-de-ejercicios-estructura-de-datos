#include "funciones.h"

void saludo() {
    cout << "Hola! Programa de pila simple." << endl;
    cout << "Ingresaras la capacidad y los elementos de la pila." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nOtro intento? (s/n): ";
    cin >> opcion;
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail() || num <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalido. Ingrese un entero positivo: ";
        cin >> num;
    }
}

void inicializarPila(Pila& p, int cap) {
    p.capacidad = cap;
    p.elementos = new int[p.capacidad];
    p.cantidad = 0;
}

void liberarPila(Pila& p) {
    delete[] p.elementos;
    p.elementos = 0;
    p.capacidad = 0;
    p.cantidad = 0;
}

bool push(Pila& p, int valor) {
    if (p.cantidad < p.capacidad) {
        p.elementos[p.cantidad] = valor;
        p.cantidad++;
        cout << "Elemento " << valor << " agregado. (" << p.cantidad << "/" << p.capacidad << ")" << endl;
        return true;
    }
    cout << "Pila llena. No se puede agregar " << valor << "." << endl;
    return false;
}

bool estaPilaLlena(const Pila& p) {
    return p.cantidad == p.capacidad;
}