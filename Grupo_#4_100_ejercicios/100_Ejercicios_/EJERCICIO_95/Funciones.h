#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

int leerCantidadNumeros();
int* leerNumeros(int cantidad);
void ordenarArray(int* arr, int cantidad);
double calcularMediana(int* arr, int inicio, int fin);
double calcularQ1(int* arr, int cantidad);
double calcularQ3(int* arr, int cantidad);
double calcularRangoIntercuartilico(int* arr, int cantidad);
void liberarMemoria(int* arr);
char preguntarSiRepetir();

#endif // FUNCIONES_H