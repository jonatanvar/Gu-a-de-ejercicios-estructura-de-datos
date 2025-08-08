#include <iostream>
#include <string>
#include "funciones.h"

using namespace std;

int main() {
    string entrada;
    cout << "Ingrese una cadena con espacios: ";
    getline(cin, entrada);

    string resultado = eliminarEspacios(entrada);
    cout << "Cadena sin espacios: " << resultado << endl;

    return 0;
}
