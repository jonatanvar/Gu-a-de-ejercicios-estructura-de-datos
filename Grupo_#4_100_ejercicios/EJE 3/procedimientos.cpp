#include "funciones.h"

void saludo() {
    cout << "Bienvenido al programa de multiplicacion" << endl;
    cout << "Este programa multiplica dos numeros enteros" << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "Desea realizar otra operacion? (s/n): ";
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

int obtenerNumero(const char* mensaje) {
    int numero;
    cout << mensaje;
    cin >> numero;
    funcionvalidar(numero);
    return numero;
}

int calcularProducto(int num1, int num2) {
    return num1 * num2;
}

void mostrarResultado(int resultado) {
    cout << "El producto es: " << resultado << endl;
}