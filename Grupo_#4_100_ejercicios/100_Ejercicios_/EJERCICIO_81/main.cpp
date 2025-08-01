// Nombre: Jorge Mendoza
// Autoría: Annie
// Fecha: 22/07/2025.
// PROMPT:
// Este código fue creado mediante un agente llamado Annie al cual se le dan una serie de instrucciones que puede y no puede hacer dentro de nuestro código solo se pega el enunciado y el agente nos genera nuestro código.
// Necesito que me hagas un código de C++ en la versión 20 del lenguaje. Te daré las indicaciones, las restricciones y puntos en los que tienes que tener mayor cuidado a la hora de generar el Prompt.
// Este es el ejercicio: Función que determine si un valor existe en el árbol binario.
// Restricciones: Necesito que me hagas este ejercicio usando una estructura de datos de tipo árbol binario, implementado con un 'struct' para el nodo que contenga un 'dato' y punteros 'izquierda' y 'derecha' (usando NULL para punteros nulos)
// SÓLO debes usar #include <iostream>. NO usar librerías externas (como <limits>, <iomanip>, <cstring>, <string>, etc.) en NINGUNO de los archivos (.h o .cpp). Usa 'using namespace std;'.
// El código debe estar dividido en tres archivos: 'funciones.h' (para las declaraciones), 'procedimientos.cpp' (para las implementaciones) y 'main.cpp' (para la lógica principal).
// Incluye funciones para la gestión del árbol como 'crearNodo', 'insertar' y la función de búsqueda principal. Debe haber una función para validar la entrada de números enteros.
// Debe haber una función para preguntar al usuario si desea repetir la operación, validando su respuesta.
// El programa principal ('main.cpp') debe:
// 1. Crear un árbol binario (puedes insertar algunos valores predefinidos para pruebas o permitir la inserción inicial por menú).
// 2. Presentar un menú o una forma clara de solicitar al usuario el valor a buscar.
// 3. Mostrar el resultado de la búsqueda.
// 4. Preguntar al usuario si quiere realizar otra búsqueda y permitirle continuar o salir.

#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    Nodo* raiz = nullptr; // Inicializa la raíz del árbol a NULL, indicando que el árbol está vacío.
    int opcion;

    cout << "Bienvenido al programa de Arbol Binario de Busqueda (BST). :)\n";

    do {
        // Mostrar menú de opciones.
        cout << "\n--- Menu de Operaciones de BST ---\n";
        cout << "1. Insertar un valor en el arbol\n";
        cout << "2. Buscar un valor en el arbol\n";
        cout << "3. Salir\n";

        // Solicita y valida la opción del menú.
        opcion = validarEntradaNumerica("Seleccione una opcion (1-3): ");

        // Estructura 'switch' para manejar las diferentes operaciones del árbol.
        switch (opcion) {
            case 1: { // Insertar un valor.
                int valor = validarEntradaNumerica("Ingrese el valor a insertar en el arbol: ");
                raiz = insertarNodo(raiz, valor); // Llama a la función para insertar.
                cout << "Valor " << valor << " insertado.\n";
                break;
            }
            case 2: { // Buscar un valor.
                if (raiz == nullptr) {
                    cout << "El arbol esta vacio. No hay elementos para buscar.\n";
                    break;
                }
                int valorBuscar = validarEntradaNumerica("Ingrese el valor a buscar en el arbol: ");
                if (buscarNodo(raiz, valorBuscar)) { // Llama a la función para buscar.
                    cout << "El valor " << valorBuscar << " SI se ha encontrado en el arbol.\n";
                } else {
                    cout << "El valor " << valorBuscar << " NO se ha encontrado en el arbol.\n";
                }
                break;
            }
            case 3:
                cout << "\nGracias por usar el programa. :)\n";
                break;
            default: // Opción no válida.
                cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }

    } while (opcion != 3);
    return 0;
}