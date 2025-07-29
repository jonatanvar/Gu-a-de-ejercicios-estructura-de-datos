#include "cabecera.h"
#include <iostream> // Solo se incluye iostream
using namespace std;

void mostrarDatos(estudiante e) {
 cout << "Nombre: " << e.nombre << endl;
 cout << "Carnet: " << e.carnet << endl;
 cout << "Carrera: " << e.carrera << endl;
 cout << "Promedio: " << e.promedio << endl;
 cout << "---------------------------------------\n";
}

void agregarEstudiante(estudiante &e) {
 cout << "Ingrese el nombre del estudiante: ";
 cin.getline(e.nombre, sizeof(e.nombre)); // Lee linea completa

 cout << "Ingrese el carnet del estudiante: ";
 cin.getline(e.carnet, sizeof(e.carnet)); // Lee linea completa

 cout << "Ingrese la carrera del estudiante: ";
 cin.getline(e.carrera, sizeof(e.carrera)); // Lee linea completa

 cout << "Ingrese el promedio del estudiante: ";
 cin >> e.promedio;
 // No se limpia el buffer aqui, se espera que el siguiente cin.ignore() lo haga si es necesario
 cout << "---------------------------------------\n";
}

void mostrarMenu() {
 cout << "\n Menu Principal:";
 cout << "\n 1. Agregar estudiante";
 cout << "\n 2. Mostrar estudiantes";
 cout << "\n 3. Salir";
 cout << "\n Ingrese una opcion: ";
}

char obtenerOpcion() {
 char opcion;
 cin >> opcion;
 // Limpiar el buffer despues de leer el char para que getline() funcione correctamente despues
 cin.ignore(256, '\n');
 return opcion;
}