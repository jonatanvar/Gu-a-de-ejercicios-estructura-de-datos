#include "funciones.h" // Incluimos nuestro archivo de encabezado

void saludo() {
    cout << "Hola! Bienvenido al programa de Suma de Matrices." << endl;
    cout << "Vamos a sumar dos matrices de igual tamano." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "Quieres sumar mas matrices? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Eso no es un numero! Ingresa un numero entero: ";
        cin >> num;
    }
}

void funcionvalidarDimension(int& dim) {
    while (cin.fail() || dim <= 0 || dim > MAX_DIM) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Dimension invalida! Debe ser un numero entre 1 y " << MAX_DIM << ": ";
        cin >> dim;
    }
}

void pedirDatosMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas, int numeroMatriz) {
    cout << "Ahora ingresa los numeros para la Matriz " << numeroMatriz << ":" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz " << numeroMatriz << " [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            funcionvalidar(matriz[i][j]);
        }
    }
}

void sumarYMostrarMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int filas, int columnas) {
    int matSuma[MAX_DIM][MAX_DIM];

    cout << "\nResultados:" << endl;

    // Mostrar Matriz 1
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    // Mostrar Matriz 2
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    // Sumar y mostrar la Matriz Suma
    cout << "Matriz Suma:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matSuma[i][j] = mat1[i][j] + mat2[i][j];
            cout << matSuma[i][j] << "\t";
        }
        cout << endl;
    }
}