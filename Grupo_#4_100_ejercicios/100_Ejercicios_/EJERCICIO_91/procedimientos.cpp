//
// Created by Admin on 7/17/2025.
//
#include "funciones.h"
#include <iostream>

using namespace std;


double calcularMedia(const double datos[], int cantidad) {
    if (cantidad <= 0) {
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < cantidad; ++i) {
        suma += datos[i];
    }

    return suma / cantidad;
}


double calcularCovarianza(const double conjuntoX[], const double conjuntoY[], int tamano) {
    // 1. Validar tamaño: Ambos conjuntos deben tener el mismo tamaño y al menos 2 elementos para (n-1).
    if (tamano <= 1) {
        cout << "Error: Se requieren al menos 2 elementos para calcular la covarianza." << endl;
        return 0.0; // Retorna 0.0 como valor de error.
    }
    // Si los arreglos fueran de tamaños potencialmente diferentes (aunque el parámetro "tamano" lo fuerza),
    // aquí iría una validación adicional de que sus tamaños reales coincidan.

    // 2. Calcular las medias de ambos conjuntos.
    double mediaX = calcularMedia(conjuntoX, tamano);
    double mediaY = calcularMedia(conjuntoY, tamano);

    // 3. Calcular la suma de los productos de las desviaciones.
    double sumaProductosDesviaciones = 0.0;
    for (int i = 0; i < tamano; ++i) {
        sumaProductosDesviaciones += (conjuntoX[i] - mediaX) * (conjuntoY[i] - mediaY);
    }


    return sumaProductosDesviaciones / (tamano - 1);
}

int validarEntradaNumericaInt(const char* mensaje) {
    int numero; // Variable para almacenar el número ingresado.

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero valido." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
}


double validarEntradaNumericaDouble(const char* mensaje) {
    double numero;

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero decimal valido." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
}


int preguntarRepetir() {
    int repetir;

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir;

        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (repetir < 1 || repetir > 2) {
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return repetir;
}