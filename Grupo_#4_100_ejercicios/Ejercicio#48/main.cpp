//Nombre: Jonatan Varela
//Fecha: 2/07/2025
#include <iostream> 
#include "cabecera.h"
using namespace std;

int main () {
 estudiante estudiantes[MAX_ESTUDIANTES];
 int cantidad = 0;
 char opcion;
 char continuar_menu;

 cout << "Bienvenido al programa para gestionar datos de estudiantes\n";

 do {
  mostrarMenu(); // Muestra las opciones del menu
  opcion = obtenerOpcion(); // Obtiene la opcion y limpia el buffer

  switch (opcion) {
   case '1':
    if (cantidad < MAX_ESTUDIANTES) {
     agregarEstudiante(estudiantes[cantidad]);
     cantidad++;
     cout << "Estudiante agregado exitosamente.\n";
    } else {
     cout << "No se pueden agregar mas estudiantes. Lista llena.\n";
    }
   break;
   case '2':
    if (cantidad == 0) {
     cout << "No hay estudiantes registrados.\n";
    } else {
     cout << "Lista de estudiantes:\n";
     for (int i = 0; i < cantidad; i++) {
      mostrarDatos(estudiantes[i]);
     }
    }
   break;
   case '3':
    cout << "Saliendo del programa...\n";
   break;
   default:
    cout << "Opcion invalida. Intente nuevamente.\n";
   break;
  }
  // Preguntar si desea continuar el menu (solo si no se eligio salir)
  if (opcion != '3') {
   cout << "\n¿Deseas regresar al menu principal? (s/n): ";
   cin >> continuar_menu;
   cin.ignore(256, '\n'); // Limpiar el buffer despues de leer char 's'/'n'
  } else {
   continuar_menu = 'n'; // Si se elige salir, no continuar
  }

 } while (continuar_menu == 'S' || continuar_menu == 's');

 cout << "Gracias por usar el programa. Adios! \n ";
 return 0;
}