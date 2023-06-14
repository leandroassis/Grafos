#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta{
    friend class Grafo;
    public:
        // construtor da classe Aresta
        Aresta(Vertice *, Vertice *, float);

        // getters
        float getPeso();
    private:
        // elementos da aresta do grafo
        Vertice *origem, *destino;
        float peso;
};

#endif