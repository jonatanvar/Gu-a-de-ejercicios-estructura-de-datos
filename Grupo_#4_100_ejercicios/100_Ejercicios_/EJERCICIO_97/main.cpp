// Nombre: Belinda Andino
// Autoria: Sofi.
// Fecha: 7/17/2025.
#include <iostream>
#include "funciones.h"

using namespace std;


constexpr int MAX_LONGITUD_CORREO = 256;

int main() {
    int repetirPrograma;
    char correo[MAX_LONGITUD_CORREO];

    cout << "Bienvenido al programa para validar el formato basico de un correo electronico. :)\n";

    // Bucle principal para permitir al usuario validar múltiples correos.
    do {
        cout << "\n--- Ingrese el correo electronico a validar ---\n";
        cout << "Correo: ";
        cin.getline(correo, MAX_LONGITUD_CORREO);

        // Llama a la función 'validarCorreoElectronico' para comprobar el formato.
        if (validarCorreoElectronico(correo)) {
            cout << "\nEl correo '" << correo << "' tiene un formato basico VALIDO.\n";
        } else {
            cout << "\nEl correo '" << correo << "' tiene un formato basico INVALIDO.\n";
            cout << "Recuerde: debe contener un '@', un '.' despues del '@', y no espacios." << endl;
            cout << "Ni '@' ni el ultimo '.' pueden estar al inicio o final de sus respectivas secciones." << endl;
        }

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);

    cout << "\nGracias por usar el programa. :)\n";

    return 0;
}