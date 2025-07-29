#ifndef CABECERA_H
#define CABECERA_H

void obtenerDimensiones(int& filas, int& columnas);
void ingresarElementosMatriz(int matriz[10][10], int filas, int columnas);
void mostrarMatriz(int matriz[10][10], int filas, int columnas);
void ordenarFila(int matriz[10][10], int columnas, int fila_a_ordenar, char orden);
int obtenerFilaAOrdenar(int max_filas);
char obtenerTipoOrden();

#endif // CABECERA_H