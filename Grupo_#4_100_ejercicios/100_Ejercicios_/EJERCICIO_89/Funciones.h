#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

int leerCantidadNumeros();
int* leerNumeros(int cantidad);
int calcularModa(int* arr, int cantidad);
void liberarMemoria(int* arr);
char preguntarSiRepetir();

#endif // FUNCIONES_H