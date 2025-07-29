//
// Created by klain on 16/7/2025.
//
#include <iostream>
#include "Funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA SUMAR FRACCIONES" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea sumar otras fracciones? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

int mcd(int a, int b) {
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificarFraccion(Fraccion &f) {
    if (f.numerador == 0) {
        f.denominador = 1;
        return;
    }
    int commonDivisor = mcd(f.numerador, f.denominador);
    f.numerador /= commonDivisor;
    f.denominador /= commonDivisor;

    if (f.denominador < 0) {
        f.numerador *= -1;
        f.denominador *= -1;
    }
}

Fraccion sumarFracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
    resultado.denominador = f1.denominador * f2.denominador;
    simplificarFraccion(resultado);
    return resultado;
}

void imprimirFraccion(Fraccion f) {
    cout << f.numerador << "/" << f.denominador;
}

void funcionvalidar(int &num1, int &den1, int &num2, int &den2) {
    bool entradaValida;
    do {
        entradaValida = true;
        cout << "Ingrese el numerador de la primera fraccion: ";
        if (!(cin >> num1)) {
            entradaValida = false;
        } else {
            cout << "Ingrese el denominador de la primera fraccion: ";
            if (!(cin >> den1)) {
                entradaValida = false;
            } else if (den1 == 0) {
                entradaValida = false;
                cout << "Error. El denominador no puede ser cero." << endl;
            }
        }

        if (entradaValida) {
            cout << "Ingrese el numerador de la segunda fraccion: ";
            if (!(cin >> num2)) {
                entradaValida = false;
            } else {
                cout << "Ingrese el denominador de la segunda fraccion: ";
                if (!(cin >> den2)) {
                    entradaValida = false;
                } else if (den2 == 0) {
                    entradaValida = false;
                    cout << "Error. El denominador no puede ser cero." << endl;
                }
            }
        }

        if (!entradaValida) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros y denominadores no cero. Intente nuevamente." << endl;
            cout << endl;
        }
    } while (!entradaValida);
}