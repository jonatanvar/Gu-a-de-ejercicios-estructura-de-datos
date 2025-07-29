#ifndef CABECERA_H
#define CABECERA_H

#include <iostream>

using namespace std;

// Estructura de un nodo del Árbol Binario de Búsqueda (ABB)
// Cada nodo contiene un dato entero y punteros a sus hijos izquierdo y derecho.
struct Nodo {
    int dato;        // Valor almacenado en el nodo
    Nodo* izquierdo; // Puntero al subárbol izquierdo (valores menores)
    Nodo* derecho;   // Puntero al subárbol derecho (valores mayores o iguales)

    // Constructor para inicializar un nuevo nodo.
    // Los punteros se inicializan a nullptr para evitar punteros colgantes.
    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

// Clase que representa el Árbol Binario de Búsqueda (ABB)
class ABB {
private:
    Nodo* raiz; // Puntero al nodo raíz del árbol

    // --- Funciones auxiliares recursivas para la gestión del ABB ---

    // Función auxiliar recursiva para insertar un nuevo nodo.
    // Se asegura de que la propiedad de orden del ABB se mantenga:
    // valores menores van a la izquierda, valores mayores o iguales van a la derecha.
    Nodo* _insertar(Nodo* nodoActual, int valor);

    // Función auxiliar recursiva para mostrar los nodos en recorrido INORDEN.
    // Este recorrido visita: subárbol izquierdo -> nodo actual -> subárbol derecho.
    // Resulta en una salida de los valores ordenados de forma ascendente.
    void _recorridoInorden(Nodo* nodoActual);

    // Función auxiliar recursiva para mostrar los nodos en recorrido PREORDEN.
    // Este recorrido visita: nodo actual -> subárbol izquierdo -> subárbol derecho.
    // Útil para recrear una copia del árbol.
    void _recorridoPreorden(Nodo* nodoActual);

    // Función auxiliar recursiva para liberar la memoria de todos los nodos.
    // Evita fugas de memoria recorriendo el árbol de forma POSTORDEN (izquierda, derecha, raíz).
    void _eliminarArbol(Nodo* nodoActual);

    // Función auxiliar recursiva para buscar un valor en el ABB.
    // Aprovecha la propiedad de orden del ABB para buscar eficientemente.
    bool _buscar(Nodo* nodoActual, int valor);

    // Función auxiliar recursiva para mostrar la estructura visual del árbol.
    // Utiliza sangría para representar los niveles del árbol.
    void _mostrarEstructura(Nodo* nodoActual, int nivel);

public:
    // Constructor de la clase ABB. Inicializa la raíz a nullptr.
    ABB();

    // Destructor de la clase ABB. Llama a la función para liberar toda la memoria del árbol.
    ~ABB();

    // Función pública para insertar un valor en el ABB.
    // Inicia el proceso de inserción desde la raíz.
    void insertar(int valor);

    // Función pública para mostrar el recorrido INORDEN del ABB.
    void mostrarInorden();

    // Función pública para mostrar el recorrido PREORDEN del ABB.
    void mostrarPreorden();

    // Función pública para mostrar la estructura visual del ABB.
    void mostrarEstructura();

    // Función pública para buscar un valor en el ABB.
    // Retorna true si el valor se encuentra, false en caso contrario.
    bool buscar(int valor);

    // Función pública para verificar si el ABB está vacío.
    // Retorna true si la raíz es nullptr, false en caso contrario.
    bool estaVacio();
};

// Prototipos de funciones auxiliares fuera de la clase (para el main.cpp)
// Estas funciones manejan la interacción con el usuario y la validación de entrada.

// Función para validar la entrada de un entero desde el usuario.
// Utiliza cin.fail() y cin.clear() para manejar errores de tipo de dato.
int obtenerEnteroValido(const char* mensaje);

// Función para limpiar el buffer de entrada después de leer un valor.
void limpiarBuffer();

// Función para pausar la ejecución y esperar que el usuario presione Enter.
void presionarEnterParaContinuar();

#endif // CABECERA_H