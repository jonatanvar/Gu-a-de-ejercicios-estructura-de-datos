// PROMPT PARA IMPLEMENTACIÓN DE ÁRBOL BINARIO CON CÁLCULO DE DESVIACIÓN ESTÁNDAR

// Necesito que me hagas un código de C++ en la versión 20 del lenguaje. Te especificaré de manera muy detallada lo que necesito para que así sea la respuesta completa. Es para una clase llamada Estructura de Datos, específicamente sobre Árboles Binarios y análisis estadístico de datos almacenados en estructuras jerárquicas.

// EJERCICIO:

// Implementar un Árbol Binario de Búsqueda (ABB) que permita almacenar valores numéricos (double) y calcular la desviación estándar de los datos almacenados en el árbol. La desviación estándar mide la dispersión de los datos respecto a la media.

// ESPECIFICACIONES TÉCNICAS:

// ESTRUCTURA DE DATOS PARA ÁRBOLES BINARIOS:

// Implementar un Árbol Binario de Búsqueda usando nodos dinámicos con punteros.

// Cada nodo debe contener:Un valor de tipo double.

// Un puntero al hijo izquierdo (Nodo* izq).

// Un puntero al hijo derecho (Nodo* der).

// La inserción de nodos debe seguir el criterio de ABB: valores menores a la izquierda, mayores o iguales a la derecha.

// Usar gestión de memoria dinámica (new/delete) para crear y destruir nodos.

// FUNCIONALIDAD FUNDAMENTAL: Calcular medidas de dispersión estadística desde el árbol:

// Recorrido del árbol para recolectar todos los valores en un contenedor auxiliar (por ejemplo, un std::vector<double>).

// Media aritmética de los valores almacenados en el árbol.

// Varianza poblacional de los valores almacenados.

// Desviación estándar poblacional de los valores almacenados.

// Fórmula para desviación estándar poblacional: σ = √(Σ(xi - μ)² / N)

// FUNCIÓN DE CÁLCULO PRINCIPAL:

// Algoritmo matemático preciso para desviación estándar aplicado a datos recolectados del árbol.

// Precisión decimal: usar tipo double para todos los cálculos.

// Validación de datos: verificar que el árbol no esté vacío antes de calcular.

// RESTRICCIONES ESTRICTAS:

// ÚNICAMENTE usar #include <iostream> y #include <vector>.

// PROHIBIDO usar cualquier otra librería como:#include <cmath> (para sqrt, pow)

// #include <array>, #include <numeric>

// #include <algorithm>, #include <iomanip>, etc.

// OBLIGATORIO usar using namespace std; en TODOS los archivos (.h, .cpp).

// IMPLEMENTAR MANUALMENTE:Una función raizCuadrada(double numero) usando el método de Newton-Raphson.

// Una función double calcularMedia(vector<double>& datos) que calcule la media aritmética.

// Una función double calcularVarianza(vector<double>& datos, double media) que calcule la varianza.

// Una función double calcularDesviacionEstandar(vector<double>& datos) que calcule la desviación estándar.

// Programación estructurada en C++20.

// Validación de entrada usando SOLO funciones básicas de iostream.

// FUNCIONES OBLIGATORIAS PARA EL ÁRBOL:

// struct Nodo {

//     double dato;

//     Nodo* izq;

//     Nodo* der;

// };

// class ArbolBinario {

// private:

//     Nodo* raiz;

// public:

//     ArbolBinario();

//     ~ArbolBinario();

//     void insertar(double valor);

//     void insertarRecursivo(Nodo*& nodo, double valor);

//     void destruirArbol(Nodo* nodo); // Para el destructor

//     void recolectarDatos(Nodo* nodo, vector<double>& datos); // Para estadísticas

//     void mostrarInorden(); // Para visualización

//     void mostrarInordenRecursivo(Nodo* nodo);

//     double calcularMediaDesdeArbol();

//     double calcularDesviacionEstandarDesdeArbol();

