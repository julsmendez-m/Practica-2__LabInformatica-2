#include <iostream>
#include "funciones.h"
using namespace std;

// ------ PROBLEMA 1 --------

void calcularCambio(const int* denominaciones, int tamano, int* monto, int* resultado) {
    // operacion para recorrer el arreglo de denominaciones mediante punteros
    for (int i = 0; i < tamano; i++) {
        // Accedo al valor actual con el operador de desreferencia *(puntero + i)
        int valorActual = *(denominaciones + i);

        // Obtener la cantidad de billetes/monedas necesarias
        *(resultado + i) = *monto / valorActual;

        // se actualiza el valor contenido en la dirección de memoria de monto
        *monto = *monto % valorActual;
    }
}
void imprimirResultado(const int* denominaciones, const int* resultado, int tamano, const int* faltante) {
    for (int i = 0; i < tamano; i++) {
        // Imprimimos leyendo directamente las posiciones con punteros
        cout << *(denominaciones + i) << " : " << *(resultado + i) << endl;
    }
    // lo que quedó en la variable apuntada por faltante
    cout << "Faltante: " << *faltante << endl;
}

// ----- PROBLEMA 3 -------

int obtenerLongitud(const char* cad) {
    int longitud = 0;
    while (*(cad + longitud) != '\0') {
        longitud++;
    }
    return longitud;
}

bool compararCadenas(const char* cad1, const char* cad2) {
    int len1 = obtenerLongitud(cad1);
    int len2 = obtenerLongitud(cad2);

    if (len1 != len2) return false;

    for (int i = 0; i < len1; i++) {
        if (*(cad1 + i) != *(cad2 + i)) return false;
    }
    return true;
}

// --- PROBLEMA 5 ---

void intACadena(int numero, char* cadena) {
    int temp = numero;
    int len = 0;
    bool esNegativo = false;

    // Caso especial cuando el número es 0
    if (temp == 0) {
        *(cadena + 0) = '0';
        *(cadena + 1) = '\0';
        return;
    }

    if (temp < 0) {
        esNegativo = true;
        temp = -temp;
    }

    // Extraemos dígitos de derecha a izquierda (% 10) y los guardamos en memoria
    while (temp > 0) {
        int digito = temp % 10;
        *(cadena + len) = '0' + digito; // Convertimos el dígito numérico a carácter ASCII
        len++;
        temp /= 10;
    }

    if (esNegativo) {
        *(cadena + len) = '-';
        len++;
    }

    *(cadena + len) = '\0'; // Carácter nulo de fin de cadena

    // Invertimos la cadena en memoria usando dos punteros (inicio y fin)
    char* inicio = cadena;
    char* fin = cadena + len - 1;
    while (inicio < fin) {
        char aux = *inicio;
        *inicio = *fin;
        *fin = aux;
        inicio++;
        fin--;
    }
}

// --- PROBLEMA 7 ---

void eliminarRepetidos(const char* original, char* resultado) {
    int posOriginal = 0;
    int posResultado = 0;

    // Recorremos la cadena original con aritmética de punteros
    while (*(original + posOriginal) != '\0') {
        char actual = *(original + posOriginal);
        bool yaExiste = false;

        // Comprobamos si el carácter ya fue agregado a 'resultado'
        for (int i = 0; i < posResultado; i++) {
            if (*(resultado + i) == actual) {
                yaExiste = true;
                break;
            }
        }

        // Si no está repetido, lo escribimos en el nuevo bloque de memoria
        if (!yaExiste) {
            *(resultado + posResultado) = actual;
            posResultado++;
        }

        posOriginal++;
    }

    *(resultado + posResultado) = '\0'; // Marcamos el final del texto
}

