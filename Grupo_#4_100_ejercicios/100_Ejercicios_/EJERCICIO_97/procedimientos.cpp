//
// Created by Admin on 7/17/2025.
//
#include "funciones.h"
#include <iostream>

using namespace std;


int obtenerLongitud(const char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}


bool validarCorreoElectronico(const char* correo) {
    int longitud = obtenerLongitud(correo);

    if (longitud == 0) {
        return false;
    }

    int posArroba = -1;
    int posUltimoPuntoDespuesArroba = -1;

    for (int i = 0; i < longitud; ++i) {
        if (correo[i] == '@') {

            if (posArroba != -1) {
                return false;
            }
            posArroba = i;
        } else if (correo[i] == ' ') {
            return false;
        }
    }

    if (posArroba == -1 || posArroba == 0 || posArroba == longitud - 1) {
        return false;
    }

    for (int i = posArroba + 1; i < longitud; ++i) {
        if (correo[i] == '.') {
            posUltimoPuntoDespuesArroba = i;
        }
    }

    if (posUltimoPuntoDespuesArroba == -1) {
        return false;
    }

    if (posUltimoPuntoDespuesArroba == posArroba + 1) {
        return false;
    }
    if (posUltimoPuntoDespuesArroba == longitud - 1) {
        return false;
    }
    return true;
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