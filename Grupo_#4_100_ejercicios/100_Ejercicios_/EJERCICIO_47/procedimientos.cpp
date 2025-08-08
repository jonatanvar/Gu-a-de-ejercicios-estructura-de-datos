#include "funciones.h"

void saludo() {
    cout << "Hola! Bienvenido al programa de gestion de estudiantes." << endl;
    cout << "Podras ingresar datos de varios estudiantes y luego verlos." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nDeseas gestionar mas estudiantes? (s/n): ";
    cin >> opcion;
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Ingresa un numero entero valido: ";
        cin >> num;
    }
}

void funcionvalidarFloat(float& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Ingresa un numero con decimales valido: ";
        cin >> num;
    }
}

void funcionvalidarCantidadEstudiantes(int& cantidad) {
    while (cin.fail() || cantidad <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Cantidad invalida. Ingresa un numero entero positivo: ";
        cin >> cantidad;
    }
}

void leerEstudiante(Estudiante& est) {
    cout << "  Nombre: ";
    cin.getline(est.nombre, MAX_NOMBRE);

    cout << "  Edad: ";
    cin >> est.edad;
    funcionvalidar(est.edad);

    cout << "  Nota: ";
    cin >> est.nota;
    funcionvalidarFloat(est.nota);
    cin.ignore(100, '\n');
}

void leerArregloEstudiantes(Estudiante* arr, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        cout << "\nIngresa datos para el Estudiante " << i + 1 << ":" << endl;
        leerEstudiante(arr[i]);
    }
}

void mostrarEstudiante(const Estudiante& est) {
    cout << "  Nombre: " << est.nombre << endl;
    cout << "  Edad: " << est.edad << endl;
    cout << "  Nota: " << est.nota << endl;
}

void mostrarArregloEstudiantes(const Estudiante* arr, int cantidad) {
    cout << "\n--- Datos de los Estudiantes ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        mostrarEstudiante(arr[i]);
    }
}