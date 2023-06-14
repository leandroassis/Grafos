#include <iostream>
#include "Grafo.h"

int main(int argc, char *argv[]){

    Grafo grafo;

    grafo.mostraEnlacesVertices();

    grafo.mostraMatrizAdjacencia();

    // falta implementar a 3

    // falta implementar a 4
    std::cout << (grafo.verificaConectividade() ? "true" : "false");
    std::cout << std::endl;

    grafo.mostraVerticeComMaiorGrau();

    return 0;
}