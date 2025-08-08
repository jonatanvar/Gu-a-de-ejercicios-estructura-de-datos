//Nombre: Cristina Cruz
//Fecha: 10 jul 2025

#include <iostream>

using namespace std;

struct Cola {
    int* elementos;
    int capacidad;
    int cantidad;
};

void saludo() {
    cout << "Hola! Programa para verificar si una cola esta vacia." << endl;
    cout << "Ingresaras la capacidad y los elementos de la cola." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nQuieres probar de nuevo? (s/n): ";
    cin >> opcion;
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail() || num <= 0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalido. Ingrese un entero positivo: ";
        cin >> num;
    }
}

void inicializarCola(Cola& c, int cap) {
    c.capacidad = cap;
    c.elementos = new int[c.capacidad];
    c.cantidad = 0;
}

void liberarCola(Cola& c) {
    delete[] c.elementos;
    c.elementos = 0;
    c.capacidad = 0;
    c.cantidad = 0;
}

void encolar(Cola& c, int valor) {
    if (c.cantidad < c.capacidad) {
        c.elementos[c.cantidad] = valor;
        c.cantidad++;
        cout << "  Elemento " << valor << " encolado. (" << c.cantidad << "/" << c.capacidad << ")" << endl;
    } else {
        cout << "  Cola llena. No se pudo encolar " << valor << "." << endl;
    }
}

void desencolar(Cola& c) {
    if (c.cantidad > 0) {
        // En un ejemplo real, esto moveria los elementos o usaria punteros de frente/final
        // Para simplicidad, solo disminuimos la cantidad y asumimos que se "desencola" el primero
        for(int i = 0; i < c.cantidad - 1; ++i) {
            c.elementos[i] = c.elementos[i+1];
        }
        c.cantidad--;
        cout << "  Elemento desencolado. Quedan " << c.cantidad << " elementos." << endl;
    } else {
        cout << "  Cola vacia. No se pudo desencolar." << endl;
    }
}

bool estaColaVacia(const Cola& c) {
    return c.cantidad == 0;
}

int main() {
    saludo();

    do {
        int capacidadDeseada;
        Cola miCola;

        cout << "Ingresa la capacidad de la cola: ";
        cin >> capacidadDeseada;
        funcionvalidar(capacidadDeseada);
        cin.ignore(100, '\n');

        inicializarCola(miCola, capacidadDeseada);

        if (estaColaVacia(miCola)) {
            cout << "\nAl inicio, la cola esta VACIA." << endl;
        } else {
            cout << "\nAl inicio, la cola NO esta vacia (error logico)." << endl;
        }
        
        cout << "\nIngresa elementos para encolar (0 para parar de encolar):" << endl;
        int valorIngresado;
        do {
            cout << "  Elemento a encolar (0 para terminar): ";
            cin >> valorIngresado;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "  Entrada invalida. Intenta de nuevo." << endl;
                valorIngresado = -1; // Para que el bucle continue
            } else if (valorIngresado != 0) {
                encolar(miCola, valorIngresado);
            }
            if (miCola.cantidad == miCola.capacidad && valorIngresado != 0) {
                cout << "  La cola alcanzo su capacidad maxima." << endl;
                break;
            }
        } while (valorIngresado != 0);
        cin.ignore(100, '\n'); // Limpiar el buffer despues del ultimo cin >> valorIngresado


        if (estaColaVacia(miCola)) {
            cout << "\nLa cola esta VACIA." << endl;
        } else {
            cout << "\nLa cola NO esta vacia. Contiene " << miCola.cantidad << " elementos." << endl;
        }

        cout << "\nIntentando desencolar elementos para vaciarla:" << endl;
        char respDesencolar;
        do {
            cout << "  Desencolar un elemento? (s/n): ";
            cin >> respDesencolar;
            cin.ignore(100, '\n');
            if (respDesencolar == 's' || respDesencolar == 'S') {
                desencolar(miCola);
            }
            if (estaColaVacia(miCola)) {
                cout << "  La cola ahora esta VACIA." << endl;
                break;
            }
        } while (respDesencolar == 's' || respDesencolar == 'S');
        
        liberarCola(miCola);

    } while (funcionseguir());

    cout << "Adios." << endl;

    return 0;
}
