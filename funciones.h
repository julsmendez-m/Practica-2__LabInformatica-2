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

#endif // FUNCIONES_H
