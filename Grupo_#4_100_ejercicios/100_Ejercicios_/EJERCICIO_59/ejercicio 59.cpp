//Nombre: Cristina Cruz
//Fecha: 8 jul 2025
//Descripción:Este progrma contiene uns Función que calcula el producto de dos fracciones. 

#include <iostream>

using namespace std;

struct Fraccion {
    int numerador;
    int denominador;
};

void saludo() {
    cout << "Hola! Bienvenido al programa para multiplicar fracciones." << endl;
    cout << "Ingresaras dos fracciones y te mostrare su producto." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nDeseas multiplicar otras fracciones? (s/n): ";
    cin >> opcion;
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Ingresa un numero entero valido: ";
        cin >> num;
    }
}

void funcionvalidarDenominador(int& den) {
    while (cin.fail() || den == 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. El denominador no puede ser cero. Ingresa un numero entero valido: ";
        cin >> den;
    }
}

void leerFraccion(Fraccion& f, const char* nombre) {
    cout << "  Para " << nombre << ":" << endl;
    cout << "    Numerador: ";
    cin >> f.numerador;
    funcionvalidar(f.numerador);

    cout << "    Denominador: ";
    cin >> f.denominador;
    funcionvalidarDenominador(f.denominador);
    cin.ignore(100, '\n');
}

Fraccion multiplicarFracciones(const Fraccion& f1, const Fraccion& f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return resultado;
}

void mostrarFraccion(const Fraccion& f) {
    cout << f.numerador << "/" << f.denominador;
}

int main() {
    saludo();

    do {
        Fraccion fraccion1, fraccion2, resultado;

        cout << "\nIngresa la primera fraccion:" << endl;
        leerFraccion(fraccion1, "Fraccion 1");

        cout << "\nIngresa la segunda fraccion:" << endl;
        leerFraccion(fraccion2, "Fraccion 2");

        resultado = multiplicarFracciones(fraccion1, fraccion2);

        cout << "\nEl producto de ";
        mostrarFraccion(fraccion1);
        cout << " * ";
        mostrarFraccion(fraccion2);
        cout << " es: ";
        mostrarFraccion(resultado);
        cout << endl;

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}
