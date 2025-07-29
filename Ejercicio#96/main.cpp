// Necesito que me hagas un código de C++ en la versión 20 del lenguaje. Te especificaré de manera muy detallada lo que necesito para que así sea la respuesta completa. Es para una clase llamada Estructura de Datos, específicamente sobre Listas Enlazadas aplicadas al análisis de texto.

// EJERCICIO:

// Implementar una Lista Enlazada Simple que permita realizar un análisis de frecuencia de caracteres en una cadena de texto. El programa debe contar cuántas veces aparece cada carácter en la cadena ingresada por el usuario, almacenando esta información en una lista enlazada donde cada nodo contiene un carácter y su frecuencia de aparición.

// ESPECIFICACIONES TÉCNICAS:

// ESTRUCTURA DE DATOS PARA LISTAS ENLAZADAS:

// - Implementar una Lista Enlazada Simple usando nodos dinámicos con punteros.

// - Cada nodo debe contener: Un carácter (char) como dato, un entero (int) para la frecuencia, y un puntero al siguiente nodo (Nodo* siguiente).

// - Usar gestión de memoria dinámica (new/delete) para crear y destruir nodos.

// - La lista crece dinámicamente a medida que se insertan nuevos nodos.

// FUNCIONALIDAD FUNDAMENTAL: Análisis de frecuencia de caracteres:

// - Procesar una cadena de texto carácter por carácter.

// - Para cada carácter: Si ya existe en la lista, incrementar su frecuencia. Si no existe, insertarlo como nuevo nodo con frecuencia 1.

// - Recorrido de la lista para mostrar resultados.

// - Calcular estadísticas como total de caracteres, caracteres únicos, y carácter más frecuente.

// RESTRICCIONES ESTRICTAS:

// - ÚNICAMENTE usar #include <iostream>. (No se permite <cstring>, <vector>, <list>, <map>, etc.)

// - OBLIGATORIO usar using namespace std; únicamente en el archivo cabecera.h.

// - NO USAR contenedores STL como std::list o std::map.

// - Implementar manualmente cualquier función auxiliar necesaria (por ejemplo, para calcular la longitud de una cadena C-style).

// FUNCIONES OBLIGATORIAS PARA LA LISTA:

// struct Nodo {

//     char caracter;

//     int frecuencia;

//     Nodo* siguiente;

// };

// class ListaFrecuencia {

// private:

//     Nodo* cabeza;

//     Nodo* buscarCaracter(char caracter);

//     void insertarAlFinal(char caracter);

//     void destruirLista();

// public:

//     ListaFrecuencia();

//     ~ListaFrecuencia();

//     void insertar(char caracter);

//     void analizarCadena(const char* cadena);

//     void mostrarFrecuencias();

//     void mostrarEstadisticas();

//     void limpiarLista();

// };

// MENÚ INTERACTIVO:

// === ANÁLISIS DE FRECUENCIA DE CARACTERES ===

// 1. Ingresar cadena de texto

// 2. Mostrar frecuencias

// 3. Mostrar estadísticas

// 4. Limpiar datos

// 5. Salir

// Seleccione opción:

// VALIDACIONES REQUERIDAS:

// - Validar entrada de texto usando SOLO cin.fail() y cin.clear().

// - Verificar que la lista no esté vacía antes de mostrar resultados.

// - Manejar correctamente la longitud máxima de las cadenas de entrada.

// - Limpiar buffer de entrada usando cin.ignore(1000, '\n').

// GESTIÓN DINÁMICA DE MEMORIA:

// - Creación de nodos usando new Nodo().

// - Liberación de nodos usando delete.

// - Implementar un destructor ~ListaFrecuencia() que libere toda la memoria de la lista iterativamente.

// - Manejar correctamente punteros nullptr.

// ESTRUCTURA DE ARCHIVOS REQUERIDA:

// 1. cabecera.h - Include guards, declaración de struct Nodo, declaración de class ListaFrecuencia. DEBE INCLUIR #include <iostream> y using namespace std;.

// 2. definiciones.cpp - Implementación de todas las funciones de la clase ListaFrecuencia. NO DEBE INCLUIR #include <iostream> ni using namespace std; (los hereda de cabecera.h).

// 3. main.cpp - Función main() con menú interactivo completo. NO DEBE INCLUIR #include <iostream> ni using namespace std; (los hereda de cabecera.h). La autoría y fecha deben ir comentad
// Autor: Jonatan Varela
// Fecha: 24 de julio de 2025

#include "cabecera.h" // Incluye el archivo de cabecera. Hereda #include <iostream> y using namespace std;

// Función para obtener la longitud de una cadena C-style manualmente.
// Restricción: No se permite <cstring>, por lo que implementamos strlen.
int mi_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') { // Cuenta caracteres hasta el terminador nulo.
        length++;
    }
    return length;
}

// Función principal del programa.
int main() {
    ListaFrecuencia lista; // Crea un objeto de la clase ListaFrecuencia.
    char cadenaEntrada[256]; // Buffer para la cadena de entrada (longitud máxima de 255 caracteres + '\0').
    int opcion;

    do {
        cout << "\n=== ANALISIS DE FRECUENCIA DE CARACTERES ===" << endl;
        cout << "1. Ingresar cadena de texto" << endl;
        cout << "2. Mostrar frecuencias" << endl;
        cout << "3. Mostrar estadisticas" << endl;
        cout << "4. Limpiar datos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        // Validar entrada de opcion.
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
            cin.clear(); // Limpia el estado de error de cin.
            // Limpia el buffer de entrada para descartar los caracteres restantes.
            cin.ignore(1000, '\n');
            continue; // Vuelve al inicio del bucle.
        }
        // Limpia el buffer de entrada después de leer el número para la siguiente lectura de cadena.
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese la cadena de texto (max 255 caracteres): ";
                cin.getline(cadenaEntrada, sizeof(cadenaEntrada)); // Lee la línea completa.

                // Validar si la cadena fue truncada.
                if (cin.fail()) {
                    cout << "Advertencia: La cadena de texto excedio la longitud maxima y fue truncada." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n'); // Limpia el buffer si la entrada fue demasiado larga.
                }

                if (mi_strlen(cadenaEntrada) > 0) { // Solo analiza si la cadena no está vacía.
                    lista.analizarCadena(cadenaEntrada);
                    cout << "Cadena analizada correctamente." << endl;
                } else {
                    cout << "Cadena de texto vacia. No se ha analizado nada." << endl;
                }
                break;
            case 2:
                lista.mostrarFrecuencias();
                break;
            case 3:
                lista.mostrarEstadisticas();
                break;
            case 4:
                lista.limpiarLista();
                break;
            case 5:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}