#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    // --- PRUEBA PROBLEMA 5 ---
    cout << "=== PROBLEMA 5: CONVERTIR INT A CADENA ===" << endl;
    int numero = 123;
    char bufferNumero[50];

    // Pasamos el entero y la dirección del arreglo por referencia/puntero
    intACadena(numero, bufferNumero);

    cout << "Numero entero original: " << numero << endl;
    cout << "Cadena de caracteres generada: \"" << bufferNumero << "\"" << endl;

    cout << "\n----------------------------------------\n" << endl;

}