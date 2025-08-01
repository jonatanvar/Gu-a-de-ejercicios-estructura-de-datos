//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para buscar libros por un autor dado.

#include <iostream> // Para operaciones de entrada/salida (cout, cin).
#include <limits>   // Para numeric_limits (validación de entrada).
#include <string>   // Para std::string y std::to_string.
#include <cctype>   // Para std::tolower.

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// Constante para el número máximo de libros.
const int MAX_LIBROS = 10;

// Definición de la estructura para un Libro.
struct Libro {
    string titulo;
    string autor;
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

// Función auxiliar para obtener una cadena (std::string) del usuario.
// Se usa para leer líneas completas incluyendo espacios.
void obtenerCadena(string& str, const char* prompt) {
    cout << prompt;
    getline(cin, str);
    // No se necesita verificar cin.fail() para getline con std::string en este contexto
    // a menos que se necesite manejo de errores de EOF o memoria, lo cual es raro para input de usuario.
    // Simplemente se asegura que no esté vacía si es un requisito.
    while (str.empty()) {
        cout << "La entrada no puede estar vacia. Por favor, intentalo de nuevo: ";
        getline(cin, str);
    }
}

// Función para convertir una cadena a minúsculas para comparaciones insensibles a mayúsculas/minúsculas.
string aMinusculas(const string& str) {
    string lower_str = str;
    for (char& c : lower_str) {
        c = tolower(c); // tolower requiere <cctype>
    }
    return lower_str;
}

// Función para pedir los datos de un libro (título y autor).
void pedirDatosLibro(Libro& libro) {
    cout << "\n--- Ingreso de datos para Libro ---\n";
    obtenerCadena(libro.titulo, "Titulo del libro: ");
    obtenerCadena(libro.autor, "Autor del libro: ");
}

// Función para mostrar la información de un libro.
void mostrarLibro(const Libro& libro) {
    cout << "  Titulo: \"" << libro.titulo << "\", Autor: " << libro.autor << endl;
}

// Función para buscar y mostrar todos los libros de un autor dado.
void buscarLibrosPorAutor(const Libro lista_libros[], int num_libros, const string& autor_buscar) {
    bool encontrado = false;
    string autor_buscar_lower = aMinusculas(autor_buscar); // Convertir a minúsculas para comparación.

    cout << "\n--- Libros encontrados para el autor \"" << autor_buscar << "\" ---\n";
    for (int i = 0; i < num_libros; ++i) {
        // Compara el autor del libro (convertido a minúsculas) con el autor buscado (también en minúsculas).
        if (aMinusculas(lista_libros[i].autor) == autor_buscar_lower) {
            mostrarLibro(lista_libros[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron libros para el autor \"" << autor_buscar << "\".\n";
    }
}

// Función principal para resolver el Ejercicio 56.
void resolverEjercicio56() {
    Libro lista_libros[MAX_LIBROS]; // Arreglo de estructuras Libro.
    int num_libros; // Cantidad real de libros a registrar.

    // Limpiar el buffer de entrada antes de la primera lectura de cadena en resolverEjercicio56
    // (después del cin >> continuar del main).
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Bucle para solicitar y validar la cantidad de libros.
    num_libros = obtenerEnteroPositivoValido(("Ingresa la cantidad de libros a registrar (max " + to_string(MAX_LIBROS) + "): ").c_str());
    while (num_libros > MAX_LIBROS) {
        cout << "La cantidad de libros excede el maximo permitido (" << MAX_LIBROS << ").\n";
        num_libros = obtenerEnteroPositivoValido(("Ingresa la cantidad de libros a registrar (max " + to_string(MAX_LIBROS) + "): ").c_str());
    }

    // Recorre para pedir datos de cada libro
    for (int i = 0; i < num_libros; ++i) {
        pedirDatosLibro(lista_libros[i]);
    }

    cout << "\n--- Todos los Libros Registrados ---\n";
    for (int i = 0; i < num_libros; ++i) {
        mostrarLibro(lista_libros[i]);
    }

    // Pedir al usuario el autor a buscar
    string autor_buscar;
    cout << "\n-------------------------------------\n";
    obtenerCadena(autor_buscar, "Ingresa el nombre del autor a buscar: ");
    
    buscarLibrosPorAutor(lista_libros, num_libros, autor_buscar);
}