//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time (para la semilla de srand)
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL SIMULADOR DE LANZAMIENTO DE DADOS" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea realizar otra simulacion? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0) {
            cout << "Error. El numero de lanzamientos debe ser mayor que cero. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void simularLanzamientos(int numLanzamientos, int frecuencias[]) {
    srand(time(0)); // Inicializar la semilla para numeros aleatorios

    for (int i = 0; i < numLanzamientos; ++i) {
        int resultadoDado = (rand() % 6) + 1; // Genera un numero entre 1 y 6
        frecuencias[resultadoDado - 1]++; // Incrementa la frecuencia (indice 0 para 1, etc.)
    }
}

void mostrarFrecuencias(int frecuencias[]) {
    cout << "--- Frecuencias de los resultados ---" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << "Cara " << i + 1 << ": " << frecuencias[i] << " veces" << endl;
    }
}