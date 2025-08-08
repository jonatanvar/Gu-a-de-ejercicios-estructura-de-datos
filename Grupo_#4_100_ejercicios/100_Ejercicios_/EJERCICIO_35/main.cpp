#include <iostream>
#include "funciones.h" // Incluimos nuestro archivo de encabezado

using namespace std;

int main() {
    saludo();

    do {
        int tamano;
        int* miArreglo = NULL; // Usamos NULL en lugar de nullptr

        cout << "Dime cuantos numeros quieres ordenar: ";
        cin >> tamano;
        funcionvalidarTamano(tamano);

        miArreglo = new int[tamano]; // Asignacion dinamica de memoria

        leerArreglo(miArreglo, tamano);

        cout << "Arreglo original: ";
        mostrarArreglo(miArreglo, tamano);

        ordenarPorInsercion(miArreglo, tamano);

        cout << "Arreglo ordenado: ";
        mostrarArreglo(miArreglo, tamano);

        delete[] miArreglo; // Liberar la memoria
        miArreglo = NULL; // Buena practica, asignar NULL despues de liberar

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}