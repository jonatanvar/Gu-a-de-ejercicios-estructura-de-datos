//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Implementación de funciones para eliminar un nodo de un Árbol Binario de Búsqueda (ABB) manteniendo su estructura.
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.cpp` para el Ejercicio 86: 'Eliminar nodo en ABB'. Incluye el nuevo bloque de encabezado, implementa las funciones `obtenerEnteroValido`, `crearNodo`, `insertar` (como inserción en un BST), `recorridoInorden`, `encontrarMinimo`, `eliminarNodo` (manejando los tres casos de eliminación), `liberarArbol`, y `resolverEjercicio86` como se describe en el análisis. Asegura una gestión de memoria adecuada y el mantenimiento de la estructura del árbol.

#include <iostream>  // Para operaciones de entrada/salida (cout, cin).
#include <limits>    // Para numeric_limits (validación de entrada).
#include <string>    // Para std::string y std::to_string.
#include "funciones.h" // Incluye el archivo de cabecera con la definición de Nodo y prototipos.

// Se asume el uso de namespace std para simplificar.
using namespace std;

// --- Funciones Auxiliares Generales ---

// Función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de una lectura exitosa.
            break;
        }
    }
    return valor;
}

// --- Funciones de Árbol Binario de Búsqueda (ABB) ---

// Función para crear un nuevo nodo.
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Función para insertar un nodo en un árbol binario de búsqueda (BST).
// Retorna la nueva raíz del subárbol después de la inserción.
Nodo* insertar(Nodo* raiz, int dato) {
    // Si el árbol está vacío, crea un nuevo nodo y lo retorna como raíz.
    if (raiz == nullptr) {
        return crearNodo(dato);
    }

    // Si el dato es menor, va al subárbol izquierdo.
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    }
    // Si el dato es mayor, va al subárbol derecho.
    else if (dato > raiz->dato) { // Maneja solo inserciones de valores únicos o mayores.
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    // Si el dato es igual, no se inserta (se ignora para este BST simple).
    // Puedes ajustar esto para permitir duplicados en el subárbol derecho si es necesario.
    else {
        cout << "El valor " << dato << " ya existe en el arbol. Ignorando duplicado.\n";
    }

    // Retorna el puntero (sin cambios si el valor ya existía o si es un nodo intermedio)
    return raiz;
}

// Función para encontrar el nodo con el valor mínimo en un subárbol.
// Utilizado para el caso de eliminación de un nodo con dos hijos.
Nodo* encontrarMinimo(Nodo* nodo) {
    Nodo* actual = nodo;
    // Recorre hacia la izquierda hasta el nodo más a la izquierda.
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

// Función para eliminar un nodo de un ABB.
// Retorna la nueva raíz del subárbol después de la eliminación.
Nodo* eliminarNodo(Nodo* raiz, int valor) {
    // Caso base: Si la raíz es nula, el valor no se encontró en el árbol.
    if (raiz == nullptr) {
        cout << "El valor " << valor << " no se encontro en el arbol.\n";
        return raiz;
    }

    // 1. Recorrer el árbol para encontrar el nodo a eliminar.
    if (valor < raiz->dato) {
        raiz->izquierdo = eliminarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = eliminarNodo(raiz->derecho, valor);
    }
    // 2. Nodo encontrado (valor == raiz->dato). Manejar los 3 casos de eliminación.
    else {
        // Caso 1: Nodo sin hijos (hoja) o con un solo hijo.
        if (raiz->izquierdo == nullptr) {
            Nodo* temp = raiz->derecho; // El hijo derecho (o nullptr si es hoja).
            delete raiz; // Libera la memoria del nodo actual.
            cout << "Nodo " << valor << " eliminado (0 o 1 hijo).\n";
            return temp; // Retorna el hijo para que el padre apunte a él.
        } else if (raiz->derecho == nullptr) {
            Nodo* temp = raiz->izquierdo; // El hijo izquierdo.
            delete raiz; // Libera la memoria del nodo actual.
            cout << "Nodo " << valor << " eliminado (0 o 1 hijo).\n";
            return temp; // Retorna el hijo para que el padre apunte a él.
        }
        // Caso 3: Nodo con dos hijos.
        else {
            // Encontrar el sucesor inorden (el nodo más pequeño en el subárbol derecho).
            Nodo* temp = encontrarMinimo(raiz->derecho);

            // Copiar el valor del sucesor inorden al nodo actual.
            raiz->dato = temp->dato;

            // Eliminar recursivamente el sucesor inorden del subárbol derecho.
            raiz->derecho = eliminarNodo(raiz->derecho, temp->dato);
            cout << "Nodo " << valor << " eliminado (2 hijos - reemplazado por " << raiz->dato << ").\n";
        }
    }
    return raiz; // Retorna el (posiblemente modificado) puntero a la raíz del subárbol.
}

// Función para realizar un recorrido en inorden (Izquierda-Raíz-Derecha).
// Muestra los elementos en orden ascendente, útil para verificar la estructura del ABB.
void recorridoInorden(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }
    recorridoInorden(nodo->izquierdo);
    cout << nodo->dato << " ";
    recorridoInorden(nodo->derecho);
}

// Función para liberar la memoria de todos los nodos del árbol (recorrido postorden).
void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }
    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    delete nodo; // Libera el nodo actual después de liberar a sus hijos.
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio86() {
    Nodo* raiz = nullptr; // Inicializa la raíz del árbol como nula.
    int num_elementos;
    int elemento;
    int valor_a_eliminar;
    char opcion;

    cout << "\n--- Ejercicio 86: Eliminar Nodo en ABB ---\n";

    // Limpiar el buffer de entrada antes del primer menú de opciones.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Opciones para construir el árbol
    cout << "¿Deseas insertar elementos en el arbol? (s/n): ";
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer.

    if (opcion == 's' || opcion == 'S') {
        num_elementos = obtenerEnteroValido(std::string("¿Cuantos elementos deseas insertar en el arbol? ").c_str());
        for (int i = 0; i < num_elementos; ++i) {
            elemento = obtenerEnteroValido(std::string("Ingresa el elemento " + to_string(i + 1) + ": ").c_str());
            raiz = insertar(raiz, elemento); // Actualiza la raíz después de la inserción.
        }
    } else {
        // Árbol de ejemplo predefinido para probar los casos de eliminación.
        // Ejemplo: 50, 30, 70, 20, 40, 60, 80, 75, 90
        cout << "Creando un arbol con elementos de ejemplo: 50, 30, 70, 20, 40, 60, 80, 75, 90\n";
        raiz = insertar(raiz, 50);
        raiz = insertar(raiz, 30);
        raiz = insertar(raiz, 70);
        raiz = insertar(raiz, 20);
        raiz = insertar(raiz, 40);
        raiz = insertar(raiz, 60);
        raiz = insertar(raiz, 80);
        raiz = insertar(raiz, 75);
        raiz = insertar(raiz, 90);
    }
    
    // Mostrar el árbol inicial.
    cout << "\nArbol inicial (Recorrido Inorden): ";
    recorridoInorden(raiz);
    cout << "\n";

    // Pedir el valor a eliminar.
    valor_a_eliminar = obtenerEnteroValido("Ingresa el valor del nodo a eliminar: ");

    // Eliminar el nodo.
    raiz = eliminarNodo(raiz, valor_a_eliminar); // La raíz puede cambiar si se elimina la raíz original.

    // Mostrar el árbol después de la eliminación.
    cout << "\nArbol despues de la eliminacion (Recorrido Inorden): ";
    if (raiz == nullptr) {
        cout << "(Arbol vacio)";
    } else {
        recorridoInorden(raiz);
    }
    cout << "\n";

    // Liberar la memoria asignada al árbol.
    liberarArbol(raiz);
    cout << "Memoria del arbol liberada.\n";
    cout << "--------------------------------------------------------\n";
}