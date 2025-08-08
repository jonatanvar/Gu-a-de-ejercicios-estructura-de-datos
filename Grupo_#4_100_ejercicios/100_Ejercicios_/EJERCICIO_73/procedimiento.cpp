#include "funciones.h"
#include <iostream>

using namespace std;

void agregarPersona(queue<string>& fila) {
    string nombre;
    cout << "Ingrese el nombre de la persona: ";
    cin.ignore();
    getline(cin, nombre);
    fila.push(nombre);
    cout << nombre << " fue agregado a la fila." << endl;
}

void atenderPersona(queue<string>& fila) {
    if (fila.empty()) {
        cout << "No hay personas en la fila para atender." << endl;
    } else {
        cout << "Atendiendo a: " << fila.front() << endl;
        fila.pop();
    }
}

void mostrarFila(queue<string> fila) {
    if (fila.empty()) {
        cout << "La fila esta vacia." << endl;
        return;
    }

    cout << "Personas en la fila:" << endl;
    while (!fila.empty()) {
        cout << "- " << fila.front() << endl;
        fila.pop();
    }
}
