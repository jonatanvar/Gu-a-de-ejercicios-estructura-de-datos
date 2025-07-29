#include "cabecera.h" // Incluimos el archivo de cabecera para acceder a las declaraciones.

using namespace std; // Usamos el espacio de nombres estándar para evitar std:: prefijos.

// --- Implementación de Funciones Auxiliares Globales ---

// Implementación del método de Newton-Raphson para la raíz cuadrada.
// Esta función es vital ya que no podemos usar <cmath>.
double raizCuadrada(double numero) {
    if (numero < 0) {
        // La raíz cuadrada de un número negativo no es un número real.
        // En este contexto, retornamos 0 o podrías manejar un error más específico.
        return 0.0;
    }
    if (numero == 0) {
        return 0.0;
    }

    double estimacion = numero; // Una primera estimación puede ser el número mismo.
    double error = 0.0001;      // Definimos un umbral de error para la precisión.
    double diferencia;

    // Iteramos hasta que la diferencia entre la estimación actual y la siguiente sea muy pequeña.
    do {
        double siguienteEstimacion = 0.5 * (estimacion + numero / estimacion);
        diferencia = estimacion - siguienteEstimacion;
        if (diferencia < 0) { // Nos aseguramos de que la diferencia sea siempre positiva para la comparación.
            diferencia = -diferencia;
        }
        estimacion = siguienteEstimacion;
    } while (diferencia > error); // Continuamos iterando mientras la diferencia sea mayor que el error permitido.

    return estimacion;
}

// Implementación para calcular la media aritmética de un vector de datos.
double calcularMedia(vector<double>& datos) {
    if (datos.empty()) {
        return 0.0; // La media de un conjunto vacío es 0 (o podría ser un error/NaN).
    }
    double suma = 0.0;
    for (double d : datos) {
        suma += d;
    }
    return suma / datos.size(); // La suma de los datos dividida por la cantidad de datos.
}

// Implementación para calcular la varianza poblacional.
double calcularVarianza(vector<double>& datos, double media) {
    if (datos.empty()) {
        return 0.0; // Varianza de un conjunto vacío es 0.
    }
    double sumaDiferenciasCuadrado = 0.0;
    for (double d : datos) {
        double diferencia = d - media;
        sumaDiferenciasCuadrado += (diferencia * diferencia); // (xi - μ)²
    }
    // Dividimos por el número total de elementos (N) para la varianza poblacional.
    return sumaDiferenciasCuadrado / datos.size();
}

// Implementación para calcular la desviación estándar poblacional.
double calcularDesviacionEstandar(vector<double>& datos) {
    if (datos.empty()) {
        return 0.0; // Desviación estándar de un conjunto vacío es 0.
    }
    double media = calcularMedia(datos); // Primero necesitamos la media.
    double varianza = calcularVarianza(datos, media); // Luego la varianza.
    return raizCuadrada(varianza); // Finalmente, la raíz cuadrada de la varianza.
}

// Implementación para obtener entrada numérica segura del usuario.
double obtenerEntradaNumerica() {
    double valor;
    while (!(cin >> valor)) { // Intenta leer un double. Si falla...
        cout << "Entrada invalida. Por favor, ingrese un numero valido: ";
        cin.clear(); // Limpia el estado de error de cin.
        cin.ignore(1000, '\n'); // Ignora hasta 1000 caracteres o hasta el salto de línea.
    }
    cin.ignore(1000, '\n'); // Limpia el buffer después de una lectura exitosa.
    return valor;
}

// Implementación de la función de pausa.
void pausa() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(1000, '\n'); // Asegura que el buffer esté limpio antes de esperar Enter.
    cin.get(); // Espera una pulsación de Enter.
}

// --- Implementación de Métodos de la Clase ArbolBinario ---

// Constructor: Inicializa la raíz del árbol a nulo.
ArbolBinario::ArbolBinario() : raiz(nullptr) {}

