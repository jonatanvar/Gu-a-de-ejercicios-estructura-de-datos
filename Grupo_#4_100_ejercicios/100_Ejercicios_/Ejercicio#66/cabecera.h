#include "cabecera.h"
#include <iostream> 
using namespace std; 

void Pila::push(char c) {
    if (tope < MAX_SIZE - 1) {
        elementos[++tope] = c;
    }
}

char Pila::pop() {
    if (tope >= 0) {
        return elementos[tope--];
    }
    return '\0'; 
}

char Pila::top() const {
    if (tope >= 0) {
        return elementos[tope];
    }
    return '\0';
}

bool Pila::empty() const {
    return tope == -1;
}

bool esPar(char abierto, char cerrado) {
    return (abierto == '(' && cerrado == ')') ||
           (abierto == '[' && cerrado == ']') ||
           (abierto == '{' && cerrado == '}');
}

bool verificarBalanceo(const char expresion[]) {
    Pila pila;

    for (int i = 0; expresion[i] != '\0'; ++i) {
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