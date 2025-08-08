#include <iostream>
#include <queue>
#include <string>
#include "funciones.h"

using namespace std;

int main() {
    queue<string> fila;
    int opcion;

    do {
        cout << "\n1. Agregar persona a la fila" << endl;
        cout << "2. Atender persona" << endl;
        cout << "3. Mostrar fila actual" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPersona(fila);
                break;
            case 2:
                atenderPersona(fila);
                break;
            case 3:
                mostrarFila(fila);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion inválida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
