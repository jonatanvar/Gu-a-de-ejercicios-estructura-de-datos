// Autor: Jorge Mendoza.
// Fecha: 7/21/2025.

#include <iostream>
using namespace std;

// Función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir() {
    int repetir;

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir;

        if (cin.fail() || repetir < 1 || repetir > 2) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return repetir;
}

int main() {
    int repetir;
    cout <<"Bienvenido al programa de Suma de dos numeros.\n";

    do {
        double numero1;
        double numero2;

        while (true) {
            cout << "Por favor, ingrese el primer numero: ";
            cin >> numero1;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        while (true) {
            cout << "Por favor, ingrese el segundo numero: ";
            cin >> numero2;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        double resultadoSuma = numero1 + numero2;
        cout << "La suma de " << numero1 << " y " << numero2 << " es: " << resultadoSuma << "\n";

        repetir = preguntarRepetir();

    } while (repetir == 1);

    cout << "\nGracias por usar el programa.\n";
    return 0;
}