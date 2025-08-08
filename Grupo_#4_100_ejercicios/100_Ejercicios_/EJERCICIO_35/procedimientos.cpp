#include "funciones.h" // Incluimos nuestro archivo de encabezado

void saludo() {
    cout << "Hola! Bienvenido al programa de Ordenamiento por Insercion." << endl;
    cout << "Este programa ordenara los numeros que ingreses de menor a mayor." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nDeseas ordenar otro arreglo? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Eso no es un numero! Ingresa un numero entero valido: ";
        cin >> num;
    }
}

void funcionvalidarTamano(int& tam) {
    while (cin.fail() || tam <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Tamano invalido! Debe ser un numero entero positivo: ";
        cin >> tam;
    }
}

void leerArreglo(int* arr, int tamano) {
    cout << "Ingresa " << tamano << " numeros enteros:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
        funcionvalidar(arr[i]);
    }
}

void mostrarArreglo(int* arr, int tamano) {
    cout << "Arreglo: [";
    for (int i = 0; i < tamano; ++i) {
        cout << arr[i];
        if (i < tamano - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void ordenarPorInsercion(int* arr, int tamano) {
    for (int i = 1; i < tamano; ++i) {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = clave;
    }
}