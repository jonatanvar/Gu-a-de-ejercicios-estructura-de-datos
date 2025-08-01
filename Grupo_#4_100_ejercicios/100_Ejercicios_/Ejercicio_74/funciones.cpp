//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de la funcionalidad para imprimir una cola en orden inverso usando una pila auxiliar.

#include <iostream> // Para operaciones de entrada/salida (cout, cin).
#include <limits>   // Para numeric_limits (validación de entrada).
#include <string>   // Para std::string y std::to_string.

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// --- Constantes ---
const int MAX_TAMANO_COLA = 5;
const int MAX_TAMANO_PILA = 5;

// --- Estructuras ---

// Definición de la estructura para la Cola (reutilizada del Ejercicio 68).
struct Cola {
    int elementos[MAX_TAMANO_COLA]; // Arreglo estático para almacenar los elementos.
    int frente;                     // Índice del elemento frontal de la cola.
    int final;                      // Índice del elemento final de la cola.
};

// Definición de la estructura para la Pila (reutilizada del Ejercicio 62).
struct Pila {
    int elementos[MAX_TAMANO_PILA]; // Arreglo estático para almacenar los elementos.
    int cima;                       // Índice de la cima de la pila (-1 para pila vacía).
};

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

// --- Funciones de Cola (adaptadas del Ejercicio 68) ---

// Inicializar la cola.
void inicializarCola(Cola& cola) {
    cola.frente = -1;
    cola.final = -1;
    // cout << "Cola inicializada y vacia.\n"; // Comentado para no saturar mensajes.
}

// Verificar si la cola está vacía.
bool estaVaciaCola(const Cola& cola) {
    return cola.frente == -1;
}

// Verificar si la cola está llena.
bool estaLlenaCola(const Cola& cola) {
    return cola.final == MAX_TAMANO_COLA - 1;
}

// Encolar un elemento.
void enqueue(Cola& cola, int elemento) {
    if (estaLlenaCola(cola)) {
        cout << "Error (Cola): La cola esta llena. No se puede agregar " << elemento << ".\n";
    } else {
        if (estaVaciaCola(cola)) {
            cola.frente = 0;
        }
        cola.final++;
        cola.elementos[cola.final] = elemento;
        cout << "Elemento " << elemento << " encolado.\n";
    }
}

// Desencolar un elemento.
bool dequeue(Cola& cola, int& elemento) {
    if (estaVaciaCola(cola)) {
        cout << "Error (Cola): La cola esta vacia. No se puede desencolar.\n";
        return false;
    } else {
        elemento = cola.elementos[cola.frente];
        if (cola.frente == cola.final) { // Último elemento, la cola se vacía.
            inicializarCola(cola);
        } else {
            cola.frente++;
        }
        // cout << "Elemento " << elemento << " desencolado.\n"; // Comentado para no saturar mensajes.
        return true;
    }
}

// Mostrar los elementos de la cola.
void mostrarCola(const Cola& cola) {
    cout << "\n--- Estado de la Cola (Frente a Final) ---\n";
    if (estaVaciaCola(cola)) {
        cout << "La cola esta vacia.\n";
    } else {
        cout << "Frente -> ";
        for (int i = cola.frente; i <= cola.final; ++i) {
            cout << cola.elementos[i];
            if (i < cola.final) {
                cout << " | ";
            }
        }
        cout << " <- Final\n";
    }
}

// --- Funciones de Pila (adaptadas del Ejercicio 62) ---

// Inicializar la pila.
void inicializarPila(Pila& pila) {
    pila.cima = -1;
    // cout << "Pila inicializada y vacia.\n"; // Comentado para no saturar mensajes.
}

// Verificar si la pila está vacía.
bool estaVaciaPila(const Pila& pila) {
    return pila.cima == -1;
}

// Verificar si la pila está llena.
bool estaLlenaPila(const Pila& pila) {
    return pila.cima == MAX_TAMANO_PILA - 1;
}

// Empujar un elemento a la pila.
void push(Pila& pila, int elemento) {
    if (estaLlenaPila(pila)) {
        cout << "Error (Pila): La pila esta llena. No se puede agregar " << elemento << ".\n";
    } else {
        pila.cima++;
        pila.elementos[pila.cima] = elemento;
        // cout << "Elemento " << elemento << " empujado a la pila.\n"; // Comentado.
    }
}

// Sacar un elemento de la pila (implementación nueva para este ejercicio).
bool pop(Pila& pila, int& elemento) {
    if (estaVaciaPila(pila)) {
        cout << "Error (Pila): La pila esta vacia. No se puede sacar ningun elemento.\n";
        return false;
    } else {
        elemento = pila.elementos[pila.cima];
        pila.cima--;
        // cout << "Elemento " << elemento << " sacado de la pila.\n"; // Comentado.
        return true;
    }
}

// Mostrar los elementos de la pila (útil para depuración).
void mostrarPila(const Pila& pila) {
    cout << "\n--- Estado de la Pila (Cima a Base) ---\n";
    if (estaVaciaPila(pila)) {
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


// --- Funciones Específicas del Ejercicio 74 ---

// Imprime los elementos de una cola en orden inverso usando una pila auxiliar.
void imprimirColaInversa(Cola& cola_original) {
    Pila pila_auxiliar;
    inicializarPila(pila_auxiliar);
    int elemento;

    cout << "\nInvirtiendo y mostrando cola...\n";

    // Paso 1: Vaciar la cola en la pila auxiliar.
    while (dequeue(cola_original, elemento)) { // dequeue retorna true si hay éxito.
        push(pila_auxiliar, elemento);
    }

    // Paso 2: Vaciar la pila auxiliar e imprimir los elementos.
    cout << "Elementos de la cola en orden inverso: ";
    while (pop(pila_auxiliar, elemento)) { // pop retorna true si hay éxito.
        cout << elemento << " ";
    }
    cout << "\n";
}


// --- Función Principal del Ejercicio ---

void resolverEjercicio74() {
    Cola miCola;
    inicializarCola(miCola);

    // Limpiar el buffer de entrada antes del primer menú.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Opciones para probar la funcionalidad
    int opcion;
    int elemento;

    do {
        cout << "\n--- Menu Ejercicio 74: Imprimir Cola Inversa ---\n";
        cout << "1. Encolar elemento\n";
        cout << "2. Mostrar Cola Actual\n";
        cout << "3. Imprimir Cola en Orden Inverso (Vacia la cola actual)\n";
        cout << "4. Salir del ejercicio\n";
        opcion = obtenerEnteroValido(std::string("Selecciona una opcion: ").c_str());

        switch (opcion) {
            case 1:
                elemento = obtenerEnteroValido(std::string("Ingresa el elemento a encolar (entero): ").c_str());
                enqueue(miCola, elemento);
                break;
            case 2:
                mostrarCola(miCola);
                break;
            case 3:
                if (estaVaciaCola(miCola)) {
                    cout << "La cola esta vacia, no hay nada que invertir.\n";
                } else {
                    imprimirColaInversa(miCola);
                    // La cola 'miCola' ahora estará vacía.
                }
                break;
            case 4:
                cout << "Saliendo del ejercicio de impresion de cola inversa.\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
                break;
        }
    } while (opcion != 4);
}