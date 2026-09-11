#include <iostream>
#include "funciones.h"

using namespace std;

int main() {

    cout << "=== PROBLEMA 7: ELIMINAR REPETIDOS ===" << endl;
    char textoOriginal[] = "bananas";
    char textoSinRepetidos[50];

    eliminarRepetidos(textoOriginal, textoSinRepetidos);

    cout << "Original: " << textoOriginal << ". Sin repetidos: " << textoSinRepetidos << "." << endl;

    return 0;
}