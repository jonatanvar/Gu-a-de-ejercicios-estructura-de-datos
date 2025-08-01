// Nombre: Jorge Mendoza
// Autoría Agente: Annie
// Fecha: 22/07/2025.
// PROMPT:
// Este código fue creado mediante un agente llamado Annie al cual se le dan una serie de instrucciones que puede y no puede hacer dentro de nuestro código solo se pega el enunciado y el agente nos genera nuestro código.
// Necesito un programa en C++ versión 20. Es para una clase de estructuras de datos. Este es el ejercicio: ejercicio 93: "Máximo y mínimo de datos: Encontrar los valores extremos de un conjunto numérico." Aquí te digo lo que el programa tiene que hacer:
// 1. Haz una función que encuentre el número más grande. Esta función debe recibir un grupo de números (un arreglo) y cuántos números hay en ese grupo. Al final, debe darme el número más grande que encontró.
// 2. Haz otra función para encontrar el número más pequeño. Igual que la anterior, recibe el grupo de números y su tamaño. Esta me debe dar el número más pequeño.
// 3. Si el grupo de números está vacío (o tiene 0 o menos números), ambas funciones deben avisar con un mensaje de error y, por ahora, pueden devolver un 0.
// 4. En la parte principal del programa (donde todo empieza):
// a. Pregunta al usuario cuántos números quiere poner en su grupo.
// b. Pide al usuario que escriba cada número para llenar el grupo.
// c. Usa las funciones que hiciste para encontrar el número más grande y el más pequeño, y muestra los resultados.
// 5. Usa `using namespace std; `.
// 6. Pon comentarios solo en las partes del código que sean un poco complicadas o que tengan una lógica muy particular. Las cosas obvias o que ya sabemos no necesitan comentario.
// 7. Solo puedes usar la librería `iostream`. Nada más.

#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int tamano;    // Variable para almacenar el tamaño del arreglo que el usuario ingresará.
    int repetir;   // Variable para controlar si el programa principal se repite.

    cout << "Bienvenido al programa para encontrar el valor maximo y minimo en un arreglo. :)\n";

    // Bucle principal para permitir al usuario repetir todo el proceso.
    do {
        // Bucle para solicitar y validar el tamaño del arreglo, asegurando que sea un número positivo.
        do {
            tamano = static_cast<int>(validarEntradaNumerica("Ingrese el tamano del arreglo (debe ser un numero positivo): "));
            if (tamano <= 0) {
                cout << "El tamano del arreglo debe ser un numero positivo.\n";
            }
        } while (tamano <= 0);

        // Crea un arreglo dinámico para almacenar los datos, basado en el tamaño ingresado por el usuario.
        int* datos = new int[tamano];

        cout << "Ingrese los " << tamano << " elementos del arreglo:\n";
        // Bucle para solicitar a cada elemento del arreglo.
        for (int i = 0; i < tamano; ++i) {
            cout << "Elemento " << (i + 1) << ": ";
            datos[i] = static_cast<int>(validarEntradaNumerica("")); // El mensaje ya fue impreso.
        }

        // Llama a las funciones para encontrar el máximo y el mínimo en el arreglo.
        int maximo = encontrarMaximo(datos, tamano);
        int minimo = encontrarMinimo(datos, tamano);

        // Muestra los elementos que fueron ingresados.
        cout << "\nLos elementos ingresados son: ";
        for (int i = 0; i < tamano; ++i) {
            cout << datos[i] << (i == tamano - 1 ? "" : ", "); // Formatea la salida con comas.
        }
        cout << endl;

        // Muestra los resultados de los valores máximo y mínimo.
        cout << "El valor maximo en el arreglo es: " << maximo << endl;
        cout << "El valor minimo en el arreglo es: " << minimo << endl;

        // Libera la memoria asignada dinámicamente al arreglo para evitar fugas de memoria.
        delete[] datos;
        datos = nullptr; // Se asigna nullptr para evitar "punteros colgantes".

        // Pregunta al usuario si desea repetir el programa.
        repetir = preguntarRepetir();

    } while (repetir == 1);

    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}