//     // ... otras funciones auxiliares necesarias

// };

// MENÚ INTERACTIVO:

// === ÁRBOL BINARIO CON ESTADÍSTICAS ===

// 1. Insertar dato en el árbol

// 2. Mostrar árbol (recorrido inorden)

// 3. Calcular media de los datos

// 4. Calcular desviación estándar de los datos

// 5. Mostrar resumen estadístico completo

// 6. Salir

// Seleccione opción:

// VALIDACIONES REQUERIDAS:

// Validar entrada numérica usando SOLO cin.fail() y cin.clear().

// NO USAR std::numeric_limits ni otras librerías para validación.

// Verificar árbol no vacío antes de cálculos estadísticos.

// Manejar división por cero en cálculos.

// Validar tamaño mínimo para cálculos estadísticos.

// Confirmar cada operación con mensaje descriptivo.

// Limpiar buffer de entrada usando cin.ignore(1000, '\n').

// GESTIÓN DINÁMICA DE MEMORIA:

// Creación de nodos usando new Nodo().

// Liberación de nodos usando delete.

// Implementar un destructor ~ArbolBinario() que libere toda la memoria del árbol recursivamente.

// Manejo correcto de punteros nullptr.

// REQUERIMIENTOS ADICIONALES:

// INTERACCIÓN CON USUARIO:

// Explicación clara de cómo se almacenan los datos en el árbol.

// Interpretación práctica de la desviación estándar calculada desde un árbol.

// Formato numérico con 4 decimales de precisión.

// Pausa entre operaciones ("Presione Enter...").

// Mensajes educativos sobre árboles binarios y dispersión de datos.

// DEMOSTRACIÓN EDUCATIVA:

// Incluir conjunto de ejemplo con interpretación de resultados.

// Mostrar paso a paso el cálculo de varianza y desviación estándar desde los datos del árbol.

// Comparar árboles con alta vs baja dispersión.

// INTERPRETACIÓN DE RESULTADOS:

// Desviación baja: datos concentrados cerca de la media.

// Desviación alta: datos dispersos, alejados de la media.

// ESTRUCTURA DE ARCHIVOS REQUERIDA:

// cabecera.h

// #include <iostream>

// using namespace std;

// // Include guards (#ifndef, #define, #endif)

// // Declaración de struct Nodo

// // Declaración de class ArbolBinario y prototipos de funciones

// // SOLO declaraciones, NO implementaciones

// definiciones.h

// #include "arbol.h"

// using namespace std;

// // Implementación de TODAS las funciones de la clase ArbolBinario

// // Función manual de raíz cuadrada (método Newton-Raphson)

// // Algoritmos de cálculo estadístico sin librerías externas

// // Validación de entrada usando SOLO cin/cout

// // Gestión completa de memoria dinámica para nodos

// main.cpp

// // Autoría: [Jonatan Varela]

// // Fecha: [24/07/2025]

// #include "arbol.h"

// using namespace std;

// // Función main() con menú interactivo completo

// // Mensaje de bienvenida explicando conceptos de árboles y estadística

// // Demostración de todas las funcionalidades con ejemplos prácticos

// CMakeLists.txt

// # Configuración para compilar en CLion

// # C++20 standard

// # Executable que compile los 3 archivos cpp

// AUTORÍA Y FORMATO:

// Comentarios: En español, explicando conceptos de árboles y estadística.

// Nombres descriptivos: Variables y funciones matemáticamente y semánticamente claras.

// CONCEPTOS A EXPLICAR:

// Árbol Binario de Búsqueda: Estructura jerárquica con reglas de inserción.

// Nodo, Raíz, Hoja: Componentes fundamentales del árbol.

// Recorrido Inorden: Para obtener datos ordenados.

// Media: Valor central del conjunto de datos.

// Varianza: Promedio de las diferencias al cuadrado respecto a la media.

// Desviación Estándar: Raíz cuadrada de la varianza (mismas unidades que datos).

