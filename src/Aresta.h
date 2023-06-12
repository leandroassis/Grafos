#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta{
    public:
        // construtor da classe Aresta
        Aresta(Vertice *, Vertice *, unsigned float);

        // getters
        unsigned float getPeso();
        void getVertices(std::string *, std::string *);

    private:
        // elementos da aresta do grafo
        Vertice *origem, *destino;
        unsigned float peso;
};

#endif