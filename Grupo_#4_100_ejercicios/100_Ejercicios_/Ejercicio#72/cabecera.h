#ifndef CABECERA_H
#define CABECERA_H

const int MAX = 20;

struct Cola {
    int elementos[MAX];
    int frente;
    int final;
    int cantidad;
};

// Declaraciones de funciones
void iniciarCola(Cola &c);
bool estaLlena(Cola &c);
bool estaVacia(Cola &c);
bool encolar(Cola &c, int valor);
bool desencolar(Cola &c, int &valor);

#endif
