#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int pila[MAX];
    int tope = -1;
    int opcion, elemento;

    do {
        cout << "\n1. Push (Agregar elemento)" << endl;
        cout << "2. Pop (Eliminar elemento)" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero a agregar: ";
                cin >> elemento;
                push(pila, tope, elemento);
                break;
            case 2:
                pop(pila, tope);
                break;
            case 3:
                mostrarPila(pila, tope);
                break;
            case 4:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opcion inválida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
