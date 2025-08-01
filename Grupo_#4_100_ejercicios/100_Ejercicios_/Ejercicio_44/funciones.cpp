//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para reemplazar todas las ocurrencias de una subcadena por otra en una cadena, sin usar funciones de biblioteca estándar.

#include <iostream> // Incluye la librería estándar para operaciones de entrada/salida.
#include <limits>   // Incluye esta librería para numeric_limits y streamsize para validación de entrada.
#include <string>   // Incluye esta librería para std::string y std::to_string (para prompts).
using namespace std; // Usa el espacio de nombres estándar.

// Define la longitud máxima para las cadenas de entrada y la cadena resultante.
const int MAX_INPUT_LENGTH = 100;
// La cadena resultante puede crecer, se le da un tamaño generoso.
const int MAX_RESULT_LENGTH = MAX_INPUT_LENGTH * 3; // Suficiente para varias sustituciones de cadena corta por larga.

// Función para obtener la longitud de una cadena de caracteres manualmente.
int obtenerLongitudCadena(const char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

// Función para obtener una cadena de caracteres del usuario con validación.
void obtenerCadena(char* str, int max_len, const char* prompt) {
    while (true) {
        cout << prompt;
        cin.getline(str, max_len);

        if (cin.fail()) {
            cout << "La cadena es demasiado larga o hubo un error. Maximo " << (max_len - 1) << " caracteres.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Permitir cadenas vacías para subcadena a buscar/reemplazar si se desea,
            // pero para la cadena principal, se pide que no esté vacía.
            // Para este ejercicio, vamos a permitir que las subcadenas a buscar/reemplazar puedan ser vacías
            // si el problema lo permitiera, pero si no son vacías, no pueden exceder la longitud máxima.
            break; // Entrada válida.
        }
    }
}

// Función para buscar la primera ocurrencia de una subcadena (manual, similar a strstr).
// Retorna un puntero al inicio de la subcadena encontrada o nullptr si no se encuentra.
const char* buscarSubcadena(const char* principal, const char* buscar) {
    if (!*buscar) return principal; // Subcadena a buscar vacía, siempre "encontrada" al inicio.

    const char* p1 = principal;
    while (*p1 != '\0') {
        const char* p1_temp = p1;
        const char* p2_temp = buscar;
        while (*p2_temp != '\0' && *p1_temp == *p2_temp) {
            p1_temp++;
            p2_temp++;
        }
        if (*p2_temp == '\0') { // Si llegamos al final de 'buscar', significa que la encontramos.
            return p1;
        }
        p1++;
    }
    return nullptr; // No se encontró la subcadena.
}

// Función para copiar una porción de una cadena a otra (manual).
// Copia 'longitud' caracteres desde 'origen' a 'destino'.
void copiarCadenas(char* destino, const char* origen, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        destino[i] = origen[i];
    }
}

// Función para reemplazar todas las ocurrencias de una subcadena por otra.
// Requiere un buffer 'resultado' lo suficientemente grande.
void reemplazarSubcadena(const char* principal, const char* buscar, const char* reemplazar, char* resultado, int max_len_resultado) {
    int len_buscar = obtenerLongitudCadena(buscar);
    int len_reemplazar = obtenerLongitudCadena(reemplazar);
    int idx_resultado = 0; // Índice actual en la cadena resultante.
    const char* current_pos = principal; // Posición actual en la cadena principal.
    const char* found_pos; // Posición donde se encuentra la subcadena a buscar.

    // Reiniciar la cadena resultado
    resultado[0] = '\0';

    // Bucle principal para buscar y reemplazar
    while (*current_pos != '\0') {
        found_pos = buscarSubcadena(current_pos, buscar);

        if (found_pos == nullptr) { // Si no se encuentra más la subcadena a buscar
            // Copiar el resto de la cadena principal
            while (*current_pos != '\0' && idx_resultado < max_len_resultado - 1) {
                resultado[idx_resultado++] = *current_pos++;
            }
            break; // Salir del bucle
        } else {
            // Copiar la parte de la cadena principal antes de la ocurrencia
            int chars_before = found_pos - current_pos;
            for (int i = 0; i < chars_before && idx_resultado < max_len_resultado - 1; ++i) {
                resultado[idx_resultado++] = current_pos[i];
            }

            // Copiar la subcadena de reemplazo
            for (int i = 0; i < len_reemplazar && idx_resultado < max_len_resultado - 1; ++i) {
                resultado[idx_resultado++] = reemplazar[i];
            }

            // Mover la posición actual en la cadena principal después de la ocurrencia encontrada
            current_pos = found_pos + len_buscar;
        }
    }
    resultado[idx_resultado] = '\0'; // Asegurar terminación nula de la cadena resultante.
}

// Función principal para resolver el Ejercicio 44.
void resolverEjercicio44() {
    char cadena_principal[MAX_INPUT_LENGTH];
    char subcadena_buscar[MAX_INPUT_LENGTH];
    char subcadena_reemplazar[MAX_INPUT_LENGTH];
    char cadena_final[MAX_RESULT_LENGTH]; // Cadena donde se almacenará el resultado.

    // Limpiar el buffer de entrada antes de la primera lectura de cadena
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Obtener las cadenas del usuario
    obtenerCadena(cadena_principal, MAX_INPUT_LENGTH, ("Ingresa la cadena principal (max " + to_string(MAX_INPUT_LENGTH - 1) + " caracteres): ").c_str());
    obtenerCadena(subcadena_buscar, MAX_INPUT_LENGTH, ("Ingresa la subcadena a buscar (max " + to_string(MAX_INPUT_LENGTH - 1) + " caracteres): ").c_str());
    obtenerCadena(subcadena_reemplazar, MAX_INPUT_LENGTH, ("Ingresa la subcadena de reemplazo (max " + to_string(MAX_INPUT_LENGTH - 1) + " caracteres): ").c_str());

    cout << "\nCadena original: " << cadena_principal << endl;
    cout << "Subcadena a buscar: " << subcadena_buscar << endl;
    cout << "Subcadena de reemplazo: " << subcadena_reemplazar << endl;

    // Realizar el reemplazo
    reemplazarSubcadena(cadena_principal, subcadena_buscar, subcadena_reemplazar, cadena_final, MAX_RESULT_LENGTH);

    cout << "Cadena final: " << cadena_final << endl;
}