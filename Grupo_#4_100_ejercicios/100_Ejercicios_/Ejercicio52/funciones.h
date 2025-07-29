//
// Created by klain on 16/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

struct Punto {
    double x;
    double y;
};

void saludo();
bool funcionSeguir();
void funcionvalidar(double &coord);
double calcularCuadradoDistancia(Punto p1, Punto p2);

#endif // FUNCIONES_H