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

void mostrarPreOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        mostrarPreOrden(raiz->izq);
        mostrarPreOrden(raiz->der);
    }
}

void mostrarInOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarInOrden(raiz->izq);
        cout << raiz->dato << " ";
        mostrarInOrden(raiz->der);
    }
}

void mostrarPostOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarPostOrden(raiz->izq);
        mostrarPostOrden(raiz->der);
        cout << raiz->dato << " ";
    }
}

void mostrarMenu() {
    cout << "\n--- MENU DE ARBOLES BINARIOS ---" << endl;
    cout << "1. Insertar elemento" << endl;
    cout << "2. Recorrido Pre-Orden" << endl;
    cout << "3. Recorrido In-Orden" << endl;
    cout << "4. Recorrido Post-Orden" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

int leerNumero() {
    int num;
    cout << "Ingrese el numero entero: ";
    cin >> num;
    return num;
}

int main() {
    Nodo* raiz = NULL;
    int opcion;
    int valor;

    cout << "¡Bienvenido al Gestor de Arboles Binarios de Busqueda!" << endl;

    do {
        mostrarMenu();
        cin >> opcion;

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
