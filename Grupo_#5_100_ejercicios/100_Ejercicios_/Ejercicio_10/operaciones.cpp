//
// Created by klain on 28/6/2025.
//

#include <iostream>
#include "funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO" << endl;
}

int sumaNatural(int x) {
    int suma = 0;
    for (int i = 1; i <= x; i++) {
        suma += i;
    }
    return suma;
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
        } else if (x <= 0) {
            cout << "Error. El numero debe ser mayor que cero. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea calcular la suma de otro numero natural? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

