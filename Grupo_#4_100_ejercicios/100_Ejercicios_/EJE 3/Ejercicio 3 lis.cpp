//Nombre: Cristina Cruz
//Fecha: 1 jul 2025
//Descripción : calcula el producto de dos números enteros que el usuario ingresa, después pregunta si quiere continuar o no (s/n).


#include <iostream>

using namespace std;

void saludo() {
    cout << "Bienvenido al programa de multiplicación" << endl;
    cout << "Este programa multiplica dos numeros enteros" << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "Desea realizar otra operación? (s/n): ";
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
