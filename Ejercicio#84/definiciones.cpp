#include "cabecera.h"
#include <iostream> // Aunque ya está en cabecera.h, lo incluimos por buenas prácticas

using namespace std;

// Constructor de la clase ABB
ABB::ABB() : raiz(nullptr) {}

// Destructor de la clase ABB
ABB::~ABB() {
    // Al destruir el objeto ABB, se libera toda la memoria asignada a los nodos.
    // Esto es crucial para prevenir fugas de memoria.
    _eliminarArbol(raiz);
    raiz = nullptr; // Asegurarse de que la raíz sea nullptr después de la eliminación
}

// --- Implementaciones de las funciones auxiliares recursivas ---

// Implementación de _insertar
// Esta es la función recursiva central para mantener la propiedad del ABB.
// Un nuevo nodo siempre se inserta como una hoja.
Nodo* ABB::_insertar(Nodo* nodoActual, int valor) {
    // Caso base: Si el nodo actual es nullptr, hemos encontrado el lugar para insertar.
    // Se crea un nuevo nodo con el valor dado y se retorna.
    if (nodoActual == nullptr) {
        return new Nodo(valor);
    }

    // Si el valor a insertar es menor que el dato del nodo actual,
    // se va al subárbol izquierdo.
    // La asignación `nodoActual->izquierdo = ...` es crucial:
    // si `nodoActual->izquierdo` era nullptr, el nuevo nodo se conecta ahí.
    // Si no era nullptr, la recursión sigue hacia abajo por ese lado.
    if (valor < nodoActual->dato) {
        nodoActual->izquierdo = _insertar(nodoActual->izquierdo, valor);
    }
    // Si el valor a insertar es mayor o igual que el dato del nodo actual,
    // se va al subárbol derecho.
    // Esto permite la inserción de valores duplicados en el lado derecho.
    else { // valor >= nodoActual->dato
        nodoActual->derecho = _insertar(nodoActual->derecho, valor);
    }

    // Se retorna el nodo actual (o el nuevo nodo en el caso base)
    // para reconstruir el camino de recursión hacia arriba y mantener los enlaces.
    return nodoActual;
}

// Implementación de _recorridoInorden
// El recorrido Inorden produce los elementos del ABB en orden ascendente.
// Visita primero el subárbol izquierdo, luego el nodo actual, y finalmente el subárbol derecho.
void ABB::_recorridoInorden(Nodo* nodoActual) {
    if (nodoActual == nullptr) {
        return; // Caso base: si el nodo es nulo, no hay nada que recorrer.
    }

    // 1. Recorrer el subárbol izquierdo.
    _recorridoInorden(nodoActual->izquierdo);

    // 2. Visitar el nodo actual (imprimir su dato).
    cout << nodoActual->dato << " ";

    // 3. Recorrer el subárbol derecho.
    _recorridoInorden(nodoActual->derecho);
}

// Implementación de _recorridoPreorden
// El recorrido Preorden visita primero el nodo actual, luego el subárbol izquierdo, y finalmente el subárbol derecho.
// Útil para clonar un árbol.
void ABB::_recorridoPreorden(Nodo* nodoActual) {
    if (nodoActual == nullptr) {
        return; // Caso base: si el nodo es nulo, no hay nada que recorrer.
    }

    // 1. Visitar el nodo actual (imprimir su dato).
    cout << nodoActual->dato << " ";

    // 2. Recorrer el subárbol izquierdo.
    _recorridoPreorden(nodoActual->izquierdo);

    // 3. Recorrer el subárbol derecho.
    _recorridoPreorden(nodoActual->derecho);
}

// Implementación de _eliminarArbol
// Esta función libera recursivamente la memoria de todos los nodos en un orden POSTORDEN
// (izquierda, derecha, raíz) para asegurar que los hijos se eliminen antes que el padre.
void ABB::_eliminarArbol(Nodo* nodoActual) {
    if (nodoActual == nullptr) {
        return; // Caso base: si el nodo es nulo, no hay nada que liberar.
    }

    // 1. Liberar el subárbol izquierdo.
    _eliminarArbol(nodoActual->izquierdo);

    // 2. Liberar el subárbol derecho.
    _eliminarArbol(nodoActual->derecho);

    // 3. Liberar el nodo actual.
    delete nodoActual;
    // cout << "Nodo con dato " << nodoActual->dato << " liberado." << endl; // Para depuración
}

// Implementación de _buscar
// Aprovecha la propiedad de orden del ABB para buscar eficientemente.
// Se reduce la búsqueda a la mitad de los nodos con cada comparación.
bool ABB::_buscar(Nodo* nodoActual, int valor) {
    // Caso base 1: Si el nodo actual es nullptr, el valor no se encontró en el árbol.
    if (nodoActual == nullptr) {
        return false;
    }

    // Caso base 2: Si el dato del nodo actual coincide con el valor, lo hemos encontrado.
    if (nodoActual->dato == valor) {
        return true;
    }

    // Si el valor es menor que el dato del nodo actual, buscar en el subárbol izquierdo.
    if (valor < nodoActual->dato) {
        return _buscar(nodoActual->izquierdo, valor);
    }
    // Si el valor es mayor que el dato del nodo actual, buscar en el subárbol derecho.
    else { // valor > nodoActual->dato (ya que el caso igual ya se manejó)
        return _buscar(nodoActual->derecho, valor);
    }
}

