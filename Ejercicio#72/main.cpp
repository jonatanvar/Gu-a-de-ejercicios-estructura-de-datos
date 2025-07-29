//Jonatan Varela
//17/07/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

void MostrarMenu() {
    cout << "\n=== MENU COLA ===" << endl;
    cout << "1. Encolar elemento" << endl;
    cout << "2. Desencolar elemento" << endl;
    cout << "3. Verificar si la cola está llena" << endl;
    cout << "4. Verificar si la cola está vacía" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opción: ";
}

int main() {
    Cola miCola;
    iniciarCola(miCola);
    int opcion, valor;

    do {
        MostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a encolar: ";
                cin >> valor;
                if (encolar(miCola, valor)) {
                    cout << "✅ Valor encolado correctamente." << endl;
                } else {
                    cout << "❌ La cola está llena, no se puede encolar." << endl;
                }
                break;

            case 2:
                if (desencolar(miCola, valor)) {
                    cout << "✅ Valor desencolado: " << valor << endl;
                } else {
                    cout << "❌ La cola está vacía, no se puede desencolar." << endl;
                }
                break;

            case 3:
                cout << "La cola " << (estaLlena(miCola) ? "SÍ" : "NO") << " está llena." << endl;
                break;

            case 4:
                cout << "La cola " << (estaVacia(miCola) ? "SÍ" : "NO") << " está vacía." << endl;
                break;

            case 5:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}
