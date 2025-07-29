//
// Created by klain on 16/7/2025.
//
#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

int main() {
    Estudiante nuevoEstudiante;

    saludo();

    do {
        funcionvalidar(nuevoEstudiante);

        cout << endl << "Datos del Estudiante Registrado" << endl;
        cout << "Nombre: " << nuevoEstudiante.nombre << endl;
        cout << "Carnet: " << nuevoEstudiante.carnet << endl;
        cout << "Carrera: " << nuevoEstudiante.carrera << endl;
        cout << "Promedio: " << nuevoEstudiante.promedio << endl;


    } while (funcionSeguir());

    return 0;
}