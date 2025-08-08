#include "funciones.h"
#include <algorithm>

std::string toLowerCase(const std::string& texto) {
    std::string resultado = texto;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}

int buscarLibro(std::string libros[], int n, const std::string& tituloBuscado) {
    std::string tituloBuscadoLower = toLowerCase(tituloBuscado);
    for (int i = 0; i < n; ++i) {
        if (toLowerCase(libros[i]) == tituloBuscadoLower) {
            return i;
        }
    }
    return -1;
}
