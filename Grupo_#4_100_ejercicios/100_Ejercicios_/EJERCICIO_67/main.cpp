#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    string expresionInfija;

    cout << "Ingrese la expresion infija (sin espacios, por ejemplo A+B*C): ";
    cin >> expresionInfija;

    string expresionPostfija = convertirInfijoAPostfijo(expresionInfija);

    cout << "Expresion postfija: " << expresionPostfija << endl;

    return 0;
}
