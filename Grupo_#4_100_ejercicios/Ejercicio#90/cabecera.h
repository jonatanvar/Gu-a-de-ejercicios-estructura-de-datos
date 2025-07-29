#ifndef CABECERA_H
#define CABECERA_H

#include <iostream>
#include <vector>

using namespace std;

// Concepto: Un Nodo es el bloque fundamental de nuestro árbol binario.
// Cada nodo contiene un valor numérico y punteros a sus "hijos" (sub-árboles).
// 'izq' apunta al hijo izquierdo, 'der' apunta al hijo derecho.
// Si un hijo no existe, su puntero será nullptr.
struct Nodo {
    double dato; // El valor numérico que este nodo almacena.
    Nodo* izq;   // Puntero al sub-árbol izquierdo.
    Nodo* der;   // Puntero al sub-árbol derecho.

    // Constructor para inicializar un nuevo nodo.
    // Cuando creamos un nodo, inicialmente no tiene hijos, por eso izq y der son nullptr.
    Nodo(double val) : dato(val), izq(nullptr), der(nullptr) {}
};

// Concepto: El ArbolBinario es una estructura de datos jerárquica.
// Un Árbol Binario de Búsqueda (ABB) es un tipo especial donde:
// 1. Todos los valores en el sub-árbol izquierdo de un nodo son menores que el valor del nodo.
// 2. Todos los valores en el sub-árbol derecho de un nodo son mayores o iguales que el valor del nodo.
// Esto permite búsquedas, inserciones y eliminaciones eficientes.
class ArbolBinario {
private:
    Nodo* raiz; // La "raíz" es el primer nodo del árbol, el punto de entrada.
                // Es como la puerta principal de tu casa, desde ahí accedes a todo lo demás.

public:
    // Constructor de la clase. Inicializa la raíz a nullptr, indicando que el árbol está vacío.
    ArbolBinario();

    // Destructor de la clase. Se encarga de liberar toda la memoria ocupada por los nodos del árbol
    // para evitar "fugas de memoria" (memory leaks).
    ~ArbolBinario();

    // Inserta un nuevo valor en el árbol, manteniendo la propiedad de ABB.
    void insertar(double valor);

    // Función auxiliar recursiva para insertar un valor. Trabaja directamente con nodos.
    // Concepto de recursividad: Una función que se llama a sí misma para resolver un problema más pequeño
    // hasta llegar a un caso base (aquí, cuando encuentra un lugar vacío para insertar el nodo).
    void insertarRecursivo(Nodo*& nodo, double valor);

    // Función auxiliar recursiva para destruir todos los nodos del árbol,
    // liberando la memoria. Se utiliza en el destructor.
    void destruirArbol(Nodo* nodo);

    // Recorre el árbol y recolecta todos los datos en un vector.
    // Recorrido Inorden: Visita el sub-árbol izquierdo, luego el nodo actual, luego el sub-árbol derecho.
    // Esto asegura que los datos se recolecten en orden ascendente.
    void recolectarDatos(Nodo* nodo, vector<double>& datos);

    // Muestra los datos del árbol en orden ascendente utilizando un recorrido inorden.
    void mostrarInorden();

    // Función auxiliar recursiva para mostrar los datos en orden inorden.
    void mostrarInordenRecursivo(Nodo* nodo);

    // Calcula la media aritmética de todos los datos en el árbol.
    // La media es el promedio de los datos, el "centro" de tu conjunto de datos.
    double calcularMediaDesdeArbol();

    // Calcula la desviación estándar poblacional de todos los datos en el árbol.
    // La desviación estándar mide cuánto se "dispersan" o se "alejan" los datos de la media.
    double calcularDesviacionEstandarDesdeArbol();

    // Verifica si el árbol está vacío.
    bool estaVacio();
};

// --- Funciones auxiliares globales para cálculos estadísticos y matemáticos ---

// Concepto: Raíz cuadrada manual. No podemos usar <cmath>, así que la implementamos.
// El método de Newton-Raphson es un algoritmo iterativo que encuentra aproximaciones
// sucesivamente mejores de las raíces (o ceros) de una función.
// Para la raíz cuadrada de 'x', buscamos 'y' tal que y*y = x. Es decir, el cero de f(y) = y*y - x.
// La fórmula de iteración es: x_n+1 = x_n - f(x_n) / f'(x_n)
// Para f(y) = y*y - x, f'(y) = 2*y.
// Entonces, y_n+1 = y_n - (y_n*y_n - x) / (2*y_n)
// Simplificando: y_n+1 = (y_n + x / y_n) / 2
double raizCuadrada(double numero);

// Calcula la media aritmética de un vector de datos.
// Fórmula: Suma de todos los datos / Número total de datos.
double calcularMedia(vector<double>& datos);

// Calcula la varianza poblacional de un vector de datos.
// Concepto: La varianza mide el promedio de los cuadrados de las diferencias de cada dato respecto a la media.
// Nos dice cuán lejos están, en promedio, los datos de la media.
// Al elevar al cuadrado las diferencias, nos aseguramos de que las desviaciones negativas y positivas
// contribuyan por igual y penalizamos más las desviaciones grandes.
// Fórmula: Σ((xi - μ)²) / N, donde xi es cada dato, μ es la media, y N es el número de datos.
double calcularVarianza(vector<double>& datos, double media);

// Calcula la desviación estándar poblacional de un vector de datos.
// Concepto: La desviación estándar es la raíz cuadrada de la varianza.
// Es una medida de dispersión muy útil porque está en las mismas unidades que los datos originales,
// lo que la hace más fácil de interpretar que la varianza.
// Analogía: Imagina que la **media** es el punto central de un grupo de amigos que están en un parque.
// La **desviación estándar** es como la "cuerda elástica" que los une.
// - Si la desviación estándar es **pequeña**, la cuerda es corta, y todos los amigos están muy cerca del centro,
//   agrupados. Esto significa que los datos están poco dispersos, muy concentrados alrededor de la media.
// - Si la desviación estándar es **grande**, la cuerda es larga, y los amigos pueden estar muy separados
//   del centro, e incluso muy separados entre sí. Esto significa que los datos están muy dispersos,
//   alejados de la media.
// Fórmula: σ = √(Varianza) = √(Σ((xi - μ)²) / N)
double calcularDesviacionEstandar(vector<double>& datos);

// Función para manejar la entrada de números de forma segura.
// Utiliza cin.fail() y cin.clear() para detectar y corregir errores de entrada.
double obtenerEntradaNumerica();

// Pausa la ejecución del programa hasta que el usuario presione Enter.
void pausa();

#endif // CABECERA_H