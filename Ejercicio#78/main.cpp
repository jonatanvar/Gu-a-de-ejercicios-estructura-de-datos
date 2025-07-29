// Necesito que me hagas un código de C++ en la versión 20 del lenguaje, te especificaré de manera muy detallada lo que necesito para que así sea la respuesta, es para una clase llamada estructura de datos, y una de esas estructuras de árboles.
// Este es el ejercicio: Recorrido preorden: Función que imprima los nodos en orden raíz-izquierda-derecha.
// Restricciones:
// Necesito que me hagas este ejercicios usando una estructura de datos de forma de árbol, ten esta restricción en cuenta SÓLO usar #include <iostream>
// NO usar librerías externas SOLO usar #include <iostream>
// NO usar librerías externas
// No usar ningún tipo de librerías en los 4 archivos como
//    #include <limits> #include <iomanip> tienes prohibido usarlas
// usa el using namespace std;
// me das un menú que permita al usuario una serie de opciones

// === PROGRAMA ÁRBOL BINARIO ===
// 1. Insertar valor en el árbol
// 2. Mostrar recorrido PREORDEN
// 3. Mostrar estructura del árbol
// 4. Verificar si está vacío
// 5. Salir

// claro le das un bienvenida al usuario.

// VALIDACIONES REQUERIDAS:
// Validar entrada numérica (no caracteres)
// Manejar opciones inválidas del menú
// Verificar árbol vacío antes de mostrar recorridos
// Manejo de memoria (evitar memory leaks)

// INTERACCIÓN CON USUARIO:
// Mensajes claros y profesionales
// Pausa entre operaciones ("Presione Enter...")
// Limpieza de pantalla entre operaciones (opcional)
// Manejo de errores con mensajes informativos

// te mando un ejemplo de una salida:

// PREORDEN sigue el orden: RAIZ → IZQUIERDA → DERECHA
// Ejemplo con el árbol de la presentación:
// Valores insertados: 5, 3, 7, 6, 9, 15, 0 
// Estructura resultante: 

//         5 
//        /  \            
//     3      7
//   /       / \ 
//  0       6   9
//                \ 
//                 15

// necesito que me estructures el programa es estas partes

// cabecera.h 
// Declaraciones de struct, class y prototipos de funciones
// Include guards (#ifndef, #define, #endif)

// definiciones.cpp 
// Implementación de todas las funciones
// Incluir cabecera.h

// main.cpp 
// Función main() con menú interactivo
// Mensaje de bienvenida profesional
// Incluir cabecera.h

// un archivo CMakeLists.txt (para compilar en clion)


//Jonatan Varela
//20/07/2025
#include "cabecera.h"
#include <iostream> // Solo esta librería está permitida

using namespace std;

int main() {
    ArbolBinario arbol;
    int opcion;
    int valor;

    cout << "=== BIENVENIDO AL PROGRAMA DE ARBOL BINARIO ===" << endl;

    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Insertar valor en el arbol" << endl;
        cout << "2. Mostrar recorrido PREORDEN" << endl;
        cout << "3. Mostrar estructura del arbol" << endl;
        cout << "4. Verificar si esta vacio" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";

        opcion = obtenerOpcionValida();

        limpiarPantalla(); // Opcional: Limpia la pantalla entre operaciones

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                valor = obtenerOpcionValida(); // Reutiliza la validación para la entrada numérica
                arbol.insertar(valor);
                break;
            case 2:
                arbol.mostrarPreorden();
                break;
            case 3:
                arbol.mostrarEstructura();
                break;
            case 4:
                if (arbol.estaVacio()) {
                    cout << "El arbol esta vacio." << endl;
                } else {
                    cout << "El arbol NO esta vacio." << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
        }

        if (opcion != 5) {
            pausar(); // Pausa para que el usuario pueda leer la salida
            limpiarPantalla(); // Limpia la pantalla después de la pausa para la siguiente iteración
        }

    } while (opcion != 5);

    return 0;
}