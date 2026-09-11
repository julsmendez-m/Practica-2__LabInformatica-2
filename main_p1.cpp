#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    // Arreglo constante con las denominaciones del problema
    const int DENOMINACIONES[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int resultado[10] = {0}; // Arreglo inicializado en 0 para almacenar el conteo
    int tamano = 10;
    int dinero = 0;

    cout << "Ingrese la cantidad de dinero: ";
    cin >> dinero;

    // Pasamos dinero con '&' para enviar su dirección de memoria (puntero)
    // se  modifica la variable original dejando el faltante
    calcularCambio(DENOMINACIONES, tamano, &dinero, resultado);

    // Imprimimos los datos procesados
    imprimirResultado(DENOMINACIONES, resultado, tamano, &dinero);

    return 0;

}
