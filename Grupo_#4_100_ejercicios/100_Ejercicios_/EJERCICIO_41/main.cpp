#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        char miCadena[MAX_CADENA];
        int numConsonantes;

        cout << "Ingresa una cadena de texto: ";
        cin.getline(miCadena, MAX_CADENA);

        numConsonantes = contarConsonantes(miCadena);

        mostrarResultadoConsonantes(miCadena, numConsonantes);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}