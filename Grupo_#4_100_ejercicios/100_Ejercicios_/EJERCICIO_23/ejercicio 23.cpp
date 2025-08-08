//Nombre: Cristina Cruz
//Fecha: 2 jul 2025
//Descripción : Este programa suma dos matrices de igual dimension elemento a elemento, después pregunta si quiere continuar o no (s/n).

#include <iostream>

using namespace std;

const int MAX_DIM = 3;

int main() {
    char continuar;
    
    cout << "Bienvenido al programa de suma de matrices." << endl;

    do {
        int matriz1[MAX_DIM][MAX_DIM];
        int matriz2[MAX_DIM][MAX_DIM];
        int suma[MAX_DIM][MAX_DIM];
        int filas, columnas;

        do {
            cout << "Ingrese el numero de filas (1-" << MAX_DIM << "): ";
            cin >> filas;
            cout << "Ingrese el numero de columnas (1-" << MAX_DIM << "): ";
            cin >> columnas;

            if (cin.fail() || filas <= 0 || filas > MAX_DIM || columnas <= 0 || columnas > MAX_DIM) {
                cout << "Dimensiones invalidas. Deben ser numeros enteros entre 1 y " << MAX_DIM << "." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                break;
            }
        } while (true);

        cout << "\n--- Ingrese los elementos de la primera matriz ---" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                while (!(cin >> matriz1[i][j])) {
                    cout << "Entrada invalida. Por favor, ingrese un numero entero: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        cout << "\n--- Ingrese los elementos de la segunda matriz ---" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                while (!(cin >> matriz2[i][j])) {
                    cout << "Entrada invalida. Por favor, ingrese un numero entero: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                suma[i][j] = matriz1[i][j] + matriz2[i][j];
            }
        }

        cout << "\n--- Resultado de la suma ---" << endl;
        cout << "Matriz 1:" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << matriz1[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\n+\n" << endl;

        cout << "Matriz 2:" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << matriz2[i][j] << "\t";
            }
            cout << endl;
        }
        
        cout << "\n=\n" << endl;

        cout << "Matriz Suma:" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << suma[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\n¿Desea realizar otra suma? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nGracias por usar el programa. ¡Hasta luego!" << endl;

    return 0;
}
