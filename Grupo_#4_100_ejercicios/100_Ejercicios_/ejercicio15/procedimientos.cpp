//
// Created by klain on 7/8/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA CLASIFICAR UN NUMERO" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea clasificar otro numero? S o N: ";
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

void clasificarNumero(int x) {
    if (x > 0) {
        cout << "El numero " << x << " es positivo." << endl;
    } else if (x < 0) {
        cout << "El numero " << x << " es negativo." << endl;
    } else {
        cout << "El numero es cero." << endl;
    }
}