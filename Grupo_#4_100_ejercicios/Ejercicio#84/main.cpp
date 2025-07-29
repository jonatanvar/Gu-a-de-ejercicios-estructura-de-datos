// PROMPT PARA INSERCIÓN EN ABB
// Necesito que me hagas un código de C++ en la versión 20 del lenguaje. Te especificaré de manera muy detallada lo que necesito para que así sea la respuesta completa. Es para una clase llamada Estructura de Datos, específicamente sobre Árboles Binarios de Búsqueda (ABB).

// EJERCICIO:
// Insertar nodo en ABB: Función para agregar nodos respetando la propiedad de orden del ABB.

// ESPECIFICACIONES TÉCNICAS:

// ESTRUCTURA DE DATOS ABB:
// Implementar un Árbol Binario de Búsqueda usando struct/class
// Cada nodo debe tener: dato (int), puntero izquierdo, puntero derecho

// PROPIEDAD FUNDAMENTAL: Para cualquier nodo N:
// Todos los valores del subárbol IZQUIERDO < N
// Todos los valores del subárbol DERECHO ≥ N

// Usar gestión de memoria dinámica (new/delete)

// FUNCIÓN DE INSERCIÓN PRINCIPAL:
// Algoritmo recursivo que respete la propiedad del ABB
// Criterio exacto: menores van izquierda, mayores o iguales derecha
// Manejo de duplicados: permitir inserción de valores iguales a la derecha
// Inserción en hoja: nuevo nodo siempre se inserta como hoja

// RESTRICCIONES ESTRICTAS:
// ÚNICAMENTE usar #include <iostream>
// PROHIBIDO usar cualquier otra librería como:
// #include <limits> (para std::numeric_limits)
// #include <vector>, #include <queue>, #include <stack>
// #include <string>, #include <algorithm>, etc.
// OBLIGATORIO usar using namespace std; en TODOS los archivos (.h, .cpp)
// Programación estructurada en C++20
// Validación de entrada usando SOLO funciones básicas de iostream

// FUNCIONALIDADES REQUERIDAS:
// MENÚ INTERACTIVO:

// === ÁRBOL BINARIO DE BÚSQUEDA (ABB) ===
// 1. Insertar valor en el ABB
// 2. Mostrar recorrido INORDEN (muestra valores ordenados)
// 3. Mostrar recorrido PREORDEN
// 4. Mostrar estructura visual del árbol
// 5. Buscar un valor en el ABB
// 6. Verificar si está vacío
// 7. Salir
// Seleccione opción:

// VALIDACIONES REQUERIDAS:
// Validar entrada numérica usando SOLO cin.fail() y cin.clear()
// NO USAR std::numeric_limits ni otras librerías para validación
// Manejar opciones inválidas del menú con bucles simples
// Verificar árbol vacío antes de operaciones
// Confirmar inserción exitosa con mensaje
// Manejo completo de memoria (evitar memory leaks)
// Limpiar buffer de entrada usando cin.ignore(1000, '\n')

// DEMOSTRACIÓN DE LA PROPIEDAD ABB:
// Ejemplo con valores: 8, 3, 10, 1, 6, 14, 4, 7, 13

// Estructura resultante debe ser:
//         8
//        / \
//       3   10
//      / \    \
//     1   6    14
//        / \   /
//       4   7 13

// Recorrido INORDEN: 1 3 4 6 7 8 10 13 14 (¡ORDENADO!)
// Recorrido PREORDEN: 8 3 1 6 4 7 10 14 13

// FUNCIÓN DE BÚSQUEDA EFICIENTE:
// Complejidad: O(log n) en promedio, O(n) en peor caso
// Algoritmo: comparar con nodo actual y decidir subárbol
// Retorno: true/false según si encuentra el valor

// REQUERIMIENTOS ADICIONALES:

// INTERACCIÓN CON USUARIO:
// Mensajes explicativos sobre la propiedad ABB
// Confirmación de cada inserción realizada
// Explicación de por qué inorden muestra valores ordenados
// Pausa entre operaciones ("Presione Enter...")
// Manejo elegante de errores

// DEMOSTRACIÓN EDUCATIVA:
// Incluir opción para insertar el ejemplo predefinido (8,3,10,1,6,14,4,7,13)
// Mostrar cómo el recorrido inorden produce secuencia ordenada
// Explicar la eficiencia de búsqueda en ABB vs búsqueda lineal

// GESTIÓN DE MEMORIA:
// Constructor/destructor apropiados
// Función recursiva para liberar todos los nodos
// Inicialización correcta de punteros (nullptr)

// ESTRUCTURA DE ARCHIVOS REQUERIDA:
// 1. cabecera.h

// cpp
// #include <iostream>
// using namespace std;
// Include guards (#ifndef, #define, #endif)
// Declaraciones de struct Nodo, class ABB y prototipos de funciones
// SOLO declaraciones, NO implementaciones

// 2. definiciones.cpp

// cpp
// #include "cabecera.h"
// using namespace std;
// Implementación de TODAS las funciones de la clase ABB
// Funciones recursivas de inserción, búsqueda, recorridos
// Validación de entrada usando SOLO cin/cout (sin std::numeric_limits)

// 3. main.cpp

