#include "Aresta.h"

Aresta::Aresta(Vertice *verticeOrigem, Vertice *verticeDestino, float pesoAresta){
    origem = verticeOrigem;
    destino = verticeDestino;
    peso = pesoAresta;
}

float Aresta::getPeso(){
    return peso;
}

void Aresta::getVertices(std::string *nomeOrigem, std::string *nomeDestino){
    *nomeOrigem = origem->getNome();
    *nomeDestino = destino->getNome();
}