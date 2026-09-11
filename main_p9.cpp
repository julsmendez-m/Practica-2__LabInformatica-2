#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    char cadenaNumerica[100];
    int n = 0;

    cout << "=== PROBLEMA 9: SUMA POR BLOQUES DE CIFRAS ===" << endl;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Ingrese la cadena numerica: ";
    cin >> cadenaNumerica;

    int suma = sumarBloques(cadenaNumerica, n);

    // Salida según el formato exigido
    cout << "\nOriginal: " << cadenaNumerica << "." << endl;
    cout << "Suma: " << suma << "." << endl;

    return 0;
}