#include <iostream>
#include <cctype>
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

// ----- PROBLEMA 11: RESERVAS SALA DE CINE -----
void problema11() {
    cout << "\n=== PROBLEMA 11: RESERVAS SALA DE CINE ===" << endl;

    const int FILAS = 15;
    const int COLUMNAS = 20;
    char sala[FILAS * COLUMNAS];

    inicializarSala(sala, FILAS, COLUMNAS);

    int opcion;
    do {
        cout << "\n-- Sala de cine --" << endl;
        cout << "1) Mostrar sala" << endl;
        cout << "2) Reservar asiento" << endl;
        cout << "3) Cancelar asiento" << endl;
        cout << "4) Volver al menu principal" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarSala(sala, FILAS, COLUMNAS);
        } else if (opcion == 2 || opcion == 3) {
            char letraFila;
            int numAsiento;

            cout << "Ingrese la fila (A-O): ";
            cin >> letraFila;
            cout << "Ingrese el asiento (1-20): ";
            cin >> numAsiento;

            int fila = toupper(letraFila) - 'A';
            int asiento = numAsiento - 1;

            if (fila < 0 || fila >= FILAS || asiento < 0 || asiento >= COLUMNAS) {
                cout << "Fila o asiento invalido." << endl;
            } else if (opcion == 2) {
                if (reservarAsiento(sala, COLUMNAS, fila, asiento)) {
                    cout << "Asiento reservado." << endl;
                } else {
                    cout << "Ese asiento ya estaba reservado." << endl;
                }
            } else {
                if (cancelarAsiento(sala, COLUMNAS, fila, asiento)) {
                    cout << "Reserva cancelada." << endl;
                } else {
                    cout << "Ese asiento ya estaba disponible." << endl;
                }
            }
        } else if (opcion != 4) {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);
}

// ----- PROBLEMA 13: CONTAR ESTRELLAS -----
void problema13() {
    cout << "\n=== PROBLEMA 13: CONTAR ESTRELLAS ===" << endl;

    const int FILAS = 6;
    const int COLUMNAS = 8;
    int imagen[FILAS * COLUMNAS] = {
        0, 3, 4, 0, 0, 0, 6, 8,
        5, 13, 6, 0, 0, 0, 2, 3,
        2, 6, 2, 7, 3, 0, 10, 0,
        0, 0, 4, 15, 4, 1, 6, 0,
        0, 0, 7, 12, 6, 9, 10, 4,
        5, 0, 6, 10, 6, 4, 8, 0
    };

    int estrellas = contarEstrellas(imagen, FILAS, COLUMNAS);

    cout << "Numero de estrellas encontradas: " << estrellas << endl;
}

// ----- PROBLEMA 15: INTERSECCION DE RECTANGULOS -----
void problema15() {
    cout << "\n=== PROBLEMA 15: INTERSECCION DE RECTANGULOS ===" << endl;

    int A[4], B[4], C[4];

    cout << "Rectangulo A (x y ancho alto): ";
    cin >> A[0] >> A[1] >> A[2] >> A[3];

    cout << "Rectangulo B (x y ancho alto): ";
    cin >> B[0] >> B[1] >> B[2] >> B[3];

    interseccionRectangulos(A, B, C);

    if (C[2] > 0 && C[3] > 0) {
        cout << "Interseccion C: {" << C[0] << ", " << C[1] << ", "
             << C[2] << ", " << C[3] << "}" << endl;
    } else {
        cout << "Los rectangulos no se intersectan." << endl;
    }
}

// ----- PROBLEMA 17: NUMEROS AMIGABLES -----
void problema17() {
    cout << "\n=== PROBLEMA 17: NUMEROS AMIGABLES ===" << endl;

    int limite;
    cout << "Ingrese un numero: ";
    cin >> limite;

    int resultado;
    sumaNumerosAmigables(limite, &resultado);

    cout << "El resultado de la suma es: " << resultado << "." << endl;
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
        cout << "6) Problema 11: Reservas sala de cine" << endl;
        cout << "7) Problema 13: Contar estrellas" << endl;
        cout << "8) Problema 15: Interseccion de rectangulos" << endl;
        cout << "9) Problema 17: Numeros amigables" << endl;
        cout << "10) Salir" << endl;
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
                problema11();
                break;
            case 7:
                problema13();
                break;
            case 8:
                problema15();
                break;
            case 9:
                problema17();
                break;
            case 10:
                cout << "Chao!" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 10);

    return 0;
}
