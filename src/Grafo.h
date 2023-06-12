#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Aresta.h"
#include "Vertice.h"

class Grafo{
    public:
        Grafo();
        ~Grafo();

        void insereAresta(Vertice *, Vertice *, unsigned int);

        // funções de apresentação do Exercício
        void mostraEnlacesVertices();
        void mostraMatrizAdjacencia();
        void mostraMenorCaminho(Vertice *, Vertice *);
        void verificaConectividade();
        void mostraVerticeComMaiorGrau();

    private:
        std::vector<Aresta> arestas;
        std::vector<Vertice> vertices;

        // funções auxiliares
        short int existeVertice(Vertice *);
        // djikstra
};

#endif