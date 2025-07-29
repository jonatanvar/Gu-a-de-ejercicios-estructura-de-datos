//
// Created by klain on 16/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    string carrera;
    double promedio;
};

void saludo();
bool funcionSeguir();
void funcionvalidar(Estudiante &est);

#endif