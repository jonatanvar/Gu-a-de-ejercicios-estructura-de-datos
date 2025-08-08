#include <iostream>
#include "funciones.h" // Incluimos nuestro archivo de encabezado

using namespace std;

int main() {
    saludo();

    do {
        int tamano;
        int sumaTotal;

        tamano = obtenerTamanoArreglo("Ingrese el tamano del arreglo: ");

        // Se usa asignacion dinamica para el arreglo ya que VLA (Variable Length Arrays)
        // no es parte del estandar de C++ (aunque algunos compiladores lo permiten como extension).
        int* miArreglo = new int[tamano];

        leerElementosArreglo(miArreglo, tamano);
        sumaTotal = sumarElementosArreglo(miArreglo, tamano);
        mostrarResultadoSuma(sumaTotal);

        // Liberar la memoria asignada dinamicamente
        delete[] miArreglo;

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}