// cpp
// Autoría: [Jonatan Varea]
// Fecha: 23 de julio de 2025
// #include "cabecera.h"
// using namespace std;
// Función main() con menú interactivo
// Mensaje de bienvenida explicando qué es un ABB
// Demostración de todas las funcionalidades

// 4. CMakeLists.txt

// cmake
// Configuración para compilar en CLion
// C++20 standard
// Executable que compile los 3 archivos cpp

// AUTORÍA Y FORMATO:
// Comentarios: En español, explicando la propiedad ABB
// Nombres descriptivos: Variables y funciones claras

// Por favor, proporciona:
// Los 4 archivos completos con la estructura solicitada
// Comentarios detallados explicando la propiedad ABB en cada función
// Separación correcta: declaraciones en .h, implementaciones en definiciones.cpp
// Ejemplo de ejecución mostrando todas las opciones del menú
// Explicación de por qué el algoritmo mantiene la propiedad ABB
// Instrucciones de compilación para CLion

// ¿Puedes generar estos 4 archivos que demuestren claramente cómo funciona la inserción en un ABB respetando la estructura modular solicitada?

// Autoría: [Jonatan Varea]
// Fecha: 23 de julio de 2025

#include "cabecera.h"
#include <iostream> // Ya incluido en cabecera.h, pero buena práctica si se usa directamente aquí.

using namespace std;

// Función main() con el menú interactivo para el ABB.
int main() {
    // Mensaje de bienvenida explicando qué es un ABB.
    cout << "========================================" << endl;
    cout << "  BIENVENIDO AL SIMULADOR DE ARBOLES" << endl;
    cout << "     BINARIOS DE BUSQUEDA (ABB)" << endl;
    cout << "========================================" << endl;
    cout << "Un Arbol Binario de Busqueda (ABB) es una estructura de datos jerarquica" << endl;
    cout << "donde cada nodo tiene, como maximo, dos hijos (izquierdo y derecho)." << endl;
    cout << "La clave para su eficiencia es la 'Propiedad del ABB':" << endl;
    cout << "  - Todos los valores en el subarbol IZQUIERDO de un nodo N son MENORES que N." << endl;
    cout << "  - Todos los valores en el subarbol DERECHO de un nodo N son MAYORES O IGUALES que N." << endl;
    cout << "Esto permite busquedas, inserciones y eliminaciones muy eficientes en promedio." << endl;
    presionarEnterParaContinuar();

    ABB miArbol; // Creamos una instancia de nuestro Árbol Binario de Búsqueda.
    int opcion;
    int valor;

    do {
        cout << "\n=== ARBOL BINARIO DE BUSQUEDA (ABB) ===" << endl;
        cout << "1. Insertar valor en el ABB" << endl;
        cout << "2. Mostrar recorrido INORDEN (muestra valores ordenados)" << endl;
        cout << "3. Mostrar recorrido PREORDEN" << endl;
        cout << "4. Mostrar estructura visual del arbol" << endl;
        cout << "5. Buscar un valor en el ABB" << endl;
        cout << "6. Verificar si esta vacio" << endl;
        cout << "7. Insertar ejemplo predefinido (8, 3, 10, 1, 6, 14, 4, 7, 13)" << endl; // Nueva opción para demostración
        cout << "8. Salir" << endl;
        cout << "Seleccione opcion: ";

        opcion = obtenerEnteroValido(""); // Reutilizamos la función para validar la entrada del menú

        switch (opcion) {
            case 1:
                valor = obtenerEnteroValido("Ingrese el valor entero a insertar: ");
                miArbol.insertar(valor);
                presionarEnterParaContinuar();
                break;
            case 2:
                miArbol.mostrarInorden();
                presionarEnterParaContinuar();
                break;
            case 3:
                miArbol.mostrarPreorden();
                presionarEnterParaContinuar();
                break;
            case 4:
                miArbol.mostrarEstructura();
                presionarEnterParaContinuar();
                break;
            case 5:
                valor = obtenerEnteroValido("Ingrese el valor a buscar: ");
                miArbol.buscar(valor);
                presionarEnterParaContinuar();
                break;
            case 6:
                if (miArbol.estaVacio()) {
                    cout << "El arbol esta Vacio." << endl;
                } else {
                    cout << "El arbol NO esta vacio." << endl;
                }
                presionarEnterParaContinuar();
                break;
            case 7: { // Bloque para la nueva opción del ejemplo predefinido
                cout << "Insertando valores del ejemplo: 8, 3, 10, 1, 6, 14, 4, 7, 13" << endl;
                miArbol.insertar(8);
                miArbol.insertar(3);
                miArbol.insertar(10);
                miArbol.insertar(1);
                miArbol.insertar(6);
                miArbol.insertar(14);
                miArbol.insertar(4);
                miArbol.insertar(7);
                miArbol.insertar(13);
                cout << "\nValores de ejemplo insertados. Observe la estructura resultante:" << endl;
                miArbol.mostrarEstructura();
                presionarEnterParaContinuar();
                cout << "Ahora, vea como el recorrido INORDEN los ordena:" << endl;
                miArbol.mostrarInorden();
                presionarEnterParaContinuar();
                break;
            }
            case 8:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion del 1 al 8." << endl;
                presionarEnterParaContinuar();
                break;
        }
    } while (opcion != 8);

    return 0;
}