// Punteros y Memoria Dinámica: Uso de new/delete para nodos.

// Por favor, proporciona:

// Los 4 archivos completos con la estructura solicitada.

// Comentarios detallados explicando cada concepto de árbol y estadístico.

// Separación correcta: declaraciones en .h, implementaciones en .cpp.

// Ejemplo de ejecución mostrando inserciones, recorrido y cálculos estadísticos paso a paso.

// Implementación manual de raíz cuadrada sin usar <cmath>.

// Explicación matemática de por qué funciona cada algoritmo.

// Instrucciones de compilación para CLion.

// Se que eres capaz de satisfacer todo eso!!!


// Autoría: [Jonatan Varela]
// Fecha: [24/07/2025]

#include "cabecera.h" // Incluimos la cabecera que contiene las declaraciones necesarias.
#include "definiciones.h" // Incluimos las implementaciones de las funciones y clases.

using namespace std;

// Función para mostrar el menú de opciones al usuario.
void mostrarMenu() {
    cout << "\n=== ARBOL BINARIO CON ESTADISTICAS ===" << endl;
    cout << "1. Insertar dato en el arbol" << endl;
    cout << "2. Mostrar arbol (recorrido inorden)" << endl;
    cout << "3. Calcular media de los datos" << endl;
    cout << "4. Calcular desviacion estandar de los datos" << endl;
    cout << "5. Mostrar resumen estadistico completo" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione opcion: ";
}

