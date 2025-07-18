//
// Created by klain on 17/7/2025.
//

#include <iostream>
#include "Funciones.h"
using namespace std;

int main() {
    Nodo *frente = nullptr;
    Nodo *fin = nullptr;
    int opcion;
    int dato;

    saludo();

    do {
        cout << "\n MENU DE COLAS " << endl;
        cout << "1. Encolar (Enqueue)" << endl;
        cout << "2. Desencolar (Dequeue)" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        funcionvalidar(opcion);

        switch (opcion) {
            case 1:
                cout << "Ingrese el dato a encolar: ";
                funcionvalidar(dato);
                enqueue(frente, fin, dato);
                break;
            case 2:
                dequeue(frente, fin);
                break;
            case 3:
                cout << "Saliendo del programa. Hasta luego" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo" << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}