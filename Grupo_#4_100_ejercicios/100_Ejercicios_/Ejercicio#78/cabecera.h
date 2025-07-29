#ifndef CABECERA_H
#define CABECERA_H

// Estructura de un nodo del árbol
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el árbol binario
class ArbolBinario {
private:
    Nodo* raiz;

    // Funciones auxiliares recursivas
    void insertarRecursivo(Nodo*& nodo, int valor);
    void preordenRecursivo(Nodo* nodo);
    void destruirRecursivo(Nodo* nodo);
    void imprimirArbolRecursivo(Nodo* nodo, int espacio);
    bool esVacioRecursivo(Nodo* nodo);

public:
    ArbolBinario(); // Constructor
    ~ArbolBinario(); // Destructor

    void insertar(int valor);
    void mostrarPreorden();
    void mostrarEstructura();
    bool estaVacio();
};

// Prototipos de funciones globales para la interacción del usuario
void limpiarPantalla();
void pausar();
int obtenerOpcionValida();

#endif // CABECERA_H