#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    Nodo* raiz = NULL;
    int valor;

    cout << "--- Implementacion Basica de Arbol Binario de Busqueda (ABB) ---" << endl;
    cout << "¡Bienvenido! Inserta numeros para construir tu ABB." << endl;
    cout << "Ingresa '0' para finalizar la insercion." << endl;

    do {
        valor = leerNumeroParaInsertar();
        if (valor != 0) {
            raiz = insertarNodo(raiz, valor);
            cout << "Numero " << valor << " insertado." << endl;
        }
    } while (valor != 0);

    cout << "\n--- Recorrido In-Orden del ABB para Verificar la Ordenacion ---" << endl;
    if (raiz == NULL) {
        cout << "El arbol esta vacio." << endl;
    } else {
        mostrarInOrden(raiz);
        cout << endl;
    }

    cout << "\n--- Fin del programa. ¡Hasta la proxima! ---" << endl;

    return 0;
}