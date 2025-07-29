//
// Created by klain on 16/7/2025.
//

#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;


void saludo() {
    cout << "BIENVENIDO AL CONTADOR DE VOCALES EN UNA CADENA" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea contar vocales en otra cadena? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(string &cadena) {
    bool entradaValida;
    // Usamos 10000 como un número grande para limpiar el buffer
    // ya que numeric_limits no está permitido sin <limits>.
    cin.ignore(10000, '\n');

    do {
        entradaValida = true;
        cout << "Ingrese la cadena de texto: ";
        getline(cin, cadena);
        if (cadena.empty()) {
            cout << "Error. La cadena no puede estar vacia. Intente nuevamente." << endl;
            entradaValida = false;
        }
    } while (!entradaValida);
}

int contarVocales(const string &cadena) {
    int contador = 0;
    for (char c : cadena) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}