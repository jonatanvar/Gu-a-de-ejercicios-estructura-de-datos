//
// Created by klain on 16/7/2025.
//


#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

int main() {
    Punto punto1, punto2;

    saludo();

    do {
        cout << "--- Ingrese las coordenadas del Primer Punto ---" << endl;
        cout << "Ingrese la coordenada X del punto 1: ";
        funcionvalidar(punto1.x);
        cout << "Ingrese la coordenada Y del punto 1: ";
        funcionvalidar(punto1.y);

        cout << endl << "--- Ingrese las coordenadas del Segundo Punto ---" << endl;
        cout << "Ingrese la coordenada X del punto 2: ";
        funcionvalidar(punto2.x);
        cout << "Ingrese la coordenada Y del punto 2: ";
        funcionvalidar(punto2.y);

        double cuadradoDistancia = calcularCuadradoDistancia(punto1, punto2);
        cout << endl;
        cout << "El cuadrado de la distancia entre los puntos es: " << cuadradoDistancia << endl;


    } while (funcionSeguir());

    return 0;
}