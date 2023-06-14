#include "Aresta.h"

Aresta::Aresta(Vertice *verticeOrigem, Vertice *verticeDestino, float pesoAresta){
    this->origem = verticeOrigem;
    this->destino = verticeDestino;
    this->peso = pesoAresta;
}

float Aresta::getPeso(){
    return peso;
}