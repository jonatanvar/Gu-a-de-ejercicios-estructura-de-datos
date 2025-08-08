#include "funciones.h"
#include <stack>
#include <cctype>

int prioridad(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    return 0;
}

std::string convertirInfijoAPostfijo(const std::string& expresion) {
    std::stack<char> pila;
    std::string postfijo;

    for (char token : expresion) {
        if (isalnum(token)) {
            postfijo += token;
        } else if (token == '(') {
            pila.push(token);
        } else if (token == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfijo += pila.top();
                pila.pop();
            }
            if (!pila.empty()) pila.pop();
        } else {
            while (!pila.empty() && prioridad(pila.top()) >= prioridad(token)) {
                postfijo += pila.top();
                pila.pop();
            }
            pila.push(token);
        }
    }

    while (!pila.empty()) {
        postfijo += pila.top();
        pila.pop();
    }

    return postfijo;
}
