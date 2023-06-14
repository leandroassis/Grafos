#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include "Aresta.h"
#include "Vertice.h"

#define arquivo "grafo.csv"

class Grafo{
    public:
        Grafo();
        ~Grafo();

        void insereAresta(Vertice *, Vertice *, float);
        int getVertice(std::string, unsigned *);

        // funções de apresentação do Exercício
        void mostraEnlacesVertices();
        void mostraMatrizAdjacencia();
        void mostraMenorCaminho(Vertice *, Vertice *);
        int verificaConectividade();
        void mostraVerticeComMaiorGrau();

    private:
        std::vector<Aresta*> arestas;
        std::vector<Vertice*> vertices;

        // funções auxiliares
        int existeVertice(std::string);
        int parseArquivoEntrada(std::vector<std::string> *, std::vector<std::string> *, std::vector<float> *);

        // djikstra
};

#endif