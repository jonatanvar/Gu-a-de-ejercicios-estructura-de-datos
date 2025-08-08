#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    saludo();

    do {
        int capacidadDeseada;
        Cola miCola;

        cout << "Ingresa la capacidad de la cola: ";
        cin >> capacidadDeseada;
        funcionvalidar(capacidadDeseada);
        cin.ignore(100, '\n');

        inicializarCola(miCola, capacidadDeseada);

        if (estaColaVacia(miCola)) {
            cout << "\nAl inicio, la cola esta VACIA." << endl;
        } else {
            cout << "\nAl inicio, la cola NO esta vacia (error logico)." << endl;
        }
        
        cout << "\nIngresa elementos para encolar (0 para parar de encolar):" << endl;
        int valorIngresado;
        do {
            cout << "  Elemento a encolar (0 para terminar): ";
            cin >> valorIngresado;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "  Entrada invalida. Intenta de nuevo." << endl;
                valorIngresado = -1;
            } else if (valorIngresado != 0) {
                encolar(miCola, valorIngresado);
            }
            if (miCola.cantidad == miCola.capacidad && valorIngresado != 0) {
                cout << "  La cola alcanzo su capacidad maxima." << endl;
                break;
            }
        } while (valorIngresado != 0);
        cin.ignore(100, '\n');


        if (estaColaVacia(miCola)) {
            cout << "\nLa cola esta VACIA." << endl;
        } else {
            cout << "\nLa cola NO esta vacia. Contiene " << miCola.cantidad << " elementos." << endl;
        }

        cout << "\nIntentando desencolar elementos para vaciarla:" << endl;
        char respDesencolar;
        do {
            cout << "  Desencolar un elemento? (s/n): ";
            cin >> respDesencolar;
            cin.ignore(100, '\n');
            if (respDesencolar == 's' || respDesencolar == 'S') {
                desencolar(miCola);
            }
            if (estaColaVacia(miCola)) {
                cout << "  La cola ahora esta VACIA." << endl;
                break;
            }
        } while (respDesencolar == 's' || respDesencolar == 'S');
        
        liberarCola(miCola);

    } while (funcionseguir());

    cout << "Adios." << endl;

    return 0;
}