// Implementación de _mostrarEstructura
// Función recursiva para mostrar una representación visual simple del árbol.
// Utiliza sangría para indicar los niveles del árbol.
void ABB::_mostrarEstructura(Nodo* nodoActual, int nivel) {
    if (nodoActual == nullptr) {
        return; // Caso base: si el nodo es nulo, no hay nada que mostrar.
    }

    // Recorrer primero el subárbol derecho para que la raíz se imprima más a la izquierda
    // y el árbol se vea "horizontal" con la raíz a la izquierda.
    _mostrarEstructura(nodoActual->derecho, nivel + 1);

    // Imprimir sangría para el nivel actual.
    for (int i = 0; i < nivel; ++i) {
        cout << "    "; // 4 espacios por nivel
    }
    cout << nodoActual->dato << endl; // Imprimir el dato del nodo actual

    // Recorrer el subárbol izquierdo.
    _mostrarEstructura(nodoActual->izquierdo, nivel + 1);
}

// --- Implementaciones de las funciones públicas de la clase ABB ---

// Función pública para insertar un valor.
// Se encarga de inicializar la inserción llamando a la función auxiliar recursiva.
void ABB::insertar(int valor) {
    raiz = _insertar(raiz, valor);
    cout << "  -> '" << valor << "' insertado correctamente." << endl;
}

// Función pública para mostrar el recorrido Inorden.
void ABB::mostrarInorden() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No hay elementos para mostrar." << endl;
        return;
    }
    cout << "Recorrido INORDEN (valores ordenados): ";
    _recorridoInorden(raiz);
    cout << endl;
    cout << "Explicacion: Este recorrido visita el subarbol izquierdo, luego el nodo actual y finalmente el subarbol derecho." << endl;
    cout << "Debido a la propiedad de orden del ABB (menores a la izquierda, mayores/iguales a la derecha)," << endl;
    cout << "este orden de visita garantiza que los valores se impriman de forma ascendente." << endl;
}

// Función pública para mostrar el recorrido Preorden.
void ABB::mostrarPreorden() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No hay elementos para mostrar." << endl;
        return;
    }
    cout << "Recorrido PREORDEN: ";
    _recorridoPreorden(raiz);
    cout << endl;
}

// Función pública para mostrar la estructura visual del ABB.
void ABB::mostrarEstructura() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No hay estructura para mostrar." << endl;
        return;
    }
    cout << "Estructura visual del arbol (horizontal, la raiz es el numero mas a la izquierda):" << endl;
    _mostrarEstructura(raiz, 0); // Iniciar en el nivel 0
}

// Función pública para buscar un valor.
bool ABB::buscar(int valor) {
    cout << "Buscando el valor '" << valor << "' en el ABB..." << endl;
    bool encontrado = _buscar(raiz, valor);
    if (encontrado) {
        cout << "  -> El valor '" << valor << "' SI se encuentra en el arbol." << endl;
    } else {
        cout << "  -> El valor '" << valor << "' NO se encuentra en el arbol." << endl;
    }
    cout << "Explicacion de eficiencia de busqueda:" << endl;
    cout << "En un ABB bien balanceado, la busqueda es O(log n) porque en cada paso descartamos aproximadamente la mitad de los nodos restantes." << endl;
    cout << "Esto es como buscar una palabra en un diccionario: no lo lees entero, vas a la mitad, luego a la mitad de la mitad, etc." << endl;
    cout << "En el peor caso (arbol degenerado, como una lista enlazada), la busqueda es O(n), similar a una busqueda lineal." << endl;
    return encontrado;
}

// Función pública para verificar si el ABB está vacío.
bool ABB::estaVacio() {
    return raiz == nullptr;
}

// --- Implementaciones de funciones auxiliares para el main.cpp ---

// Implementación de obtenerEnteroValido
// Valida la entrada del usuario para asegurar que sea un entero.
int obtenerEnteroValido(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        // Comprueba si la entrada falló (no se leyó un entero)
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingrese un numero entero." << endl;
            cin.clear(); // Limpia la bandera de error de cin
            limpiarBuffer(); // Limpia el buffer de entrada para evitar bucles infinitos
        } else {
            limpiarBuffer(); // Limpia el buffer después de una lectura exitosa
            return valor; // Retorna el valor si la entrada es válida
        }
    }
}

// Implementación de limpiarBuffer
// Limpia el resto de la línea del buffer de entrada.
void limpiarBuffer() {
    cin.ignore(1000, '\n'); // Ignora hasta 1000 caracteres o hasta el salto de línea
}

// Implementación de presionarEnterParaContinuar
// Pausa la ejecución del programa hasta que el usuario presione Enter.
void presionarEnterParaContinuar() {
    cout << "\nPresione Enter para continuar...";
    cin.get(); // Lee el salto de línea pendiente o espera uno si el buffer está limpio
}