//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para encontrar el menor elemento en un arreglo unidimensional.

#include <iostream> // Incluye la librería estándar para operaciones de entrada/salida.
#include <limits>   // Incluye esta librería para numeric_limits y streamsize para validación de entrada.
using namespace std; // Usa el espacio de nombres estándar para facilitar el acceso a cout, cin, etc.

// Define un tamaño máximo para el arreglo estático.
const int MAX_SIZE = 100;

// Implementación de la función para resolver el Ejercicio 19: Menor elemento en arreglo.
void resolverEjercicio19() {
    int arr[MAX_SIZE]; // Declaración de un arreglo estático para almacenar los números.
    int num_elements;  // Variable para almacenar la cantidad de elementos que el usuario desea usar.

    // Bucle para solicitar y validar la cantidad de elementos del arreglo.
    while (true) {
        cout << "Ingresa la cantidad de elementos (max " << MAX_SIZE << "): ";
        cin >> num_elements;

        if (cin.fail() || num_elements <= 0 || num_elements > MAX_SIZE) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero positivo no mayor a " << MAX_SIZE << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Bucle para solicitar y validar cada elemento del arreglo.
    cout << "Ingresa los " << num_elements << " elementos del arreglo:\n";
    for (int i = 0; i < num_elements; ++i) {
        while (true) {
            cout << "Elemento " << (i + 1) << ": ";
            cin >> arr[i];

            if (cin.fail()) {
                cout << "Entrada invalida. Por favor, ingresa un numero entero.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    }

    // Si no hay elementos, no se puede encontrar el menor.
    if (num_elements == 0) {
        cout << "No hay elementos en el arreglo para encontrar el menor.\n";
        return;
    }

    // Lógica para encontrar el menor elemento en el arreglo.
    int menor = arr[0]; // Asume que el primer elemento es el menor inicialmente.

    // Recorre el resto del arreglo para encontrar el verdadero menor.
    for (int i = 1; i < num_elements; ++i) {
        if (arr[i] < menor) {
            menor = arr[i]; // Si encuentra un elemento menor, actualiza 'menor'.
        }
    }

    // Imprime el resultado final: el menor elemento encontrado.
    cout << "El menor elemento en el arreglo es: " << menor << endl;
}