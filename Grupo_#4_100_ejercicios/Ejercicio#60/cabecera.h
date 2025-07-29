#ifndef CABECERA_H
#define CABECERA_H

struct Fraccion {
    int numerador;
    int denominador;
};

int abs_manual(int n); 
int calcularMCD(int a, int b);
void simplificarFraccion(Fraccion &f);
void mostrarFraccion(const Fraccion &f);

#endif // CABECERA_H