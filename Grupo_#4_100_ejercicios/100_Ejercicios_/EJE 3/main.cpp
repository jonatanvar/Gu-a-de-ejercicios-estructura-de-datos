#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        int numero1;
        int numero2;
        int resultado;

        numero1 = obtenerNumero("Ingrese el primer numero: ");
        numero2 = obtenerNumero("Ingrese el segundo numero: ");

        resultado = calcularProducto(numero1, numero2);
        mostrarResultado(resultado);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}