// main.cpp
#include <iostream>
#include "Pila.h" // Incluimos nuestro archivo de encabezado de la pila
using namespace std;

// Funciones de bienvenida y continuar, adaptadas al contexto de la pila
void saludoPila() {
    cout << "BIENVENIDO AL PROGRAMA DE MANEJO DE PILAS" << endl;
}

bool funcionSeguirPila() {
    char opcion;
    cout << endl;
    cout << "Desea realizar otra operacion con la pila? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

// Adaptación de funcionvalidar para un solo entero (por ejemplo, para el valor a meter)
void funcionvalidarEntero(int &x) {
    bool entradaValida;
    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros enteros. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

int main() {
    Pila miPila;
    inicializarPila(miPila);
    int opcion;
    int valor;

    saludoPila();

    do {
        cout << "Elija una operacion:" << endl;
        cout << "1. Meter elemento (PUSH)" << endl;
        cout << "2. Sacar elemento (POP)" << endl;
        cout << "3. Ver elemento de la cima (PEEK)" << endl;
        cout << "4. Verificar si la pila esta vacia" << endl;
        cout << "5. Verificar si la pila esta llena" << endl;
        cout << "Ingrese su opcion: ";
        funcionvalidarEntero(opcion);

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a meter: ";
                funcionvalidarEntero(valor);
                meter(miPila, valor);
                break;
            case 2:
                if (!estaVacia(miPila)) {
                    sacar(miPila);
                } else {
                    cout << "La pila esta vacia, no se puede sacar." << endl;
                }
                break;
            case 3:
                if (!estaVacia(miPila)) {
                    cout << "El elemento en la cima es: " << verCima(miPila) << endl;
                } else {
                    cout << "La pila esta vacia, no hay cima para ver." << endl;
                }
                break;
            case 4:
                if (estaVacia(miPila)) {
                    cout << "La pila esta VACIA." << endl;
                } else {
                    cout << "La pila NO esta vacia." << endl;
                }
                break;
            case 5:
                if (estaLlena(miPila)) {
                    cout << "La pila esta LLENA." << endl;
                } else {
                    cout << "La pila NO esta llena." << endl;
                }
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }

    } while (funcionSeguirPila());

    return 0;
}