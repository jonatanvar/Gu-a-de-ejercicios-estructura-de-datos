#include "funciones.h"

void saludo() {
    cout << "Hola! Programa para verificar si una cola esta vacia." << endl;
    cout << "Ingresaras la capacidad y los elementos de la cola." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nQuieres probar de nuevo? (s/n): ";
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

void inicializarCola(Cola& c, int cap) {
    c.capacidad = cap;
    c.elementos = new int[c.capacidad];
    c.cantidad = 0;
}

void liberarCola(Cola& c) {
    delete[] c.elementos;
    c.elementos = 0;
    c.capacidad = 0;
    c.cantidad = 0;
}

void encolar(Cola& c, int valor) {
    if (c.cantidad < c.capacidad) {
        c.elementos[c.cantidad] = valor;
        c.cantidad++;
        cout << "  Elemento " << valor << " encolado. (" << c.cantidad << "/" << c.capacidad << ")" << endl;
    } else {
        cout << "  Cola llena. No se pudo encolar " << valor << "." << endl;
    }
}

void desencolar(Cola& c) {
    if (c.cantidad > 0) {
        for(int i = 0; i < c.cantidad - 1; ++i) {
            c.elementos[i] = c.elementos[i+1];
        }
        c.cantidad--;
        cout << "  Elemento desencolado. Quedan " << c.cantidad << " elementos." << endl;
    } else {
        cout << "  Cola vacia. No se pudo desencolar." << endl;
    }
}

bool estaColaVacia(const Cola& c) {
    return c.cantidad == 0;
}