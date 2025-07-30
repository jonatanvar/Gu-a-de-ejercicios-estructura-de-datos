// Autor: Jorge Mendoza.
// Fecha: 21/07/2025

#include "funciones.h"
#include <iostream>


using namespace std;
int main() {
    int repetirPrograma;

    do {
        double radioCirculo;

        while (true) {
            cout << "Ingrese el radio del circulo: ";
            cin >> radioCirculo;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            else if (radioCirculo < 0) {
                cout << "Error: El radio no puede ser un numero negativo. Por favor, ingresa un valor positivo.\n";
            }
            else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        double perimetroCalculado = calcularPerimetroCirculo(radioCirculo);
        cout << "El perimetro del circulo con radio " << radioCirculo << " es: " << perimetroCalculado << "\n";
        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);

    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}

