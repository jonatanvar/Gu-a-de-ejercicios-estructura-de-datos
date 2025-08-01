// Nombre: Jorge Mendoza
// Autoría: Annie
// Fecha: 22/07/2025.
// PROMPT:
// Este código fue creado mediante un agente llamado Annie al cual se le dan una serie de instrucciones que puede y no puede hacer dentro de nuestro código solo se pega el enunciado y el agente nos genera nuestro código.
// Necesito que me hagas un código de C++ en la versión 20 del lenguaje. Es para una clase de estructuras de datos. Este es el ejercicio: Calcular media: Función que calcule el promedio de un conjunto de datos numéricos. Las instrucciones son las siguientes:
// 1. Haz una función para calcular el promedio. Esta función debe recibir un grupo de números (un arreglo) y cuántos números hay en ese grupo. El resultado debe ser el promedio, que puede tener decimales.
// 2. Para guardar los números, usa un arreglo estático (de los de C++ de toda la vida).
// 3. Si el grupo de números está vacío (o su tamaño es cero), la función de promedio debe manejarlo, quizás mostrando un mensaje de error y retornando un valor especial (como 0.0).
// 4. En la parte principal del programa (`main`):
// a. Pregunta al usuario cuántos números quiere promediar.
// b. Pide al usuario que escriba cada número para llenar el arreglo.
// c. Llama a la función de promedio y muestra el resultado de forma clara.
// d. Después de mostrar el promedio, pregunta si el usuario quiere calcular otro promedio y deja que decida si sigue o sale.
// 5. Usa la función que ya tenemos para validar que lo que el usuario escribe sean números válidos.
// 6. Acuérdate de usar `using namespace std;`.
// 7. Pon comentarios solo en las líneas que sean un poco más difíciles de entender o que tengan una lógica específica. Las cosas obvias o que ya sabemos no necesitan comentario.
// 9. Solo puedes usar la librería `iostream`. Nada más, ninguna otra.


#include <iostream>
#include "funciones.h"

using namespace std;
const int MAX_DATOS = 100;

int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa para calcular la media (promedio) de un conjunto de datos. :)\n";

    // Bucle principal para permitir la repetición del cálculo de la media.
    do {
        int cantidadDatos; // Almacena la cantidad de datos que el usuario desea ingresar.

        // Bucle para solicitar y validar la cantidad de datos.
        while (true) {
            cout << "Ingrese la cantidad de datos que desea promediar (1 a ";
            cout << MAX_DATOS;
            cout << "): ";
            cantidadDatos = validarEntradaNumericaInt("");
            if (cantidadDatos > 0 && cantidadDatos <= MAX_DATOS) {
                break; // Sale del bucle si la cantidad es válida y dentro del rango.
            } else {
                cout << "Error: La cantidad de datos debe ser entre 1 y " << MAX_DATOS << ".\n";
            }
        }

        // Declaramos el arreglo para almacenar los datos, de tamaño fijo máximo.
        double datos[MAX_DATOS];

        cout << "--- Ingrese los " << cantidadDatos << " datos ---\n";
        // Bucle para solicitar y validar cada uno de los datos.
        for (int i = 0; i < cantidadDatos; ++i) {
            cout << "Ingrese el dato #";
            cout << (i + 1); // Imprime el número del dato directamente
            cout << ": ";
            // Llamamos a la función validarEntradaNumericaDouble sin pasar un mensaje por parámetro.
            datos[i] = validarEntradaNumericaDouble("");
        }

        // Calcula la media llamando a la función correspondiente.
        double mediaCalculada = calcularMedia(datos, cantidadDatos);

        // Muestra el resultado.
        cout << "\nLa media (promedio) de los datos ingresados es: " << mediaCalculada << "\n";

        // Pregunta al usuario si desea repetir el programa.
        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1); // El programa se repite si el usuario elige '1' (Sí).
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}