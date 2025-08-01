//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para concatenar dos cadenas de caracteres sin usar funciones de biblioteca estándar.

#include <iostream> // Incluye la librería estándar para operaciones de entrada/salida.
#include <limits>   // Incluye esta librería para numeric_limits y streamsize para validación de entrada.
#include <string>   // Incluye esta librería para std::string y std::to_string (para prompts).
using namespace std; // Usa el espacio de nombres estándar.

// Define la longitud máxima para las cadenas (incluyendo el carácter nulo '\0').
const int MAX_STRING_LENGTH = 100;

// Función para obtener la longitud de una cadena de caracteres manualmente.
// (No usa strlen de <cstring> para cumplir con la restricción)
int obtenerLongitudCadena(const char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

// Función para obtener una cadena de caracteres del usuario.
void obtenerCadena(char* str, int max_len, const char* prompt) {
    while (true) {
        cout << prompt;
        // Usa cin.getline para leer líneas completas, incluyendo espacios.
        // max_len debe ser el tamaño total del buffer (incluyendo espacio para '\0').
        cin.getline(str, max_len);

        // Verifica si la lectura falló o si la cadena es demasiado larga (se truncó).
        // Si cin.fail() es true, significa que el buffer era demasiado pequeño.
        if (cin.fail()) {
            cout << "La cadena es demasiado larga o hubo un error. Maximo " << (max_len - 1) << " caracteres.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer restante.
        } else {
            // Verifica si la primera cadena ingresada está vacía.
            if (str[0] == '\0') {
                cout << "La cadena no puede estar vacia. Intentalo de nuevo.\n";
            } else {
                break; // Entrada válida.
            }
        }
    }
}

// Función para concatenar dos cadenas manualmente en una tercera cadena.
// (No usa strcat de <cstring> para cumplir con la restricción)
void concatenarCadenas(const char* str1, const char* str2, char* resultado, int max_len_resultado) {
    int i = 0;
    int j = 0;

    // Copiar la primera cadena al resultado
    while (str1[i] != '\0' && i < max_len_resultado - 1) { // Asegura no desbordar el buffer
        resultado[i] = str1[i];
        i++;
    }

    // Copiar la segunda cadena al final de la primera en resultado
    // Asegura que no se desborde el buffer y que haya espacio para el nulo final
    while (str2[j] != '\0' && i < max_len_resultado - 1) { 
        resultado[i] = str2[j];
        i++;
        j++;
    }

    resultado[i] = '\0'; // Asegura que la cadena resultante esté terminada en nulo.
}


// Función principal para resolver el Ejercicio 38.
void resolverEjercicio38() {
    char cadena1[MAX_STRING_LENGTH];
    char cadena2[MAX_STRING_LENGTH];
    // La cadena resultante puede ser hasta la suma de las longitudes de las dos cadenas + 1 para el '\0'.
    // Por simplicidad y seguridad, se define el doble del tamaño máximo de una cadena individual.
    char cadena_concatenada[MAX_STRING_LENGTH * 2]; 

    // Limpiar el buffer de entrada antes de la primera lectura de cadena
    // para evitar que queden caracteres del Enter del menú previo.
    // Esto es crucial para cin.getline()
    // Lo moví aquí para que se ejecute siempre antes de pedir las cadenas.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // ¡CORRECCIÓN! Usar .c_str() para convertir std::string a const char*.
    obtenerCadena(cadena1, MAX_STRING_LENGTH, ("Ingresa la primera cadena (max " + to_string(MAX_STRING_LENGTH - 1) + " caracteres): ").c_str());
    // ¡CORRECCIÓN! Usar .c_str() para convertir std::string a const char*.
    obtenerCadena(cadena2, MAX_STRING_LENGTH, ("Ingresa la segunda cadena (max " + to_string(MAX_STRING_LENGTH - 1) + " caracteres): ").c_str());

    cout << "\nPrimera cadena: " << cadena1 << endl;
    cout << "Segunda cadena: " << cadena2 << endl;

    concatenarCadenas(cadena1, cadena2, cadena_concatenada, MAX_STRING_LENGTH * 2);

    cout << "Cadena concatenada: " << cadena_concatenada << endl;
}