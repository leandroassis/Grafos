#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta{
    public:
        // construtor da classe Aresta
        Aresta(Vertice *, Vertice *, float);

        // getters
        float getPeso();
        void getVertices(std::string *, std::string *);

    private:
        // elementos da aresta do grafo
        Vertice *origem, *destino;
        float peso;
};

#endif