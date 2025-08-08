#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        int numero;
        long long factorialResultado;

        numero = obtenerNumero("Ingrese un numero entero no negativo para calcular su factorial: ");

        factorialResultado = calcularFactorial(numero);
        mostrarResultadoFactorial(numero, factorialResultado);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}