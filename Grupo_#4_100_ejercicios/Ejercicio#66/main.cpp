//Nombre: Jonatan Varela
//Fecha: 15/07/2025
#include <iostream>
#include "cabecera.h" 
using namespace std; 

int main() {
    cout << "== Verificacion de expresiones balanceadas ==" << endl;
    cout << "Ingrese una expresion con () , [] y {} para verificar balance: " << endl;

    char expresion[MAX_SIZE];
    char continuar;

    do {
        cout << "\nExpresion a verificar: ";
        cin.ignore(256, '\n'); 
        cin.getline(expresion, MAX_SIZE);

        if (verificarBalanceo(expresion)) {
            cout << "✅ La expresion ESTA balanceada" << endl;
        } else {
            cout << "❌ La expresion NO esta balanceada" << endl;
        }

        cout << "¿Desea verificar otra expresion? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nPrograma finalizado. ¡Hasta luego!" << endl;
    return 0;
}