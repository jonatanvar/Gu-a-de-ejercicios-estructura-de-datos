#include <iostream>
#include "Funciones.h" 

using namespace std; 
int main() {
    Nodo* raiz = NULL;
    int opcion;
    int valor;

    cout << "¡Bienvenido al Gestor de Arboles Binarios de Busqueda!" << endl;

    do {
        mostrarMenu();
        opcion = leerOpcion(); // Leemos la opcion del menu

        switch (opcion) {
            case 1:
                valor = leerNumero();
                raiz = insertarNodo(raiz, valor);
                cout << "Elemento " << valor << " insertado." << endl;
                break;
            case 2:
                cout << "\n--- Recorrido Pre-Orden ---" << endl;
                if (raiz == NULL) {
                    cout << "El arbol esta vacio." << endl;
                } else {
                    mostrarPreOrden(raiz);
                    cout << endl;
                }
                break;
            case 3:
                cout << "\n--- Recorrido In-Orden ---" << endl;
                if (raiz == NULL) {
                    cout << "El arbol esta vacio." << endl;
                } else {
                    mostrarInOrden(raiz);
                    cout << endl;
                }
                break;
            case 4:
                cout << "\n--- Recorrido Post-Orden ---" << endl;
                if (raiz == NULL) {
                    cout << "El arbol esta vacio." << endl;
                } else {
                    mostrarPostOrden(raiz);
                    cout << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}