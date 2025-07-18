//
// Created by klain on 16/7/2025.
//
// procedimientos.cpp
#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO AL REGISTRO DE ESTUDIANTES" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea registrar otro estudiante? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(Estudiante &est) {
    bool entradaValida;

    cin.ignore(10000, '\n');

    do {
        entradaValida = true;
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, est.nombre);
        if (est.nombre.empty()) {
            cout << "Error. El nombre no puede estar vacio. Intente nuevamente." << endl;
            entradaValida = false;
        }
    } while (!entradaValida);

    do {
        entradaValida = true;
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, est.carnet);
        if (est.carnet.empty()) {
            cout << "Error. El carnet no puede estar vacio. Intente nuevamente." << endl;
            entradaValida = false;
        }
    } while (!entradaValida);

    do {
        entradaValida = true;
        cout << "Ingrese la carrera del estudiante: ";
        getline(cin, est.carrera);
        if (est.carrera.empty()) {
            cout << "Error. La carrera no puede estar vacia. Intente nuevamente." << endl;
            entradaValida = false;
        }
    } while (!entradaValida);

    do {
        entradaValida = true;
        cout << "Ingrese el promedio del estudiante: ";
        if (!(cin >> est.promedio)) {
            cout << "Error. Solo se permiten numeros. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            entradaValida = false;
        } else if (est.promedio < 0 || est.promedio > 100) {
            cout << "Error. El promedio debe ser entre 0 y 100. Intente nuevamente." << endl;
            entradaValida = false;
        }
    } while (!entradaValida);
}