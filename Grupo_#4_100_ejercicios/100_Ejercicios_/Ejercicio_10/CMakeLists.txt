cmake_minimum_required(VERSION 3.31)
project(Ejercicio_10 CXX) # Siempre es buena práctica especificar el lenguaje (CXX para C++)

set(CMAKE_CXX_STANDARD 20) # Establece el estándar de C++ a usar (C++20 en este caso)

# ¡Aquí es donde listamos TODOS tus archivos .cpp que deben ser compilados!
add_executable(Ejercicio_10
        main.cpp
        operaciones.cpp
        funciones.h
)

