// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define el tamaño máximo de la cola.
constexpr int MAX_TAMANIO_COLA = 3;

// Estructura para la Cola Circular.
// 'elementos' almacenará los datos.
// 'frente' es el índice del primer elemento (para eliminar/dequeue).
// 'final' es el índice del último elemento (para agregar/enqueue).
// 'contador' lleva la cuenta de cuántos elementos hay actualmente en la cola.
struct Cola {
    int elementos[MAX_TAMANIO_COLA];
    int frente;
    int final;
    int contador;
};

// Declaración de la función para comprobar si la cola está vacía.
// Retorna 'true' si la cola está vacía, 'false' en caso contrario.
bool estaVacia(const Cola& cola);

// Declaración de la función para comprobar si la cola está llena.
// Retorna 'true' si la cola está llena, 'false' en caso contrario.
bool estaLlena(const Cola& cola);

// Declaración de la función para agregar un elemento al final de la cola (enqueue).
// Retorna 'true' si el elemento se agregó con éxito, 'false' si la cola está llena.
bool enqueue(Cola& cola, int valor);

// Declaración de la función para eliminar y retornar un elemento del frente de la cola (dequeue).
// Retorna el elemento eliminado. Si la cola está vacía, podría retornar un valor sentinel como -1 o
// imprimir un mensaje de error (en este caso, imprimirá un error y un valor por defecto).
int dequeue(Cola& cola);

// Declaración de la función para validar y leer una entrada numérica (int).
// Retorna un valor int válido.
int validarEntradaNumerica(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
// Retorna 1 para 'Sí', 2 para 'No'. Incluye validación de entrada.
int preguntarRepetir();

#endif // FUNCIONES_H