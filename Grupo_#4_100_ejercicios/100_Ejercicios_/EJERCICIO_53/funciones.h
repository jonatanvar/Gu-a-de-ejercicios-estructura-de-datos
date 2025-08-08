#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

const int MAX_CADENA = 100;

struct Libro {
    char titulo[MAX_CADENA];
    char autor[MAX_CADENA];
    char editorial[MAX_CADENA];
    int anoPublicacion;
};

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void leerLibro(Libro& lib);
void mostrarLibro(const Libro& lib);

#endif