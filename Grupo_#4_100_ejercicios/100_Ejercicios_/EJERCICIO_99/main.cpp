// Nombre: Jorge Mendoza.
// Autoría: Annie
// Fecha: 22/07/2025.
// PROMPT:
// Este código fue creado mediante un agente llamado Annie al cual se le dan una serie de instrucciones que puede y no puede hacer dentro de nuestro código solo se pega el enunciado y el agente nos genera nuestro código.
// Generar un programa en C++ 20 para el ejercicio #99: Validar fecha: Comprobar día, mes y año válidos, incluyendo años bisiestos.
// El programa debe:
// 1. Utilizar únicamente la librería `iostream`.
// 2. Implementar la funcionalidad en tres archivos: `main.cpp`, `funciones.h`, y `procedimientos.cpp`.
// 3. Incluir una función booleana validar los datos de las fechas, que reciba tres enteros: día, mes y año.
// 4. Dicha función debe implementar la lógica para:
// a. Validar el rango del año (por ejemplo, mayor a 0).
// b. Validar el rango del mes (1-12).
// c. Validar el rango del día para el mes dado, considerando los días de cada mes (31, 30, 28/29).
// d. Implementar la lógica para determinar si un año es bisiesto.
// 5. La función debe retornar `true` si la fecha es válida, `false` en caso contrario.

#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa para validar fechas. :)\n";

    // Bucle principal para permitir al usuario validar múltiples fechas.
    do {

        cout << "\n--- Ingrese la fecha a validar ---\n";

        // Solicita y valida el día.
        int dia = validarEntradaNumericaInt("Ingrese el dia: ");

        // Solicita y valida el mes.
        int mes = validarEntradaNumericaInt("Ingrese el mes: ");

        // Solicita y valida el año.
        int anio = validarEntradaNumericaInt("Ingrese el anio: ");

        // Llama a la función 'validarFecha' para comprobar la validez de la fecha ingresada.
        if (validarFecha(dia, mes, anio)) {
            cout << "\nLa fecha " << dia << "/" << mes << "/" << anio << " es VALIDA.\n";
        } else {
            cout << "\nLa fecha " << dia << "/" << mes << "/" << anio << " es INVALIDA.\n";
        }

        // Pregunta al usuario si desea repetir el programa.
        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}