cmake_minimum_required(VERSION 3.10) # Versión mínima de CMake.

# Nombre de tu proyecto.
project(analisis_frecuencia_caracteres CXX)

# Establece el estándar de C++ a C++20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega los archivos fuente al ejecutable.
add_executable(analisis_frecuencia_caracteres
    main.cpp
    definiciones.cpp
)

# Incluye el directorio actual para que los archivos .cpp puedan encontrar cabecera.h.
target_include_directories(analisis_frecuencia_caracteres PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)