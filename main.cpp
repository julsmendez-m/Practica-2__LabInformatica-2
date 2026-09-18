#include <iostream>
#include "funciones.h"

using namespace std;

// ----- PROBLEMA 1: CALCULAR CAMBIO -----
void problema1() {
    cout << "=== PROBLEMA 1: CALCULAR CAMBIO ===" << endl;

    const int DENOMINACIONES[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int resultado[10] = {0};
    int tamano = 10;
    int dinero = 0;

    cout << "Ingrese la cantidad de dinero: ";
    cin >> dinero;

    calcularCambio(DENOMINACIONES, tamano, &dinero, resultado);
    imprimirResultado(DENOMINACIONES, resultado, tamano, &dinero);
}

// ----- PROBLEMA 3: COMPARAR CADENAS -----
void problema3() {
    cout << "\n=== PROBLEMA 3: COMPARAR CADENAS ===" << endl;

    char cadena1[100];
    char cadena2[100];

    cin.ignore(); // limpiamos el salto de linea que quedo pendiente

    cout << "Ingrese la primera cadena: ";
    cin.getline(cadena1, 100);

    cout << "Ingrese la segunda cadena: ";
    cin.getline(cadena2, 100);

    bool sonIguales = compararCadenas(cadena1, cadena2);

    if (sonIguales) {
        cout << "Resultado: Las cadenas son IGUALES (true)." << endl;
    } else {
        cout << "Resultado: Las cadenas son DIFERENTES (false)." << endl;
    }
}

// ----- PROBLEMA 5: CONVERTIR INT A CADENA -----
void problema5() {
    cout << "\n=== PROBLEMA 5: CONVERTIR INT A CADENA ===" << endl;

    int numero = 123;
    char bufferNumero[50];

    intACadena(numero, bufferNumero);

    cout << "Numero entero original: " << numero << endl;
    cout << "Cadena de caracteres generada: \"" << bufferNumero << "\"" << endl;
}

// ----- PROBLEMA 7: ELIMINAR REPETIDOS -----
void problema7() {
    cout << "\n=== PROBLEMA 7: ELIMINAR REPETIDOS ===" << endl;

    char textoOriginal[] = "bananas";
    char textoSinRepetidos[50];

    eliminarRepetidos(textoOriginal, textoSinRepetidos);

    cout << "Original: " << textoOriginal << ". Sin repetidos: " << textoSinRepetidos << "." << endl;
}

// ----- PROBLEMA 9: SUMA POR BLOQUES DE CIFRAS -----
void problema9() {
    cout << "\n=== PROBLEMA 9: SUMA POR BLOQUES DE CIFRAS ===" << endl;

    char cadenaNumerica[100];
    int n = 0;

    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Ingrese la cadena numerica: ";
    cin >> cadenaNumerica;

    int suma = sumarBloques(cadenaNumerica, n);

    cout << "Original: " << cadenaNumerica << "." << endl;
    cout << "Suma: " << suma << "." << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1) Problema 1: Calcular cambio" << endl;
        cout << "2) Problema 3: Comparar cadenas" << endl;
        cout << "3) Problema 5: Convertir int a cadena" << endl;
        cout << "4) Problema 7: Eliminar repetidos" << endl;
        cout << "5) Problema 9: Suma por bloques de cifras" << endl;
        cout << "6) Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                problema1();
                break;
            case 2:
                problema3();
                break;
            case 3:
                problema5();
                break;
            case 4:
                problema7();
                break;
            case 5:
                problema9();
                break;
            case 6:
                cout << "Chao!" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
