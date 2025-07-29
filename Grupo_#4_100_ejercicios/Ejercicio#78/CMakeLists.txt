cmake_minimum_required(VERSION 3.10)

project(ArbolBinario VERSION 1.0 CXX)

# Especifica la versión de C++ a usar
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega los ejecutables (tu main.cpp) y las fuentes necesarias
add_executable(ArbolBinario main.cpp definiciones.cpp)

# Si tienes librerías o directorios de inclusión adicionales, los agregarías aquí.
# Por ejemplo, para incluir cabecera.h, CMake buscará automáticamente en el mismo directorio.