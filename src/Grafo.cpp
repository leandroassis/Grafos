#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Grafo.h"

Grafo::Grafo(){
    // le o arquivo de entrada e cria os vertices e arestas, além de inserir no grafo
    
    std::vector<std::string> verticesOrigem, verticesDestino;
    std::vector<float> pesosArestas;

    if(!parseArquivoEntrada(&verticesOrigem, &verticesDestino, &pesosArestas)){
        std::cout << "Erro ao fazer o parse do arquivo de entrada." << std::endl;
        exit(1);
    }

    // cria os vertices e insere no grafo
    for (unsigned i = 0; i < verticesOrigem.size(); i++){

        // verifica se o vertice de origem e destino já existem no grafo
        // e os inclui caso não existam
        if(!existeVertice(verticesOrigem.at(i))){
            Vertice *novoVertice = new Vertice(verticesOrigem.at(i));
            vertices.push_back(novoVertice);
        }

        if(!existeVertice(verticesDestino.at(i))){
            Vertice *novoVertice = new Vertice(verticesDestino.at(i));
            vertices.push_back(novoVertice);
        }


        // procura a posição dos vértices de origem e destino no vetor de vertices da classe
        unsigned indiceVerticeOrigem, indiceVerticeDestino;

        if(getVertice(verticesOrigem.at(i), &indiceVerticeOrigem) == 0){
            std::cout << "Erro ao encontrar o vertice de origem." << std::endl;
            exit(1);
        }

        if(getVertice(verticesDestino.at(i), &indiceVerticeDestino) == 0){
            std::cout << "Erro ao encontrar o vertice de destino." << std::endl;
            exit(1);
        }
        
        // cria uma aresta linkando os vértices de origem e destino e insere no gráfico
        insereAresta(vertices[indiceVerticeOrigem], vertices[indiceVerticeDestino], pesosArestas.at(i));
    }
}

Grafo::~Grafo(){
    // dá dealloc nos vertices e arestas criados
    for (auto aresta : arestas){
        delete aresta;
    }

    for (auto vertice : vertices){
        delete vertice;
    }
}

int Grafo::getVertice(std::string nomeVertice, unsigned *indiceVertice){
    // retorna o indice do vertice no vetor de vertices
    
    for (unsigned i = 0; i < vertices.size(); i++){
        if (vertices.at(i)->getNome() == nomeVertice){
            // se encontrar o vertice, retorna 1 e o indice do vertice
            *indiceVertice = i;
            return 1;
        }
    }

    // se não encontrar o vertice, retorna -1
    return 0;
}

int Grafo::parseArquivoEntrada(std::vector<std::string> *verticesOrigem, std::vector<std::string> *verticesDestino, std::vector<float> *pesosArestas){
    // faz o parse do arquivo de entrada e insere os dados nos vetores passados por referência
    std::fstream arquivoEntrada;
    std::string linhaArquivo;

    // abre o arquivo de entrada
    arquivoEntrada.open(arquivo, std::ios::in);

    // se o arquivo não existe, retorna 0
    if(!arquivoEntrada.is_open()) return 0;

    // faz o parse do arquivo de entrada
    while(getline(arquivoEntrada, linhaArquivo)){
        // separa os itens da linha por ";"
        std::stringstream linha(linhaArquivo);
        std::string item[3];
        unsigned itemCount = 0;

        while(itemCount < 3){
            getline(linha, item[itemCount], ';');
            itemCount++;
        }
        
        // insere os itens nos vetores passados por referência
        verticesOrigem->push_back(item[0]);
        verticesDestino->push_back(item[1]);
        pesosArestas->push_back(std::stof(item[2]));

    }

    arquivoEntrada.close();
    return 1;
}

void Grafo::insereAresta(Vertice *verticeOrigem, Vertice *verticeDestino, float pesoAresta){
    // cria uma aresta e insere no grafo
    Aresta *novaAresta = new Aresta(verticeOrigem, verticeDestino, pesoAresta);
    arestas.push_back(novaAresta);
}

int Grafo::existeVertice(std::string nomeVertice){
    // verifica se o vertice existe no grafo
    for (auto verticeGrafo : vertices){
        if (verticeGrafo->getNome() == nomeVertice){
            // se existe, retorna True
            return 1;
        }
    }

    // se não existe, retorna False
    return 0;
}

void Grafo::mostraEnlacesVertices(){
    // mostra os enlaces entre os vertices

    for (auto vertice : vertices){
        std::cout << vertice->getNome() << ": ";
        int enlaces = 0;
        std::string nomeVerticeTemp1, nomeVerticeTemp2;
        for(auto aresta : arestas){
            aresta->getVertices(&nomeVerticeTemp1, &nomeVerticeTemp2);
            if(nomeVerticeTemp1 == vertice->getNome()) enlaces++;
            if(nomeVerticeTemp2 == vertice->getNome()) enlaces++;
        }
        std::cout << enlaces << std::endl;
    }
}

