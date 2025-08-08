//
// Created by Admin on 7/17/2025.
//
#ifndef FUNCIONES_H
#define FUNCIONES_H


constexpr int MAX_DATOS = 100;


double calcularMedia(const double datos[], int cantidad);

double calcularCovarianza(const double conjuntoX[], const double conjuntoY[], int tamano);


int validarEntradaNumericaInt(const char* mensaje);

double validarEntradaNumericaDouble(const char* mensaje);

int preguntarRepetir();

#endif // FUNCIONES_H