//Nombre: [Erinson Alvarez]
//Fecha: 30/07/2025
//Descripción: Implementación de funciones para calcular el Coeficiente de Correlación de Pearson entre dos variables.
//Autoría: Gemini
//Prompt: Genera el archivo `funciones.cpp` para el Ejercicio 92: 'Coeficiente de Pearson'. Incluye el nuevo bloque de encabezado, implementa las funciones `obtenerEnteroValido`, `obtenerDobleValido`, `solicitarDatos`, `calcularMedia`, `calcularDesviacionEstandar`, `calcularCovarianza`, `calcularCoeficientePearson`, y `resolverEjercicio92` como se describe en el análisis. Asegura una gestión de memoria adecuada.

#include <iostream>  // Para operaciones de entrada/salida (cout, cin).
#include <vector>    // Para el uso de std::vector para almacenar datos.
#include <cmath>     // Para funciones matemáticas como sqrt y pow.
#include <limits>    // Para numeric_limits (validación de entrada).
#include <string>    // Para std::string y std::to_string.
#include <numeric>   // Para std::accumulate (aunque las sumas se implementarán explícitamente para claridad).
#include <iomanip>   // Para std::fixed y std::setprecision.
#include "funciones.h" // Incluye el archivo de cabecera con los prototipos de funciones.

// Se asume el uso de namespace std para simplificar.
using namespace std;

// --- Funciones Auxiliares Generales ---

// Función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail() || valor <= 0) { // También valida que N sea positivo
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

// Función para obtener y validar un número de punto flotante (double).
double obtenerDobleValido(const char* prompt) {
    double valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer.
            break;
        }
    }
    return valor;
}

// Función para solicitar un conjunto de datos (vector de doubles).
std::vector<double> solicitarDatos(int n, const std::string& varName) {
    std::vector<double> datos(n);
    cout << "Ingresa los " << n << " valores para la variable " << varName << ":\n";
    for (int i = 0; i < n; ++i) {
        datos[i] = obtenerDobleValido(std::string("  " + varName + "[" + to_string(i + 1) + "]: ").c_str());
    }
    return datos;
}

// --- Funciones de Cálculo Estadístico ---

// Función para calcular la media de un conjunto de datos.
double calcularMedia(const std::vector<double>& datos) {
    if (datos.empty()) {
        return 0.0; // Media de un conjunto vacío es 0.
    }
    double suma = 0.0;
    for (double d : datos) {
        suma += d;
    }
    return suma / datos.size();
}

// Función para calcular la desviación estándar de un conjunto de datos.
double calcularDesviacionEstandar(const std::vector<double>& datos, double media) {
    if (datos.empty() || datos.size() == 0) { // Añadir comprobación de size == 0
        return 0.0;
    }
    double sumaDiferenciasCuadrado = 0.0;
    for (double d : datos) {
        sumaDiferenciasCuadrado += pow(d - media, 2);
    }
    return sqrt(sumaDiferenciasCuadrado / datos.size());
}

// Función para calcular la covarianza entre dos conjuntos de datos.
double calcularCovarianza(const std::vector<double>& x, const std::vector<double>& y, double mediaX, double mediaY) {
    if (x.empty() || y.empty() || x.size() != y.size()) {
        return 0.0; // O manejar como error si los tamaños no coinciden.
    }
    double sumaProductosDiferencias = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        sumaProductosDiferencias += (x[i] - mediaX) * (y[i] - mediaY);
    }
    return sumaProductosDiferencias / x.size();
}

// Función para calcular el Coeficiente de Correlación de Pearson.
double calcularCoeficientePearson(const std::vector<double>& x, const std::vector<double>& y) {
    // Verificar que los conjuntos de datos tengan el mismo tamaño y no estén vacíos.
    if (x.empty() || y.empty() || x.size() != y.size()) {
        cout << "Error: Los conjuntos de datos estan vacios o tienen tamanos diferentes.\n";
        return NAN; // Retorna Not-a-Number para indicar un resultado invalido.
    }

    size_t n = x.size();

    // Calcular medias
    double mediaX = calcularMedia(x);
    double mediaY = calcularMedia(y);

    // Calcular desviaciones estándar
    double sigmaX = calcularDesviacionEstandar(x, mediaX);
    double sigmaY = calcularDesviacionEstandar(y, mediaY);

    // Manejar el caso de desviación estándar cero (no hay variabilidad en una de las variables).
    if (sigmaX == 0.0 || sigmaY == 0.0) {
        cout << "Advertencia: La desviacion estandar de una o ambas variables es cero.\n";
        cout << "Esto implica que no hay variabilidad en los datos, la correlacion es indefinida (o cero si se asume).\n";
        return 0.0; // En la práctica, a menudo se asume 0 o NaN. Aquí se retorna 0.0.
    }

    // Calcular covarianza
    double covarianza = calcularCovarianza(x, y, mediaX, mediaY);

    // Calcular coeficiente de Pearson
    return covarianza / (sigmaX * sigmaY);
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio92() {
    cout << "\n--- Ejercicio 92: Coeficiente de Correlacion de Pearson ---\n";

    // Limpiar el buffer de entrada antes del primer menú de opciones.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    int n = obtenerEnteroValido("Ingresa el numero de observaciones (N) para ambas variables: ");

    // Solicitar datos para X e Y
    std::vector<double> x_data = solicitarDatos(n, "X");
    std::vector<double> y_data = solicitarDatos(n, "Y");

    // Calcular el coeficiente de Pearson
    double pearson_r = calcularCoeficientePearson(x_data, y_data);

    // Mostrar el resultado
    cout << fixed << setprecision(4); // Formato para el resultado

    if (isnan(pearson_r)) { // Si el resultado es NaN por error en el input
        cout << "No se pudo calcular el coeficiente de Pearson debido a un error en los datos.\n";
    } else {
        cout << "\nEl Coeficiente de Correlacion de Pearson (r) es: " << pearson_r << "\n";

        // Interpretación básica del coeficiente
        if (pearson_r > 0.7) {
            cout << "Interpretacion: Fuerte relacion lineal positiva.\n";
        } else if (pearson_r > 0.3) {
            cout << "Interpretacion: Moderada relacion lineal positiva.\n";
        } else if (pearson_r > 0.0) {
            cout << "Interpretacion: Debil relacion lineal positiva.\n";
        } else if (pearson_r < -0.7) {
            cout << "Interpretacion: Fuerte relacion lineal negativa.\n";
        } else if (pearson_r < -0.3) {
            cout << "Interpretacion: Moderada relacion lineal negativa.\n";
        } else if (pearson_r < 0.0) {
            cout << "Interpretacion: Debil relacion lineal negativa.\n";
        } else {
            cout << "Interpretacion: No hay relacion lineal aparente.\n";
        }
    }
    cout << "------------------------------------------------------------\n";
}