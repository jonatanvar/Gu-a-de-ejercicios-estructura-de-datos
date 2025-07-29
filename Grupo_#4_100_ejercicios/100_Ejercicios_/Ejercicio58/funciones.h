//
// Created by klain on 16/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Fraccion {
    int numerador;
    int denominador;
};

void saludo();
bool funcionSeguir();
void funcionvalidar(int &num1, int &den1, int &num2, int &den2);
int mcd(int a, int b);
void simplificarFraccion(Fraccion &f);
Fraccion sumarFracciones(Fraccion f1, Fraccion f2);
void imprimirFraccion(Fraccion f);

#endif // FUNCIONES_H