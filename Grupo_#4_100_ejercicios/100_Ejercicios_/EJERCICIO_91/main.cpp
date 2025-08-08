// Nombre: Belinda Andino.
// Autoria: Sofi.
// Fecha: 7/17/2025.
#include <iostream>
#include "funciones.h"

using namespace std;


int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa para calcular la covarianza entre dos conjuntos de datos. :)\n";

    do {
        int tamanoConjuntos;

        while (true) {
            cout << "Ingrese el tamano de los conjuntos (minimo 2, maximo " << MAX_DATOS << "): ";
            tamanoConjuntos = validarEntradaNumericaInt("");

            if (tamanoConjuntos >= 2 && tamanoConjuntos <= MAX_DATOS) {
                break;
            } else {
                cout << "Error: El tamano de los conjuntos debe ser entre 2 y " << MAX_DATOS << ".\n";
            }
        }

        // Declaramos arreglos dinámicos para almacenar los datos de cada conjunto.
        double* conjuntoX = new double[tamanoConjuntos];
        double* conjuntoY = new double[tamanoConjuntos];

        cout << "\n--- Ingrese los " << tamanoConjuntos << " datos para el Conjunto X ---\n";
        // Bucle para solicitar y validar cada uno de los datos del Conjunto X.
        for (int i = 0; i < tamanoConjuntos; ++i) {
            cout << "Conjunto X - Dato #" << (i + 1) << ": ";
            conjuntoX[i] = validarEntradaNumericaDouble("");
        }

        cout << "\n--- Ingrese los " << tamanoConjuntos << " datos para el Conjunto Y ---\n";
        // Bucle para solicitar y validar cada uno de los datos del Conjunto Y.
        for (int i = 0; i < tamanoConjuntos; ++i) {
            cout << "Conjunto Y - Dato #" << (i + 1) << ": ";
            conjuntoY[i] = validarEntradaNumericaDouble("");
        }

        // Calcula la covarianza llamando a la función correspondiente.
        double covarianzaCalculada = calcularCovarianza(conjuntoX, conjuntoY, tamanoConjuntos);

        // Muestra el resultado de la covarianza.
        if (tamanoConjuntos > 1) {
             cout << "\nLa covarianza entre los dos conjuntos es: " << covarianzaCalculada << "\n";
        }
        // Libera la memoria asignada dinámicamente a los arreglos para evitar fugas de memoria.
        delete[] conjuntoX;
        delete[] conjuntoY;
        conjuntoX = nullptr;
        conjuntoY = nullptr;


        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);

    cout << "\nGracias por usar el programa. :)\n";

    return 0; // El programa finalizó con éxito.
}