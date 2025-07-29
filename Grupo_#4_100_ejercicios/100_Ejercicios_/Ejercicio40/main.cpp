//
// Created by klain on 16/7/2025.
//

#include <iostream>
#include <string>
#include "Funciones.h"
using namespace std;

int main() {
    string texto;

    saludo();

    do {
        funcionvalidar(texto);
        int numVocales = contarVocales(texto);
        cout << "El numero de vocales en la cadena es: " << numVocales << endl;
    } while (funcionSeguir());

    return 0;
}