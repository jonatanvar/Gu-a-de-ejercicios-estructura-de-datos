#include "cabecera.h"
#include <iostream> // Necesario para cin/cout en algunos entornos, aunque ya en .h
using namespace std;

// Implementacion de los metodos de la Pila
Pila::Pila() {
    tope = -1;
}

void Pila::push(char c) {
    if (tope < MAX_SIZE - 1) {
        elementos[++tope] = c;
    }
}

char Pila::pop() {
    if (tope >= 0) {
        return elementos[tope--];
    }
    return '\0'; // Caracter nulo para indicar error o pila vacia
}

char Pila::top() {
    if (tope >= 0) {
        return elementos[tope];
    }
    return '\0'; // Caracter nulo para indicar error o pila vacia
}

bool Pila::empty() {
    return tope == -1;
}

// Funcion auxiliar para verificar si dos caracteres forman un par
bool esPar(char abierto, char cerrado) {
    return (abierto == '(' && cerrado == ')') ||
           (abierto == '[' && cerrado == ']') ||
           (abierto == '{' && cerrado == '}');
}

// Funcion principal para verificar el balanceo
bool verificarBalanceo(const char expresion[]) {
    Pila pila; // Se crea una instancia de la Pila
    pila.tope = -1; // Inicializar tope explicitamente si no hay constructor por defecto

    for (int i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pila.empty() || !esPar(pila.top(), c)) {
                return false;
            }
            pila.pop();
        }
    }
    return pila.empty();
}