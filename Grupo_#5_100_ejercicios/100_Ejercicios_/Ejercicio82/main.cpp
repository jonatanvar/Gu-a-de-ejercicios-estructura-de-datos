//
// Created by klain on 17/7/2025.
//

#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    NodoArbol *arbol = nullptr;
    int opcion;
    int dato;

    saludo();

    do {
        cout << "\n--- MENU DE ARBOLES BINARIOS ---" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Recorrido Pre-Orden" << endl;
        cout << "3. Contar nodos" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        funcionvalidar(opcion);

        switch (opcion) {
            case 1:
                cout << "Ingrese el dato a insertar: ";
                funcionvalidar(dato);
                insertar(arbol, dato);
                break;
            case 2:
                cout << "Recorrido Pre-Orden: ";
                preOrden(arbol);
                cout << endl;
                break;
            case 3:
                cout << "El numero total de nodos en el arbol es: " << contarNodos(arbol) << endl;
                break;
            case 4:
                cout << "Saliendo del programa. Hasta luego" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo. " << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}