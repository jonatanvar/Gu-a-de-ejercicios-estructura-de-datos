#ifndef CABECERA_H
#define CABECERA_H

#include <iostream> // Obligatorio: Necesario para operaciones de entrada/salida como cin y cout.
using namespace std; // Obligatorio: Permite usar cout, cin, etc. sin prefijo std::

// Concepto: Nodo
// Un 'Nodo' es la unidad fundamental de una lista enlazada.
// Contiene un dato (en este caso, un 'caracter' y su 'frecuencia')
// y un 'puntero' ('siguiente') que apunta al siguiente nodo en la secuencia.
struct Nodo {
    char caracter;      // El carácter almacenado en este nodo.
    int frecuencia;     // La frecuencia de aparición de este carácter.
    Nodo* siguiente;    // Puntero al siguiente nodo en la lista. Si es el último, apunta a nullptr.
};

// Concepto: Lista Enlazada Simple
// Una 'Lista Enlazada Simple' es una estructura de datos lineal
// donde cada elemento (nodo) apunta al siguiente.
// No almacena los elementos en ubicaciones de memoria contiguas.
class ListaFrecuencia {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista. Si la lista está vacía, es nullptr.

    // Concepto: Punteros y Memoria Dinámica
    // Los punteros son variables que almacenan direcciones de memoria.
    // La 'Memoria Dinámica' permite asignar y liberar memoria durante la ejecución del programa
    // usando 'new' para asignar y 'delete' para liberar.
    // Esto es crucial para listas enlazadas que crecen o se reducen en tamaño.

    // Función auxiliar para buscar un carácter en la lista.
    // Retorna el puntero al nodo si lo encuentra, nullptr si no.
    Nodo* buscarCaracter(char caracter);

    // Función auxiliar para insertar un nuevo nodo al final de la lista.
    // Se usa cuando un carácter aparece por primera vez.
    void insertarAlFinal(char caracter);

    // Función auxiliar para liberar toda la memoria de la lista.
    // Se llama en el destructor para evitar fugas de memoria.
    void destruirLista();

public:
    // Constructor de la clase ListaFrecuencia.
    // Inicializa la cabeza de la lista a nullptr (lista vacía).
    ListaFrecuencia();

    // Destructor de la clase ListaFrecuencia.
    // Llama a destruirLista() para liberar toda la memoria asignada dinámicamente.
    ~ListaFrecuencia();

    // Inserta un carácter en la lista.
    // Si el carácter ya existe, incrementa su frecuencia; de lo contrario, lo añade.
    void insertar(char caracter);

    // Concepto: Análisis de Frecuencia
    // El 'Análisis de Frecuencia' es un proceso estadístico que cuenta
    // cuántas veces aparece cada elemento (en este caso, cada carácter)
    // en un conjunto de datos (la cadena de texto).
    // Esta función procesa una cadena de texto y actualiza las frecuencias en la lista.
    void analizarCadena(const char* cadena);

    // Concepto: Recorrido de Lista
    // El 'Recorrido de Lista' es el proceso de visitar cada nodo de la lista
    // secuencialmente, comenzando desde la cabeza y siguiendo los punteros 'siguiente'
    // hasta llegar a nullptr (el final de la lista).
    // Esta función muestra los caracteres y sus frecuencias.
    void mostrarFrecuencias();

    // Muestra estadísticas generales sobre la cadena analizada.
    void mostrarEstadisticas();

    // Limpia la lista, eliminando todos los nodos y restableciendo la lista a su estado inicial.
    void limpiarLista();
};

#endif // CABECERA_H