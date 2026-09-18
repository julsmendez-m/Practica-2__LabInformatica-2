#ifndef FUNCIONES_H
#define FUNCIONES_H


//----- problema 1 ------

// función para calcular los billetes y monedas.
// - denominaciones: puntero a arreglo constante
// - tamano: cantidad de denominaciones disponibles.
// - monto: puntero a la cantidad ingresada
// - resultado: puntero al arreglo donde se guarda el conteo de cada denominación.
void calcularCambio(const int* denominaciones, int tamano, int* monto, int* resultado);

// imprimir los resultados en consola pasando punteros constantes.
void imprimirResultado(const int* denominaciones, const int* resultado, int tamano, const int* faltante);


//------- problema 3 -------

int obtenerLongitud(const char* cad);
bool compararCadenas(const char* cad1, const char* cad2);


// ----- PROBLEMA 5 -----
// Recibe un entero y escribe la cadena resultante en el arreglo 'cadena' usando punteros
void intACadena(int numero, char* cadena);


// --- PROBLEMA 7 ---
// Copia de 'original' a 'resultado' omitiendo caracteres repetidos
void eliminarRepetidos(const char* original, char* resultado);


// ----PROBLEMA 9 -----

// Recibe la cadena numérica (constante) y el tamaño del bloque 'n'.
// Devuelve la suma de los bloques de 'n' cifras.
int sumarBloques(const char* cadena, int n);


// ---- PROBLEMA 11 ----
// La sala se maneja como un arreglo de char de una sola dimensión
// (fila * columnas + asiento), '-' = disponible, '+' = reservado.

// Deja todos los asientos de la sala en disponible ('-').
void inicializarSala(char* sala, int filas, int columnas);

// Imprime la sala fila por fila.
void mostrarSala(const char* sala, int filas, int columnas);

// Reserva el asiento indicado si estaba disponible. Retorna true si se pudo reservar.
bool reservarAsiento(char* sala, int columnas, int fila, int asiento);

// Cancela el asiento indicado si estaba reservado. Retorna true si se pudo cancelar.
bool cancelarAsiento(char* sala, int columnas, int fila, int asiento);


// ---- PROBLEMA 13 ----
// Recibe un puntero a la matriz de enteros (aplanada por filas) y retorna
// el numero de estrellas encontradas, ignorando los bordes de la matriz.
int contarEstrellas(const int* matriz, int filas, int columnas);


// ---- PROBLEMA 15 ----
// A y B son arreglos {x, y, ancho, alto}. Por referencia se retorna en C
// el rectangulo interseccion (si no hay interseccion, C queda en {0,0,0,0}).
void interseccionRectangulos(const int* A, const int* B, int* C);


// ---- PROBLEMA 17 ----

// Suma de los divisores propios de n (sin contar el mismo n).
int sumaDivisores(int n);

// Dice si a y b son numeros amigables.
bool sonAmigables(int a, int b);

// Halla, por puntero, la suma de todos los numeros amigables menores que 'limite'.
void sumaNumerosAmigables(int limite, int* resultado);

#endif // FUNCIONES_H