// --- PROBLEMA 9 ---
int sumarBloques(const char* cadena, int n) {
    int len = obtenerLongitud(cadena);
    int residuo = len % n;
    int sumaTotal = 0;

    // Puntero auxiliar para movernos por el arreglo en memoria
    const char* p = cadena;

    // Si la longitud no se divide exactamente entre 'n',
    // procesamos primero las cifras sobrantes de la izquierda (equivale a rellenar con ceros)
    if (residuo > 0) {
        int num = 0;
        for (int i = 0; i < residuo; i++) {
            num = num * 10 + (*(p + i) - '0'); // Convertimos ASCII a número entero
        }
        sumaTotal += num;
        p += residuo; // Desplazamos el puntero en la memoria
    }

    // Procesamos todos los bloques completos de tamaño 'n'
    while (*p != '\0') {
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = num * 10 + (*(p + i) - '0');
        }
        sumaTotal += num;
        p += n; // Desplazamos el puntero 'n' posiciones
    }

    return sumaTotal;
}

// --- PROBLEMA 11 ---

void inicializarSala(char* sala, int filas, int columnas) {
    for (int i = 0; i < filas * columnas; i++) {
        *(sala + i) = '-'; // todos los asientos empiezan disponibles
    }
}

void mostrarSala(const char* sala, int filas, int columnas) {
    for (int f = 0; f < filas; f++) {
        // Imprimimos la letra de la fila (A, B, C, ...)
        cout << (char)('A' + f) << ": ";
        for (int c = 0; c < columnas; c++) {
            cout << *(sala + f * columnas + c) << " ";
        }
        cout << endl;
    }
}

bool reservarAsiento(char* sala, int columnas, int fila, int asiento) {
    char* pos = sala + fila * columnas + asiento; // direccion del asiento pedido
    if (*pos == '-') {
        *pos = '+';
        return true;
    }
    return false; // ya estaba reservado
}

bool cancelarAsiento(char* sala, int columnas, int fila, int asiento) {
    char* pos = sala + fila * columnas + asiento;
    if (*pos == '+') {
        *pos = '-';
        return true;
    }
    return false; // ya estaba disponible
}

// --- PROBLEMA 13 ---

int contarEstrellas(const int* matriz, int filas, int columnas) {
    int estrellas = 0;

    // Ignoramos los bordes: empezamos en 1 y terminamos en filas-2 / columnas-2
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            int centro = *(matriz + i * columnas + j);
            int izquierda = *(matriz + i * columnas + (j - 1));
            int derecha = *(matriz + i * columnas + (j + 1));
            int arriba = *(matriz + (i - 1) * columnas + j);
            int abajo = *(matriz + (i + 1) * columnas + j);

            double promedio = (centro + izquierda + derecha + arriba + abajo) / 5.0;

            if (promedio > 6) {
                estrellas++;
            }
        }
    }

    return estrellas;
}

// --- PROBLEMA 15 ---

void interseccionRectangulos(const int* A, const int* B, int* C) {
    // A y B tienen el formato {x, y, ancho, alto}
    int xA1 = *(A + 0), yA1 = *(A + 1);
    int xA2 = xA1 + *(A + 2), yA2 = yA1 + *(A + 3);

    int xB1 = *(B + 0), yB1 = *(B + 1);
    int xB2 = xB1 + *(B + 2), yB2 = yB1 + *(B + 3);

    // Esquina superior izquierda y esquina inferior derecha de la interseccion
    int x1 = (xA1 > xB1) ? xA1 : xB1;
    int y1 = (yA1 > yB1) ? yA1 : yB1;
    int x2 = (xA2 < xB2) ? xA2 : xB2;
    int y2 = (yA2 < yB2) ? yA2 : yB2;

    if (x2 > x1 && y2 > y1) {
        *(C + 0) = x1;
        *(C + 1) = y1;
        *(C + 2) = x2 - x1; // ancho
        *(C + 3) = y2 - y1; // alto
    } else {
        // No hay interseccion
        *(C + 0) = 0;
        *(C + 1) = 0;
        *(C + 2) = 0;
        *(C + 3) = 0;
    }
}

// --- PROBLEMA 17 ---

int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}

bool sonAmigables(int a, int b) {
    if (a == b) return false;
    return sumaDivisores(a) == b && sumaDivisores(b) == a;
}

void sumaNumerosAmigables(int limite, int* resultado) {
    *resultado = 0;

    for (int a = 2; a < limite; a++) {
        int b = sumaDivisores(a);

        // Solo sumamos cuando b > a para no contar dos veces la misma pareja
        if (b > a && b < limite && sonAmigables(a, b)) {
            *resultado += a + b;
        }
    }
}