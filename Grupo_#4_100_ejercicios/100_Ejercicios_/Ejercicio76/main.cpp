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
        cout << "3. Recorrido In-Orden" << endl;
        cout << "4. Recorrido Post-Orden" << endl;
        cout << "5. Salir" << endl;
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
                cout << "Recorrido In-Orden: ";
                inOrden(arbol);
                cout << endl;
                break;
            case 4:
                cout << "Recorrido Post-Orden: ";
                postOrden(arbol);
                cout << endl;
                break;
            case 5:
                cout << "Saliendo del programa. Hasta Luego" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}