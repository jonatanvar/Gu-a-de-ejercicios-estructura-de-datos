//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de una Cola (Queue) usando un arreglo estático y variables de control (frente, final).

#include <iostream> // Para operaciones de entrada/salida (cout, cin).
#include <limits>   // Para numeric_limits (validación de entrada).
#include <string>   // Para std::string y std::to_string.

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// Constante para el tamaño máximo de la cola.
const int MAX_TAMANO_COLA = 5;

// Definición de la estructura para la Cola.
struct Cola {
    int elementos[MAX_TAMANO_COLA]; // Arreglo estático para almacenar los elementos.
    int frente;                     // Índice del elemento frontal de la cola.
    int final;                      // Índice del elemento final de la cola.
};

// Función para inicializar la cola.
void inicializarCola(Cola& cola) {
    cola.frente = -1; // Indica que la cola está vacía.
    cola.final = -1;  // Indica que la cola está vacía.
    cout << "Cola inicializada y vacia.\n";
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

// Función para verificar si la cola está vacía.
bool estaVacia(const Cola& cola) {
    return cola.frente == -1; // O cola.frente > cola.final si no se reinician a -1 al vaciarse.
}

// Función para verificar si la cola está llena.
bool estaLlena(const Cola& cola) {
    // En una implementación lineal, está llena cuando 'final' llega al límite del arreglo.
    return cola.final == MAX_TAMANO_COLA - 1;
}

// Función enqueue: agrega un elemento al final de la cola.
void enqueue(Cola& cola, int elemento) {
    if (estaLlena(cola)) {
        cout << "Error: La cola esta llena. No se puede agregar el elemento " << elemento << ".\n";
    } else {
        if (estaVacia(cola)) { // Si la cola está vacía, el primer elemento también es el frente.
            cola.frente = 0;
        }
        cola.final++; // Incrementa el índice del final.
        cola.elementos[cola.final] = elemento; // Agrega el elemento.
        cout << "Elemento " << elemento << " agregado a la cola.\n";
    }
}

// Función dequeue: elimina y retorna el elemento del frente de la cola.
bool dequeue(Cola& cola, int& elemento) {
    if (estaVacia(cola)) {
        cout << "Error: La cola esta vacia. No se puede extraer ningun elemento.\n";
        return false;
    } else {
        elemento = cola.elementos[cola.frente]; // Obtiene el elemento del frente.
        if (cola.frente == cola.final) { // Si solo queda un elemento, la cola se vacía.
            inicializarCola(cola); // Restablece frente y final a -1.
        } else {
            cola.frente++; // Mueve el frente al siguiente elemento.
        }
        cout << "Elemento " << elemento << " extraido de la cola.\n";
        return true;
    }
}

// Función verFrente: permite ver el elemento del frente sin eliminarlo.
bool verFrente(const Cola& cola, int& elemento) {
    if (estaVacia(cola)) {
        cout << "Error: La cola esta vacia. No hay elemento en el frente.\n";
        return false;
    } else {
        elemento = cola.elementos[cola.frente];
        cout << "El elemento en el frente de la cola es: " << elemento << ".\n";
        return true;
    }
}

// Función para mostrar los elementos de la cola.
void mostrarCola(const Cola& cola) {
    cout << "\n--- Estado actual de la Cola (Frente a Final) ---\n";
    if (estaVacia(cola)) {
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

// Función principal para resolver el Ejercicio 68.
void resolverEjercicio68() {
    Cola miCola;
    inicializarCola(miCola); // Asegura que la cola esté vacía al inicio del ejercicio.

    int opcion;
    int elemento; // Para encolar o para recibir el elemento desencolado.
    bool operacion_exitosa;

    // Limpiar el buffer de entrada antes del primer menú, si fuera necesario (después de cin >> char en main).
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    do {
        cout << "\n--- Menu de Cola (Arreglo Lineal) ---\n";
        cout << "1. Encolar elemento (Enqueue)\n";
        cout << "2. Desencolar elemento (Dequeue)\n";
        cout << "3. Ver elemento del Frente (Front/Peek)\n";
        cout << "4. Verificar si esta Vacia\n";
        cout << "5. Verificar si esta Llena\n";
        cout << "6. Mostrar Cola\n";
        cout << "7. Salir del ejercicio\n";
        opcion = obtenerEnteroValido(std::string("Selecciona una opcion: ").c_str());

        switch (opcion) {
            case 1:
                elemento = obtenerEnteroValido(std::string("Ingresa el elemento a encolar (entero): ").c_str());
                enqueue(miCola, elemento);
                break;
            case 2:
                operacion_exitosa = dequeue(miCola, elemento);
                // El mensaje ya se imprime dentro de dequeue.
                break;
            case 3:
                operacion_exitosa = verFrente(miCola, elemento);
                // El mensaje ya se imprime dentro de verFrente.
                break;
            case 4:
                if (estaVacia(miCola)) {
                    cout << "La cola esta Vacia.\n";
                } else {
                    cout << "La cola NO esta Vacia.\n";
                }
                break;
            case 5:
                if (estaLlena(miCola)) {
                    cout << "La cola esta Llena.\n";
                } else {
                    cout << "La cola NO esta Llena.\n";
                }
                break;
            case 6:
                mostrarCola(miCola);
                break;
            case 7:
                cout << "Saliendo del ejercicio de cola.\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
                break;
        }
    } while (opcion != 7);
}