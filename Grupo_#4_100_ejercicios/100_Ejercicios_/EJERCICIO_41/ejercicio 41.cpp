//Nombre: Cristina Cruz
//Fecha: 5 jul 2025
//Descripción: Este codigo contara las consonantes en el texto ingresado por el usuario.

#include <iostream> 
using namespace std;
const int MAX_CADENA = 100;

void saludo() {
    cout << "Hola! Bienvenido al programa para contar consonantes." << endl;
    cout << "Contare las consonantes en el texto que escribas (solo letras, sin simbolos)." << endl;
}
bool funcionseguir() {
    char opcion;
    cout << "\nDeseas contar consonantes en otra cadena? (s/n): ";
    cin >> opcion;
   
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}
char aMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); 
    }
    return c; 
}
bool esLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool esVocal(char c) {
    char minuscula_c = aMinuscula(c);
    return (minuscula_c == 'a' || minuscula_c == 'e' || minuscula_c == 'i' ||
            minuscula_c == 'o' || minuscula_c == 'u');
}
int contarConsonantes(char cadena[]) {
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; ++i) {
        if (esLetra(cadena[i]) && !esVocal(cadena[i])) {
            contador++;
        }
    }
    return contador;
}

void mostrarResultadoConsonantes(char cadena[], int cantidadConsonantes) {
    cout << "La cadena ingresada es: \"" << cadena << "\"" << endl;
    cout << "El numero de consonantes es: " << cantidadConsonantes << endl;
}

int main() {
    saludo();

    do {
        char miCadena[MAX_CADENA];
        int numConsonantes;

        cout << "Ingresa una cadena de texto: ";
        cin.getline(miCadena, MAX_CADENA); 

        numConsonantes = contarConsonantes(miCadena);

        mostrarResultadoConsonantes(miCadena, numConsonantes);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}
