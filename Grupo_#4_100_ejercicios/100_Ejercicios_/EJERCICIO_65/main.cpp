#include <iostream>
#include "funciones.h"

using namespace std;

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
            funcionvalidar(valor);
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