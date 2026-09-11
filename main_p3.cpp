#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    char cadena1[100];
    char cadena2[100];

    cout << "=== PROBLEMA 3: COMPARAR CADENAS ===" << endl;

    cout << "Ingrese la primera cadena: ";
    cin.getline(cadena1, 100);

    cout << "Ingrese la segunda cadena: ";
    cin.getline(cadena2, 100);

    // Al pasar el nombre del arreglo (cadena1, cadena2),
    // lo que se envía a la función es el puntero a su primer elemento
    bool sonIguales = compararCadenas(cadena1, cadena2);

    if (sonIguales) {
        cout << "\nResultado: Las cadenas son IGUALES (true)." << endl;
    } else {
        cout << "\nResultado: Las cadenas son DIFERENTES (false)." << endl;
    }

    return 0;
}