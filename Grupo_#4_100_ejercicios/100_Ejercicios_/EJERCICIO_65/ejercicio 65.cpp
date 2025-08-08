//Nombre: Cristina Cruz
//Fecha: 10 jul 2025
//Descripción: Este codigo contiene una Función que retorne verdadero si la pila alcanzó su capacidad máxima.

#include <iostream>

using namespace std;

struct Pila {
    int* elementos;
    int capacidad;
    int cantidad;
};

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

int main() {
    saludo();

    do {
        int capacidadDeseada;
        Pila miPila;

        cout << "Capacidad de la pila: ";
        cin >> capacidadDeseada;
        funcionvalidar(capacidadDeseada);
        cin.ignore(100, '\n');

        inicializarPila(miPila, capacidadDeseada);

        cout << "\nIngresa " << capacidadDeseada << " elementos para la pila:" << endl;
        for (int i = 0; i < capacidadDeseada; ++i) {
            int valor;
            cout << "Elemento " << i + 1 << ": ";
            cin >> valor;
            funcionvalidar(valor); // Validar el elemento a insertar (aunque sea positivo, para simplificar)
            cin.ignore(100, '\n');
            push(miPila, valor);
        }

        if (estaPilaLlena(miPila)) {
            cout << "\nLa pila esta LLENA." << endl;
        } else {
            cout << "\nLa pila NO esta llena." << endl;
        }
        
        cout << "\nIntentando agregar un elemento mas (0 para salir, cualquier numero para intentar): ";
        int intentoExtra;
        cin >> intentoExtra;
        if (intentoExtra != 0) {
            cin.ignore(100, '\n');
            push(miPila, intentoExtra);
        } else {
             cin.ignore(100, '\n');
        }


        liberarPila(miPila);

    } while (funcionseguir());

    cout << "Adios." << endl;

    return 0;
}
