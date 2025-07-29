//
// Created by klain on 16/7/2025.
//
// procedimientos.cpp
#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO AL CALCULADOR DE DISTANCIA ENTRE DOS PUNTOS" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea calcular el cuadrado de la distancia de otros dos puntos? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(double &coord) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> coord)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

double calcularCuadradoDistancia(Punto p1, Punto p2) {
    double diffX = p2.x - p1.x;
    double diffY = p2.y - p1.y;
    double cuadradoDiffX = diffX * diffX;
    double cuadradoDiffY = diffY * diffY;
    return cuadradoDiffX + cuadradoDiffY;
}
