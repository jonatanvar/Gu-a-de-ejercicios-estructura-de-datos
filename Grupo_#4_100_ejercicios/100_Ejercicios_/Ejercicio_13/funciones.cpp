//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para determinar el menor de tres números.

#include <iostream> // Incluye la librería estándar para operaciones de entrada/salida.
#include <limits>

using namespace std; // Usa el espacio de nombres estándar para facilitar el acceso a cout, cin, etc.

// Implementación de la función para resolver el Ejercicio 13: Menor de tres números.
void resolverEjercicio13() {
    int num1, num2, num3; // Declaración de las variables para almacenar los tres números.

    // Bucle para solicitar y validar el primer número.
    while (true) {
        cout << "Ingresa el primer numero entero: "; // Pide al usuario el primer número.
        cin >> num1; // Lee el primer número.

        // Validación de la entrada: verifica si hubo un error en la lectura (ej. se ingresó texto en lugar de un número).
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de cin.
            // Ignora el resto de la línea del buffer de entrada, incluyendo el carácter de nueva línea.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Si la entrada es válida, limpia el resto de la línea y sale del bucle.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }

    // Bucle para solicitar y validar el segundo número.
    while (true) {
        cout << "Ingresa el segundo numero entero: "; // Pide al usuario el segundo número.
        cin >> num2; // Lee el segundo número.

        // Validación de la entrada.
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de cin.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea.
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }

    // Bucle para solicitar y validar el tercer número.
    while (true) {
        cout << "Ingresa el tercer numero entero: "; // Pide al usuario el tercer número.
        cin >> num3; // Lee el tercer número.

        // Validación de la entrada.
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de cin.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea.
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }

    // Lógica para determinar el menor de los tres números.
    int menor = num1; // Asume que el primer número es el menor inicialmente.

    if (num2 < menor) {
        menor = num2; // Si el segundo número es menor que el actual 'menor', actualiza 'menor'.
    }

    if (num3 < menor) {
        menor = num3; // Si el tercer número es menor que el actual 'menor', actualiza 'menor'.
    }

    // Imprime el resultado final: el menor de los tres números.
    cout << "El menor de los tres numeros es: " << menor << endl; 
}