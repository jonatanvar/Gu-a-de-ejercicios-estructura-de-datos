//Nombre: Cristina Cruz
//Fecha: 15 jul 2025

#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) : dato(val), izq(NULL), der(NULL) {}
};
Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return new Nodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izq = insertarNodo(raiz->izq, valor);
    }
    else {
        raiz->der = insertarNodo(raiz->der, valor);
    }
    return raiz;
}
void mostrarInOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarInOrden(raiz->izq);
        cout << raiz->dato << " ";
        mostrarInOrden(raiz->der);
    }
}
int leerNumeroParaInsertar() {
    int num;
    cout << "Ingresa un numero entero para insertar (0 para terminar): ";
    cin >> num;
    return num;
}
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
