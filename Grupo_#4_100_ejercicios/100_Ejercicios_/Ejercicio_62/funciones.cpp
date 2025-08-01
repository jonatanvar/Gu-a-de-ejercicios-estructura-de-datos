//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de la función push para una pila, incluyendo validación si está llena.

#include <iostream> // Para operaciones de entrada/salida (cout, cin).
#include <limits>   // Para numeric_limits (validación de entrada).
#include <string>   // Para std::string y std::to_string.

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// Constante para el tamaño máximo de la pila.
const int MAX_TAMANO_PILA = 5;

// Definición de la estructura para la Pila.
struct Pila {
    int elementos[MAX_TAMANO_PILA]; // Arreglo estático para almacenar los elementos.
    int cima;                       // Índice de la cima de la pila (-1 para pila vacía).
};

// Función para inicializar la pila.
void inicializarPila(Pila& pila) {
    pila.cima = -1; // La pila está vacía cuando cima es -1.
    cout << "Pila inicializada y vacia.\n";
}

// Función auxiliar para obtener y validar un entero.
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

// Función para verificar si la pila está llena.
bool estaLlena(const Pila& pila) {
    return pila.cima == MAX_TAMANO_PILA - 1;
}

// Función push: agrega un elemento a la pila.
void push(Pila& pila, int elemento) {
    if (estaLlena(pila)) {
        cout << "Error: La pila esta llena. No se puede agregar el elemento " << elemento << ".\n";
    } else {
        pila.cima++; // Incrementa la cima.
        pila.elementos[pila.cima] = elemento; // Agrega el elemento.
        cout << "Elemento " << elemento << " agregado a la pila.\n";
    }
}

// Función para mostrar los elementos de la pila (desde la cima hasta la base).
void mostrarPila(const Pila& pila) {
    cout << "\n--- Estado actual de la Pila (Cima a Base) ---\n";
    if (pila.cima == -1) {
        cout << "La pila esta vacia.\n";
    } else {
        for (int i = pila.cima; i >= 0; --i) {
            cout << "| " << pila.elementos[i] << " |\n";
            if (i == pila.cima) {
                cout << "-----(Cima)\n";
            }
        }
        cout << "------------\n";
    }
}

// Función principal para resolver el Ejercicio 62.
void resolverEjercicio62() {
    Pila miPila;
    inicializarPila(miPila); // Asegura que la pila esté vacía al inicio del ejercicio.

    int opcion;
    int elemento_a_insertar;

    // Limpiar el buffer de entrada antes del primer menú.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    do {
        cout << "\n--- Menu de Pila (Funcion Push) ---\n";
        cout << "1. Agregar elemento (Push)\n";
        cout << "2. Mostrar Pila\n";
        cout << "3. Salir del ejercicio\n";
        // Corrección aplicada: convertir el literal a std::string antes de .c_str()
        opcion = obtenerEnteroValido(std::string("Selecciona una opcion: ").c_str());

        switch (opcion) {
            case 1:
                // ¡CORRECCIÓN AQUÍ! Convertir el literal a std::string antes de .c_str()
                elemento_a_insertar = obtenerEnteroValido(std::string("Ingresa el elemento a agregar (entero): ").c_str());
                push(miPila, elemento_a_insertar);
                break;
            case 2:
                mostrarPila(miPila);
                break;
            case 3:
                cout << "Saliendo del ejercicio de pila.\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
                break;
        }
    } while (opcion != 3);
}