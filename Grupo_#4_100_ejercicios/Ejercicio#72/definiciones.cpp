#include "cabecera.h"

void iniciarCola(Cola &c) {
    c.frente = 0;
    c.final = -1;
    c.cantidad = 0;
}

bool estaLlena(Cola &c) {
    return c.cantidad == MAX;
}

bool estaVacia(Cola &c) {
    return c.cantidad == 0;
}

bool encolar(Cola &c, int valor) {
    if (estaLlena(c)) {
        return false;
    }
    c.final = (c.final + 1) % MAX;
    c.elementos[c.final] = valor;
    c.cantidad++;
    return true;
}

bool desencolar(Cola &c, int &valor) {
    if (estaVacia(c)) {
        return false;
    }
    valor = c.elementos[c.frente];
    c.frente = (c.frente + 1) % MAX;
    c.cantidad--;
    return true;
}
