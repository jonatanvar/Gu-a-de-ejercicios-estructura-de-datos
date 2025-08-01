//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para identificar al estudiante con el mejor promedio.

#include <iostream>   // Para operaciones de entrada/salida (cout, cin).
#include <limits>     // Para numeric_limits (validación de entrada).
#include <string>     // Para std::string y std::to_string.
#include <iomanip>    // Para std::fixed y std::setprecision (formato de promedios).

// Se asume el uso de namespace std en funciones.cpp para simplificar,
// aunque en un header se evita.
using namespace std;

// Constantes para los límites de estudiantes y notas.
const int MAX_ESTUDIANTES = 10;
const int MAX_NOTAS = 5;

// Definición de la estructura para un Estudiante.
struct Estudiante {
    string nombre;
    float notas[MAX_NOTAS]; // Arreglo estático para las notas.
    int num_notas;         // Cantidad real de notas ingresadas.
    float promedio;        // Promedio calculado.
};

// Función auxiliar para obtener y validar un entero positivo.
int obtenerEnteroPositivoValido(const char* prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail() || valor <= 0) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de una lectura exitosa.
            break;
        }
    }
    return valor;
}

// Función auxiliar para obtener y validar un número flotante.
float obtenerFlotanteValido(const char* prompt) {
    float valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail() || valor < 0) { // Las notas no deben ser negativas.
            cout << "Entrada invalida. Por favor, ingresa un numero valido (no negativo).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer.
            break;
        }
    }
    return valor;
}

// Función para pedir los datos de un estudiante (nombre y notas).
void pedirDatosEstudiante(Estudiante& estudiante, int max_notas_permitidas) {
    cout << "\n--- Ingreso de datos para Estudiante ---\n";
    cout << "Nombre del estudiante: ";
    // Limpiar el buffer antes de leer el nombre con getline
    // Ya se limpia en main.cpp después de la decisión de continuar o en funciones.cpp antes del primer getline.
    // Aquí es para asegurar que si se llama a esta función múltiples veces, no haya problemas.
    // Esto se maneja mejor si getline se usa solo después de un cin.ignore.
    // En este flujo, el cin.ignore del main o el primer cin.ignore en resolverEjercicio50 lo cubre.
    getline(cin, estudiante.nombre);

    // Bucle para solicitar y validar la cantidad de notas.
    while (true) {
        estudiante.num_notas = obtenerEnteroPositivoValido(("Cantidad de notas para " + estudiante.nombre + " (max " + to_string(max_notas_permitidas) + "): ").c_str());
        if (estudiante.num_notas > max_notas_permitidas) {
            cout << "La cantidad de notas excede el maximo permitido (" << max_notas_permitidas << ").\n";
        } else {
            break;
        }
    }

    cout << "Ingresa las " << estudiante.num_notas << " notas para " << estudiante.nombre << ":\n";
    for (int i = 0; i < estudiante.num_notas; ++i) {
        estudiante.notas[i] = obtenerFlotanteValido(("Nota " + to_string(i + 1) + ": ").c_str());
    }
}

// Función para calcular el promedio de un estudiante.
void calcularPromedio(Estudiante& estudiante) {
    float suma_notas = 0.0f;
    for (int i = 0; i < estudiante.num_notas; ++i) {
        suma_notas += estudiante.notas[i];
    }
    estudiante.promedio = (estudiante.num_notas > 0) ? (suma_notas / estudiante.num_notas) : 0.0f;
}

// Función para mostrar la información de un estudiante.
void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre
         << ", Promedio: " << fixed << setprecision(2) << estudiante.promedio << endl;
}

// Función para encontrar al estudiante con el promedio más alto.
void encontrarMejorEstudiante(const Estudiante estudiantes[], int num_estudiantes, Estudiante& mejor_estudiante) {
    if (num_estudiantes <= 0) {
        mejor_estudiante.nombre = "N/A"; // No hay estudiantes.
        mejor_estudiante.promedio = 0.0f;
        return;
    }

    // Inicializar el mejor estudiante con el primero de la lista.
    mejor_estudiante = estudiantes[0]; 

    // Recorrer el resto de estudiantes para encontrar el mejor promedio.
    for (int i = 1; i < num_estudiantes; ++i) {
        if (estudiantes[i].promedio > mejor_estudiante.promedio) {
            mejor_estudiante = estudiantes[i];
        }
    }
}

// Función principal para resolver el Ejercicio 50.
void resolverEjercicio50() {
    Estudiante lista_estudiantes[MAX_ESTUDIANTES]; // Arreglo de estructuras Estudiante.
    int num_estudiantes; // Cantidad real de estudiantes a registrar.

    // Bucle para solicitar y validar la cantidad de estudiantes.
    num_estudiantes = obtenerEnteroPositivoValido(("Ingresa la cantidad de estudiantes (max " + to_string(MAX_ESTUDIANTES) + "): ").c_str());
    while (num_estudiantes > MAX_ESTUDIANTES) {
        cout << "La cantidad de estudiantes excede el maximo permitido (" << MAX_ESTUDIANTES << ").\n";
        num_estudiantes = obtenerEnteroPositivoValido(("Ingresa la cantidad de estudiantes (max " + to_string(MAX_ESTUDIANTES) + "): ").c_str());
    }

    // Recorre para pedir datos de cada estudiante
    for (int i = 0; i < num_estudiantes; ++i) {
        pedirDatosEstudiante(lista_estudiantes[i], MAX_NOTAS);
        calcularPromedio(lista_estudiantes[i]); // Calcula el promedio inmediatamente.
    }

    cout << "\n--- Resumen de Estudiantes ---\n";
    for (int i = 0; i < num_estudiantes; ++i) {
        mostrarEstudiante(lista_estudiantes[i]);
    }

    Estudiante mejor_estudiante;
    encontrarMejorEstudiante(lista_estudiantes, num_estudiantes, mejor_estudiante);

    cout << "\n--- Estudiante con el Mejor Promedio ---\n";
    if (num_estudiantes > 0) {
        mostrarEstudiante(mejor_estudiante);
    } else {
        cout << "No se registraron estudiantes.\n";
    }
}