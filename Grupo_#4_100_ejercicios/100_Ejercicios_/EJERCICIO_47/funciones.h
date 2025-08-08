#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

const int MAX_NOMBRE = 50;

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float nota;
};

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void funcionvalidarFloat(float& num);
void funcionvalidarCantidadEstudiantes(int& cantidad);
void leerEstudiante(Estudiante& est);
void leerArregloEstudiantes(Estudiante* arr, int cantidad);
void mostrarEstudiante(const Estudiante& est);
void mostrarArregloEstudiantes(const Estudiante* arr, int cantidad);

#endif