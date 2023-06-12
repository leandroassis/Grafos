#include <iostream>
#include "Grafo.h"

Grafo::Grafo() : arestas(1), vertices(1){
    // le o arquivo de entrada e cria os vertices e arestas, além de inserir no grafo
    
}

Grafo::~Grafo(){
    // dá dealloc nos vertices e arestas criados
    for (auto vertice : vertices){
        delete vertice;
    }

    for (auto aresta : arestas){
        delete aresta;
    }
}

void Grafo::insereAresta(Vertice *verticeOrigem, Vertice *verticeDestino, unsigned int pesoAresta){
    // cria uma aresta e insere no grafo
    Aresta novaAresta = new Aresta(verticeOrigem, verticeDestino, pesoAresta);
    arestas.push_back(novaAresta);
}

short int existeVertice(Vertice *vertice){
    // verifica se o vertice existe no grafo
    for (auto verticeGrafo : vertices){
        if (verticeGrafo->getNome() == vertice->getNome()){
            // se existe, retorna True
            return 1;
        }
    }

    // se não existe, retorna False
    return 0;
}