int main() {
    // Explicación de conceptos inicial.
    cout << "*****************************************************" << endl;
    cout << "* BIENVENIDO AL SIMULADOR DE ARBOL BINARIO CON      *" << endl;
    cout << "* ANALISIS ESTADISTICO                              *" << endl;
    cout << "*****************************************************" << endl;
    cout << "\nUn **Arbol Binario de Busqueda (ABB)** es una estructura de datos" << endl;
    cout << "jerarquica donde cada nodo tiene a lo sumo dos hijos." << endl;
    cout << "La clave para un ABB es su regla de insercion:" << endl;
    cout << "  - Valores menores van al sub-arbol izquierdo." << endl;
    cout << "  - Valores mayores o iguales van al sub-arbol derecho." << endl;
    cout << "Esto permite que los datos se mantengan ordenados, facilitando" << endl;
    cout << "operaciones como busqueda y recuperacion de datos." << endl;
    cout << "\nComponentes clave:" << endl;
    cout << "  - **Nodo**: La unidad basica que almacena un dato y punteros a sus hijos." << endl;
    cout << "  - **Raiz**: El nodo superior del arbol, desde donde se inicia todo recorrido." << endl;
    cout << "  - **Hoja**: Un nodo que no tiene hijos." << endl;
    cout << "Un **Recorrido Inorden** visita el sub-arbol izquierdo, luego el nodo actual," << endl;
    cout << "y finalmente el sub-arbol derecho. Esto garantiza que los datos se" << endl;
    cout << "muestren en orden ascendente (de menor a mayor)." << endl;
    cout << "\nAdemas, analizaremos la dispersion de los datos almacenados:" << endl;
    cout << "  - **Media Aritmetica (Promedio)**: El valor central de un conjunto de datos." << endl;
    cout << "  - **Varianza**: Mide que tan dispersos estan los datos respecto a la media." << endl;
    cout << "                  Un valor alto indica que los datos estan muy separados de la media." << endl;
    cout << "  - **Desviacion Estandar (sigma - σ)**: Es la raiz cuadrada de la varianza." << endl;
    cout << "                                         Es mas interpretable porque esta en las" << endl;
    cout << "                                         mismas unidades que los datos originales." << endl;
    cout << "                                         Una **desviacion baja** significa que los" << endl;
    cout << "                                         datos estan concentrados cerca de la media." << endl;
    cout << "                                         Una **desviacion alta** significa que los" << endl;
    cout << "                                         datos estan dispersos, alejados de la media." << endl;
    cout << "\nUsaremos **punteros y memoria dinamica (new/delete)** para construir y destruir" << endl;
    cout << "nuestros nodos de manera eficiente." << endl;
    pausa();

    ArbolBinario miArbol; // Creamos una instancia de nuestro árbol binario.
    int opcion;
    double valor;
    vector<double> datosRecopilados;
    double mediaCalculada, varianzaCalculada, desviacionCalculada;

    // Demostración educativa con conjunto de ejemplo
    cout << "\n--- DEMOSTRACION EDUCATIVA INICIAL ---" << endl;
    cout << "Vamos a insertar algunos datos para una demostracion:" << endl;
    cout << "Insertando: 50.0" << endl; miArbol.insertar(50.0);
    cout << "Insertando: 30.0" << endl; miArbol.insertar(30.0);
    cout << "Insertando: 70.0" << endl; miArbol.insertar(70.0);
    cout << "Insertando: 20.0" << endl; miArbol.insertar(20.0);
    cout << "Insertando: 40.0" << endl; miArbol.insertar(40.0);
    cout << "Insertando: 60.0" << endl; miArbol.insertar(60.0);
    cout << "Insertando: 80.0" << endl; miArbol.insertar(80.0);
    pausa();

    do {
        mostrarMenu();
        opcion = static_cast<int>(obtenerEntradaNumerica()); // Casteamos a int después de validar.

        switch (opcion) {
            case 1:
                cout << "\n--- INSERTAR DATO ---" << endl;
                cout << "Ingrese el valor (double) a insertar: ";
                valor = obtenerEntradaNumerica();
                miArbol.insertar(valor);
                break;
            case 2:
                cout << "\n--- MOSTRAR ARBOL ---" << endl;
                miArbol.mostrarInorden();
                cout << "El recorrido Inorden siempre muestra los datos ordenados de menor a mayor." << endl;
                break;
            case 3:
                cout << "\n--- CALCULAR MEDIA ---" << endl;
                mediaCalculada = miArbol.calcularMediaDesdeArbol();
                if (!miArbol.estaVacio()) {
                    cout.precision(4); // Establece la precisión a 4 decimales.
                    cout << fixed;    // Asegura que se muestren los decimales incluso si son ceros.
                    cout << "La media de los datos en el arbol es: " << mediaCalculada << endl;
                    cout << "La media representa el 'punto de equilibrio' o promedio de todos sus datos." << endl;
                }
                break;
            case 4:
                cout << "\n--- CALCULAR DESVIACION ESTANDAR ---" << endl;
                desviacionCalculada = miArbol.calcularDesviacionEstandarDesdeArbol();
                if (!miArbol.estaVacio() && miArbol.recolectarDatos(miArbol.raiz, datosRecopiladas), datosRecopiladas.size() > 1) {
                    cout.precision(4);
                    cout << fixed;
                    cout << "La desviacion estandar de los datos en el arbol es: " << desviacionCalculada << endl;
                    cout << "Una desviacion estandar baja indica que los datos estan agrupados cerca de la media." << endl;
                    cout << "Una desviacion estandar alta indica que los datos estan mas dispersos." << endl;
                }
                break;
            case 5:
                cout << "\n--- RESUMEN ESTADISTICO COMPLETO ---" << endl;
                if (miArbol.estaVacio()) {
                    cout << "El arbol esta vacio. No se pueden realizar calculos estadisticos." << endl;
                    break;
                }

                // Recolectar datos para los cálculos
                datosRecopiladas.clear(); // Limpiar por si acaso
                miArbol.recolectarDatos(miArbol.raiz, datosRecopiladas);

                if (datosRecopiladas.empty()) {
                    cout << "El arbol esta vacio. No hay datos para el resumen." << endl;
                    break;
                }
                
                cout.precision(4);
                cout << fixed;

                cout << "Recolectando datos del arbol..." << endl;
                cout << "Datos recolectados: [";
                for (size_t i = 0; i < datosRecopiladas.size(); ++i) {
                    cout << datosRecopiladas[i];
                    if (i < datosRecopiladas.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "]" << endl;
                cout << "Cantidad de datos (N): " << datosRecopiladas.size() << endl;

                // Cálculo y explicación de la media
                mediaCalculada = calcularMedia(datosRecopiladas);
                cout << "\n**Paso 1: Calcular la Media (μ)**" << endl;
                cout << "La media (promedio) es la suma de todos los datos dividida por el numero de datos." << endl;
                cout << "Media (μ) = " << mediaCalculada << endl;

                // Cálculo y explicación de la varianza
                if (datosRecopiladas.size() < 2) {
                    cout << "\nNecesita al menos dos datos para calcular varianza y desviacion estandar." << endl;
                } else {
                    varianzaCalculada = calcularVarianza(datosRecopiladas, mediaCalculada);
                    cout << "\n**Paso 2: Calcular la Varianza Poblacional (σ²)**" << endl;
                    cout << "La varianza mide la dispersion de los datos respecto a la media." << endl;
                    cout << "Se calcula como el promedio de los cuadrados de las diferencias entre cada dato y la media." << endl;
                    cout << "Formula: Σ((xi - μ)²) / N" << endl;
                    cout << "Detalle de los cuadrados de las diferencias:" << endl;
                    for (double d : datosRecopiladas) {
                        double diferencia = d - mediaCalculada;
                        cout << "  (" << d << " - " << mediaCalculada << ")^2 = (" << diferencia << ")^2 = " << (diferencia * diferencia) << endl;
                    }
                    cout << "Suma de los cuadrados de las diferencias: ";
                    double sum_diff_sq = 0.0;
                    for (double d : datosRecopiladas) {
                        double diferencia = d - mediaCalculada;
                        sum_diff_sq += (diferencia * diferencia);
                    }
                    cout << sum_diff_sq << endl;
                    cout << "Varianza (σ²) = " << varianzaCalculada << endl;

                    // Cálculo y explicación de la desviación estándar
                    desviacionCalculada = raizCuadrada(varianzaCalculada); // Usamos nuestra función manual
                    cout << "\n**Paso 3: Calcular la Desviacion Estandar Poblacional (σ)**" << endl;
                    cout << "La desviacion estandar es la raiz cuadrada de la varianza." << endl;
                    cout << "Es la medida de dispersion mas comun y se interpreta en las mismas unidades que los datos." << endl;
                    cout << "Formula: σ = √(Varianza)" << endl;
                    cout << "Desviacion estandar (σ) = raizCuadrada(" << varianzaCalculada << ") = " << desviacionCalculada << endl;

                    cout << "\n**Interpretacion de la Desviacion Estandar:**" << endl;
                    cout << "  - Si σ es pequena (" << desviacionCalculada << "), significa que los datos estan muy juntos, cerca de la media." << endl;
                    cout << "    (Piensa en un grupo de amigos muy juntos en el centro de un parque)." << endl;
                    cout << "  - Si σ es grande, significa que los datos estan muy dispersos, lejos de la media." << endl;
                    cout << "    (Piensa en un grupo de amigos esparcidos por todo el parque)." << endl;

                    // Comparación con árboles de alta vs baja dispersión (ejemplo conceptual)
                    cout << "\n**Ejemplo Comparativo (Concepto):**" << endl;
                    cout << "  - Arbol 1 (Poca dispersion): Datos {10, 11, 10, 9, 10} -> Media ~10, Desviacion Estandar muy baja." << endl;
                    cout << "    Todos los datos estan muy cerca del 10." << endl;
                    cout << "  - Arbol 2 (Mucha dispersion): Datos {1, 10, 50, 5, 40} -> Media ~21.2, Desviacion Estandar alta." << endl;
                    cout << "    Los datos estan muy alejados unos de otros y de la media." << endl;
                }
                break;
            case 6:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
        }
        if (opcion != 6) {
            pausa();
        }
    } while (opcion != 6);

    return 0;
}