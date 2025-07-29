#include "cabecera.h" // Incluye el archivo de cabecera donde se declaran las estructuras y la clase.

// Implementación del constructor.
// Inicializa el puntero 'cabeza' a nullptr, indicando que la lista está vacía.
ListaFrecuencia::ListaFrecuencia() : cabeza(nullptr) {}

// Implementación del destructor.
// Se asegura de que toda la memoria dinámica asignada para los nodos sea liberada
// cuando un objeto ListaFrecuencia sale de alcance o es destruido.
ListaFrecuencia::~ListaFrecuencia() {
    destruirLista(); // Llama a la función auxiliar para liberar los nodos.
}

// Implementación de la función auxiliar para buscar un carácter.
// Recorre la lista desde la cabeza hasta encontrar el carácter o el final de la lista.
Nodo* ListaFrecuencia::buscarCaracter(char caracter) {
    Nodo* actual = cabeza; // Comienza desde la cabeza.
    while (actual != nullptr) { // Mientras no se llegue al final de la lista.
        if (actual->caracter == caracter) { // Si el carácter es encontrado.
            return actual; // Retorna el puntero al nodo.
        }
        actual = actual->siguiente; // Avanza al siguiente nodo.
    }
    return nullptr; // Si el carácter no se encuentra, retorna nullptr.
}

// Implementación de la función auxiliar para insertar un nodo al final.
// Crea un nuevo nodo y lo añade al final de la lista.
void ListaFrecuencia::insertarAlFinal(char caracter) {
    // Crea un nuevo nodo dinámicamente.
    // Concepto: Gestión de Memoria Dinámica (new)
    // 'new Nodo()' asigna memoria en el 'heap' para un nuevo objeto Nodo
    // y devuelve un puntero a esa ubicación.
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->caracter = caracter;
    nuevoNodo->frecuencia = 1; // La primera aparición del carácter.
    nuevoNodo->siguiente = nullptr; // Este será el nuevo último nodo.

    if (cabeza == nullptr) { // Si la lista está vacía.
        cabeza = nuevoNodo; // El nuevo nodo se convierte en la cabeza.
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) { // Recorre la lista hasta el último nodo.
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo; // El último nodo ahora apunta al nuevo nodo.
    }
}

// Implementación de la función principal para insertar o actualizar un carácter.
void ListaFrecuencia::insertar(char caracter) {
    Nodo* nodoExistente = buscarCaracter(caracter); // Intenta encontrar el carácter.
    if (nodoExistente != nullptr) {
        nodoExistente->frecuencia++; // Si ya existe, incrementa su frecuencia.
    } else {
        insertarAlFinal(caracter); // Si no existe, lo añade como nuevo nodo.
    }
}

// Implementación de la función para analizar una cadena.
void ListaFrecuencia::analizarCadena(const char* cadena) {
    if (cadena == nullptr) return; // Evitar el procesamiento de cadenas nulas.

    // Recorre la cadena de texto carácter por carácter.
    // Restricción: No se permite <cstring>, así que implementamos strlen manualmente.
    for (int i = 0; cadena[i] != '\0'; ++i) { // '\0' marca el final de una cadena C-style.
        insertar(cadena[i]); // Inserta o actualiza la frecuencia del carácter.
    }
}

// Implementación de la función para mostrar las frecuencias.
void ListaFrecuencia::mostrarFrecuencias() {
    if (cabeza == nullptr) { // Verifica si la lista está vacía.
        cout << "La lista de frecuencias esta vacia. Ingrese una cadena primero." << endl;
        return;
    }

    cout << "\n--- Frecuencias de Caracteres ---" << endl;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "'" << actual->caracter << "': " << actual->frecuencia << " veces" << endl;
        actual = actual->siguiente;
    }
    cout << "---------------------------------" << endl;
}

// Implementación de la función para mostrar estadísticas.
void ListaFrecuencia::mostrarEstadisticas() {
    if (cabeza == nullptr) { // Verifica si la lista está vacía.
        cout << "La lista de frecuencias esta vacia. Ingrese una cadena primero." << endl;
        return;
    }

    int totalCaracteres = 0;
    int caracteresUnicos = 0;
    char caracterMasFrecuente = ' ';
    int maxFrecuencia = 0;

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        totalCaracteres += actual->frecuencia; // Suma todas las frecuencias para el total de caracteres.
        caracteresUnicos++; // Cada nodo representa un carácter único.

        if (actual->frecuencia > maxFrecuencia) { // Encuentra el carácter con mayor frecuencia.
            maxFrecuencia = actual->frecuencia;
            caracterMasFrecuente = actual->caracter;
        }
        actual = actual->siguiente;
    }

    cout << "\n--- Estadisticas de Analisis ---" << endl;
    cout << "Total de caracteres procesados: " << totalCaracteres << endl;
    cout << "Caracteres unicos encontrados: " << caracteresUnicos << endl;
    if (totalCaracteres > 0) { // Solo mostrar si hay caracteres para evitar division por cero o valores sin sentido.
        cout << "Caracter mas frecuente: '" << caracterMasFrecuente << "' (" << maxFrecuencia << " veces)" << endl;
    }
    cout << "--------------------------------" << endl;
}

// Implementación de la función para limpiar la lista.
void ListaFrecuencia::limpiarLista() {
    destruirLista(); // Llama a la función auxiliar para liberar los nodos.
    cabeza = nullptr; // Asegura que la cabeza sea nullptr después de limpiar.
    cout << "Datos de la lista limpiados." << endl;
}

// Implementación de la función auxiliar para destruir la lista.
// Concepto: Gestión de Memoria Dinámica (delete)
// 'delete' libera la memoria que fue asignada previamente con 'new'.
// Es crucial liberar la memoria de cada nodo para evitar 'fugas de memoria'.
void ListaFrecuencia::destruirLista() {
    Nodo* actual = cabeza;
    Nodo* siguienteNodo;
    while (actual != nullptr) { // Recorre la lista.
        siguienteNodo = actual->siguiente; // Guarda el puntero al siguiente nodo.
        delete actual; // Libera la memoria del nodo actual.
        actual = siguienteNodo; // Avanza al siguiente nodo.
    }
    cabeza = nullptr; // Una vez que todos los nodos han sido liberados, la cabeza apunta a nullptr.
}