// Destructor: Llama a una función auxiliar para liberar toda la memoria del árbol.
ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

// Función auxiliar recursiva para destruir los nodos del árbol.
void ArbolBinario::destruirArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izq); // Destruye el sub-árbol izquierdo.
        destruirArbol(nodo->der); // Destruye el sub-árbol derecho.
        // Finalmente, elimina el nodo actual. Esto es un recorrido postorden implícito para la destrucción.
        delete nodo;
    }
}

// Inserta un valor en el árbol. Es la interfaz pública para el usuario.
void ArbolBinario::insertar(double valor) {
    insertarRecursivo(raiz, valor); // Llama a la función recursiva que hace el trabajo pesado.
}

// Función recursiva para insertar un valor en el ABB.
void ArbolBinario::insertarRecursivo(Nodo*& nodo, double valor) {
    // Caso base: Si el nodo actual es nulo, hemos encontrado el lugar para insertar el nuevo nodo.
    if (nodo == nullptr) {
        nodo = new Nodo(valor); // Creamos un nuevo nodo y lo asignamos al puntero.
        cout << "Dato " << valor << " insertado correctamente en el arbol." << endl;
        return;
    }

    // Si el valor es menor, vamos al sub-árbol izquierdo.
    if (valor < nodo->dato) {
        insertarRecursivo(nodo->izq, valor);
    }
    // Si el valor es mayor o igual, vamos al sub-árbol derecho.
    else {
        insertarRecursivo(nodo->der, valor);
    }
}

// Recolecta todos los datos del árbol en un vector utilizando un recorrido inorden.
void ArbolBinario::recolectarDatos(Nodo* nodo, vector<double>& datos) {
    if (nodo != nullptr) {
        recolectarDatos(nodo->izq, datos); // Recorre el sub-árbol izquierdo.
        datos.push_back(nodo->dato);       // Agrega el dato del nodo actual.
        recolectarDatos(nodo->der, datos); // Recorre el sub-árbol derecho.
    }
}

// Muestra los datos del árbol en orden ascendente (inorden).
void ArbolBinario::mostrarInorden() {
    if (estaVacio()) {
        cout << "El arbol esta vacio. No hay datos para mostrar." << endl;
        return;
    }
    cout << "Datos en el arbol (recorrido Inorden): ";
    mostrarInordenRecursivo(raiz); // Llama a la función auxiliar recursiva.
    cout << endl;
}

// Función auxiliar recursiva para mostrar los datos inorden.
void ArbolBinario::mostrarInordenRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        mostrarInordenRecursivo(nodo->izq); // Visita el sub-árbol izquierdo.
        cout << nodo->dato << " ";         // Visita el nodo actual.
        mostrarInordenRecursivo(nodo->der); // Visita el sub-árbol derecho.
    }
}

// Calcula la media de los datos almacenados en el árbol.
double ArbolBinario::calcularMediaDesdeArbol() {
    vector<double> datos;
    recolectarDatos(raiz, datos); // Primero, recolecta todos los datos del árbol.

    if (datos.empty()) {
        cout << "Error: El arbol esta vacio. No se puede calcular la media." << endl;
        return 0.0;
    }
    return calcularMedia(datos); // Utiliza la función auxiliar global.
}

// Calcula la desviación estándar de los datos almacenados en el árbol.
double ArbolBinario::calcularDesviacionEstandarDesdeArbol() {
    vector<double> datos;
    recolectarDatos(raiz, datos); // Recolecta los datos.

    if (datos.size() < 2) { // Necesitamos al menos dos puntos para una desviación estándar significativa.
        cout << "Error: Necesita al menos dos datos en el arbol para calcular la desviacion estandar. Datos actuales: " << datos.size() << endl;
        return 0.0;
    }
    return calcularDesviacionEstandar(datos); // Utiliza la función auxiliar global.
}

// Verifica si el árbol está vacío.
bool ArbolBinario::estaVacio() {
    return raiz == nullptr;
}