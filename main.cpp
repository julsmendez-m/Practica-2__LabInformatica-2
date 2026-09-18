#include <iostream>
#include <limits>
#include "funciones.h"

using namespace std;

// ----- PROBLEMA 1: CALCULAR CAMBIO -----
void problema1() {
    cout << "=== PROBLEMA 1: CALCULAR CAMBIO ===" << endl;

    // Arreglo constante con las denominaciones del problema
    const int DENOMINACIONES[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int resultado[10] = {0}; // Arreglo inicializado en 0 para almacenar el conteo
    int tamano = 10;
    int dinero = 0;

    cout << "Ingrese la cantidad de dinero: ";
    cin >> dinero;

    // Pasamos dinero con '&' para enviar su dirección de memoria (puntero)
    // se modifica la variable original dejando el faltante
    calcularCambio(DENOMINACIONES, tamano, &dinero, resultado);

    // Imprimimos los datos procesados
    imprimirResultado(DENOMINACIONES, resultado, tamano, &dinero);
}

// ----- PROBLEMA 3: COMPARAR CADENAS -----
void problema3() {
    cout << "=== PROBLEMA 3: COMPARAR CADENAS ===" << endl;

    char cadena1[100];
    char cadena2[100];

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
}

// ----- PROBLEMA 5: CONVERTIR INT A CADENA -----
void problema5() {
    cout << "=== PROBLEMA 5: CONVERTIR INT A CADENA ===" << endl;

    int numero = 123;
    char bufferNumero[50];

    // Pasamos el entero y la dirección del arreglo por referencia/puntero
    intACadena(numero, bufferNumero);

    cout << "Numero entero original: " << numero << endl;
    cout << "Cadena de caracteres generada: \"" << bufferNumero << "\"" << endl;
}

// ----- PROBLEMA 7: ELIMINAR REPETIDOS -----
void problema7() {
    cout << "=== PROBLEMA 7: ELIMINAR REPETIDOS ===" << endl;

    char textoOriginal[] = "bananas";
    char textoSinRepetidos[50];

    eliminarRepetidos(textoOriginal, textoSinRepetidos);

    cout << "Original: " << textoOriginal << ". Sin repetidos: " << textoSinRepetidos << "." << endl;
}

// ----- PROBLEMA 9: SUMA POR BLOQUES DE CIFRAS -----
void problema9() {
    cout << "=== PROBLEMA 9: SUMA POR BLOQUES DE CIFRAS ===" << endl;

    char cadenaNumerica[100];
    int n = 0;

    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Ingrese la cadena numerica: ";
    cin >> cadenaNumerica;

    int suma = sumarBloques(cadenaNumerica, n);

    cout << "\nOriginal: " << cadenaNumerica << "." << endl;
    cout << "Suma: " << suma << "." << endl;
}

int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Problema 1: Calcular cambio" << endl;
        cout << "2. Problema 3: Comparar cadenas" << endl;
        cout << "3. Problema 5: Convertir int a cadena" << endl;
        cout << "4. Problema 7: Eliminar repetidos" << endl;
        cout << "5. Problema 9: Suma por bloques de cifras" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Descartamos el resto de la línea (incluyendo '\n') para que
        // cin.getline() funcione correctamente en la siguiente iteración
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: problema1(); break;
            case 2: problema3(); break;
            case 3: problema5(); break;
            case 4: problema7(); break;
            case 5: problema9(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl; break;
        }
    }

    return 0;
}
