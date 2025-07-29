#include "cabecera.h"
#include <iostream> // Solo esta librería está permitida

using namespace std;

// Implementación de funciones auxiliares globales

void limpiarPantalla() {
    // Implementación simple para limpiar la pantalla.
    // Puede que no funcione en todos los sistemas operativos o IDEs
    // como se espera, pero cumple con la restricción de no usar librerías extras.
    for (int i = 0; i < 50; ++i) { // Imprime 50 líneas nuevas para "limpiar"
        cout << endl;
    }
    // Una alternativa más efectiva pero que rompe la restricción de <iostream> sería:
    // system("cls"); // Para Windows
    // system("clear"); // Para Unix/Linux
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(); // Limpia el buffer de entrada si hay algo
    cin.get();    // Espera a que el usuario presione Enter
}

int obtenerOpcionValida() {
    int opcion;
    while (!(cin >> opcion)) {
        cout << "Entrada invalida. Por favor, ingrese un numero: ";
        cin.clear(); // Limpia el estado de error
        cin.ignore(10000, '\n'); // Descarta la entrada incorrecta
    }
    cin.ignore(10000, '\n'); // Limpia el buffer después de leer el número
    return opcion;
}

// Implementación de la clase ArbolBinario

// Constructor
ArbolBinario::ArbolBinario() : raiz(nullptr) {}

// Destructor
ArbolBinario::~ArbolBinario() {
    destruirRecursivo(raiz);
}

// Funciones recursivas privadas

void ArbolBinario::insertarRecursivo(Nodo*& nodo, int valor) {
    if (nodo == nullptr) {
        nodo = new Nodo(valor);
    } else if (valor < nodo->valor) {
        insertarRecursivo(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        insertarRecursivo(nodo->derecha, valor);
    } else {
        // Opcional: Manejar valores duplicados. Aquí simplemente no se insertan.
        cout << "El valor " << valor << " ya existe en el arbol y no se insertara de nuevo." << endl;
    }
}

void ArbolBinario::preordenRecursivo(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }
    cout << nodo->valor << " ";         // Visita la raíz
    preordenRecursivo(nodo->izquierda); // Recorre el subárbol izquierdo
    preordenRecursivo(nodo->derecha);   // Recorre el subárbol derecho
}

void ArbolBinario::destruirRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo; // Libera la memoria del nodo
    }
}

void ArbolBinario::imprimirArbolRecursivo(Nodo* nodo, int espacio) {
    if (nodo == nullptr) {
        return;
    }

    espacio += 10; // Incrementa la distancia entre niveles

    imprimirArbolRecursivo(nodo->derecha, espacio); // Procesa primero el hijo derecho

    cout << endl;
    for (int i = 10; i < espacio; i++) {
        cout << " ";
    }
    cout << nodo->valor << endl;

    imprimirArbolRecursivo(nodo->izquierda, espacio); // Procesa el hijo izquierdo
}

bool ArbolBinario::esVacioRecursivo(Nodo* nodo) {
    return nodo == nullptr;
}


// Funciones públicas

void ArbolBinario::insertar(int valor) {
    insertarRecursivo(raiz, valor);
    cout << "Valor " << valor << " insertado correctamente." << endl;
}

void ArbolBinario::mostrarPreorden() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No se puede realizar el recorrido preorden." << endl;
        return;
    }
    cout << "PREORDEN sigue el orden: RAIZ -> IZQUIERDA -> DERECHA" << endl;
    cout << "Recorrido PREORDEN: ";
    preordenRecursivo(raiz);
    cout << endl;
}

void ArbolBinario::mostrarEstructura() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No hay estructura para mostrar." << endl;
        return;
    }
    cout << "Estructura del arbol:" << endl;
    // La función imprimirArbolRecursivo se adapta para mostrar la estructura visualmente
    // de una manera que gire el árbol 90 grados a la izquierda para una mejor visualización.
    imprimirArbolRecursivo(raiz, 0);
}

bool ArbolBinario::estaVacio() {
    return esVacioRecursivo(raiz);
}