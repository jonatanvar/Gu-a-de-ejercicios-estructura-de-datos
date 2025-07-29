//Nombre: Jonatan Varela
//Fecha: 3/07/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main (){
 const int MAX = 100;
 Libro Biblioteca[MAX];
 int cantidad = 0;
 char opcion;
 cout << "=== GESTION DE BIBLIOTECA ===\n";
 char continuar; // Variable declarada en el original, pero no usada en la condicion del do-while

do {
  cout << "\nMenu Principal:";
  cout << "\n 1. Agregar libro";
  cout << "\n 2. Mostrar libros";
  cout << "\n 3. Salir";
  cout << "\n Ingrese una opcion: ";
  cin >> opcion;
  cin.ignore(256, '\n'); // <<--- AGREGADO A TU SOLICITUD ESPECIFICA

  switch (opcion) {
    case '1':
    if (cantidad < MAX) {
      agregarLibro(Biblioteca, cantidad);
      cantidad++;
      // Este mensaje se mantuvo aqui, como en tu codigo original
      cout << "Libro agregado exitosamente.\n";
    } else {
      cout << "No se pueden agregar mas libros. Lista llena (" << MAX << " libros).\n";
      }
      break;
    case '2':
    if (cantidad == 0) {
        cout << "\nNo hay libros registrados aun.\n";
    } else {
          cout << "\n=== LISTA DE LIBROS ===\n";
          for(int i = 0; i < cantidad; i++) {
          mostrarLibro(Biblioteca[i]);
     }
          }
    break;

      case '3':
      cout << "\nSaliendo del programa. ¡Hasta pronto!\n";
     break;

      default:
            cout << "\nOpcion no valida. Intentalo nuevamente.\n";
    }
 } while(opcion != '3'); // Condicion del bucle do-while de tu codigo original

     return 0;
 }