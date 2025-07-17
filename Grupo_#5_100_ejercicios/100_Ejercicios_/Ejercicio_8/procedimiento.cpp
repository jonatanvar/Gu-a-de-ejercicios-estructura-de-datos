//
// Created by Kevin Lainez on 28/6/2025.
//
#include <iostream>
#include "funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO AL CONVERTIDOR DE LEMPIRAS A DOLARES" << endl;
}

double funciondolar(double x) {
    const double lps=26.15;
    return x*lps;
}

void funcionvalidar(double &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0) {
            cout << "Error. Los lempiras deben de ser mayores que 0. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea Realizar otra conversion? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}