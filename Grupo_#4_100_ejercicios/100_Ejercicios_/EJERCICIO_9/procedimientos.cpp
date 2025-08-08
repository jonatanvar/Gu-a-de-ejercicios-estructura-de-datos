#include "funciones.h"

void saludo() {
    cout << "Bienvenido al programa de Factorial" << endl;
    cout << "Este programa calcula el factorial de un numero entero no negativo" << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "Desea calcular otro factorial? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& x) {
    while (cin.fail() || x < 0) { // Valida que sea numero y no negativo
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Por favor, ingrese un numero entero no negativo: ";
        cin >> x;
    }
}

int obtenerNumero(const char* mensaje) {
    int numero;
    cout << mensaje;
    cin >> numero;
    funcionvalidar(numero);
    return numero;
}

long long calcularFactorial(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

void mostrarResultadoFactorial(int n, long long factorial) {
    cout << "El factorial de " << n << " es: " << factorial << endl;
}