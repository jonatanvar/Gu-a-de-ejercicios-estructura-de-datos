cmake_minimum_required(VERSION 3.16) # Versión de CMake, ajusta si tu CLion es más antiguo
project(ABB_Proyecto CXX)            # Nombre del proyecto y lenguaje C++

set(CMAKE_CXX_STANDARD 20)          # Establece el estándar C++ a 20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Asegura que el estándar sea requerido
set(CMAKE_CXX_EXTENSIONS OFF)       # Desactiva las extensiones del compilador

# Añade los archivos fuente al ejecutable
add_executable(ABB_Ejecutable
    main.cpp
    definiciones.cpp
)

# Enlaza el archivo de cabecera si es necesario (generalmente no se requiere para includes directos)
# target_include_directories(ABB_Ejecutable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})