#include "funciones.h"

void saludo() {
    cout << "Bienvenido al programa de Suma de Arreglos" << endl;
    cout << "Este programa suma todos los elementos de un arreglo unidimensional" << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "Desea sumar los elementos de otro arreglo? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& x) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Por favor, ingrese un numero entero: ";
        cin >> x;
    }
}

void funcionvalidarPositivo(int& x) {
    while (cin.fail() || x <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Por favor, ingrese un numero entero positivo: ";
        cin >> x;
    }
}

int obtenerTamanoArreglo(const char* mensaje) {
    int tamano;
    cout << mensaje;
    cin >> tamano;
    funcionvalidarPositivo(tamano);
    return tamano;
}

void leerElementosArreglo(int arreglo[], int tamano) {
    cout << "Ingrese los " << tamano << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo[i];
        funcionvalidar(arreglo[i]);
    }
}

int sumarElementosArreglo(int arreglo[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; ++i) {
        suma += arreglo[i];
    }
    return suma;
}

void mostrarResultadoSuma(int suma) {
    cout << "La suma de los elementos del arreglo es: " << suma << endl;
}