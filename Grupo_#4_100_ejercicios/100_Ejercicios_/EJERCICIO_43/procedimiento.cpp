#include "funciones.h"

std::string eliminarEspacios(const std::string& cadenaOriginal) {
    std::string cadenaSinEspacios;
    for (char c : cadenaOriginal) {
        if (c != ' ') {
            cadenaSinEspacios += c;
        }
    }
    return cadenaSinEspacios;
}
