# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.16)

# Nombre de tu proyecto
project(ArbolBinarioEstadistico)

# Especifica el estándar C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega un ejecutable.
# El primer argumento es el nombre del ejecutable que se creará (e.g., "arbol_stats").
# Los siguientes argumentos son los archivos fuente (.cpp) que se deben compilar.
# No es necesario listar los archivos .h aquí, ya que son incluidos por los .cpp.
add_executable(arbol_stats main.cpp definiciones.h)

# Aunque definicion.h no es un .cpp, en algunos entornos CMake puede requerir
# que se liste si contiene implementaciones y no es incluido por un solo .cpp.
# En este caso, al estar incluido por main.cpp, podría funcionar sin listarlo
# explícitamente, pero es una buena práctica si contiene definiciones que
# necesitan ser procesadas por el compilador como parte de una unidad de compilación.
# Aquí lo listamos porque contiene las implementaciones completas.