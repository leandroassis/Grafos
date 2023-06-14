#include <iostream>
#include "Grafo.h"

int main(int argc, char *argv[]){

    Grafo grafo;

    grafo.mostraEnlacesVertices();

    grafo.mostraMatrizAdjacencia();

    std::cout << grafo.mostraMenorCaminho("B", "B", 1) << std::endl;


    std::cout << (grafo.verificaConectividade() ? "true" : "false");
    std::cout << std::endl;

    grafo.mostraVerticeComMaiorGrau();

    return 0;
}