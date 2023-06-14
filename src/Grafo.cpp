#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <utility>
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
            // se encontrar o vertice, retorna true e o indice do vertice
            *indiceVertice = i;
            return 1;
        }
    }

    // se não encontrar o vertice, retorna false
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
        for(auto aresta : arestas){
            if(aresta->origem->getNome() == vertice->getNome()) enlaces++;
            if(aresta->destino->getNome() == vertice->getNome()) enlaces++;
        }
        std::cout << enlaces << std::endl;
    }
}

void Grafo::mostraMatrizAdjacencia(){
    // mostra a matriz de adjacencia do grafo

    // para cada vertice de origem escolhido
    for(auto verticeOrigem : vertices){
        // verifica todos os vertices remanescentes
        
        for(auto verticeDestino : vertices){

            // verifica se existe uma aresta entre os vertices
            for(auto aresta : arestas){
                if((aresta->origem->getNome() == verticeOrigem->getNome() && aresta->destino->getNome() == verticeDestino->getNome()) \
                || (aresta->origem->getNome() == verticeDestino->getNome() && aresta->destino->getNome() == verticeOrigem->getNome())){
                    // se existe, mostra o peso da aresta
                    std::cout <<  aresta->getPeso() << " ";
                    goto proximoVertice;
                }
            }

            // se não existe, mostra 0
            std::cout << "NaN ";

            proximoVertice:;
        }
        std::cout << std::endl;
    }
}

float Grafo::mostraMenorCaminho(std::string nomeVerticeOrigem, std::string nomeVerticeDestino, int saida){
    // mostra o menor caminho entre dois vertices usando Dijkstra

    unsigned indiceVerticeDestino, indiceVerticeOrigem;
    std::vector<std::string> caminho;

    // verifica se os vertices existem
    if(!existeVertice(nomeVerticeOrigem) || !existeVertice(nomeVerticeDestino)){
        std::cout << "Erro: Vertice nao encontrado." << std::endl;
        return -1;
    }

    // inicio do algoritmo de Dijkstra
    int verticesVisitados[vertices.size()]; // cada item representa um vertice, 0 para não visitado, 1 para visitado
    float distancia[vertices.size()]; // cada item representa a distancia do vertice de origem para o vertice do indice

    for(unsigned i = 0; i < vertices.size(); i++){
        verticesVisitados[i] = 0;
        distancia[i] = -1;
    }

    // encontra o indice do vertice de origem
    (void) getVertice(nomeVerticeOrigem, &indiceVerticeOrigem);

    // inicializa a distancia do vertice de origem para a origem
    distancia[indiceVerticeOrigem] = 0; // valor padrão é zero
    // caso exista uma aresta entre o vertice de origem e ele mesmo, a distancia é o peso da aresta
    for(auto aresta : arestas){
        if(aresta->origem->getNome() == nomeVerticeOrigem && aresta->destino->getNome() == nomeVerticeOrigem){
            distancia[indiceVerticeOrigem] = aresta->getPeso();
            break;
        }
    }

    // cria um fila de prioridade para armazenar os vertices (indice, distancia)
    std::vector<std::pair<unsigned, float>> filaPrioridade;
    filaPrioridade.push_back(std::make_pair(indiceVerticeOrigem, distancia[indiceVerticeOrigem]));

    // enquanto a fila de prioridade não estiver vazia
    while(!filaPrioridade.empty()){

        // remove o primeiro elemento da fila de prioridade
        std::pair<unsigned, float> verticeAtual = filaPrioridade.front();
        filaPrioridade.erase(filaPrioridade.begin());

        // verifica se o vertice atual já foi visitado
        if(verticesVisitados[verticeAtual.first] == 0){
            // se não foi visitado, marca como visitado
            verticesVisitados[verticeAtual.first]= 1;

            // verifica se o vertice atual é o vertice de destino
            if(vertices[verticeAtual.first]->getNome() == nomeVerticeDestino){
                // se for, mostra o caminho


                if(saida == 1){
                    //std::cout << nomeVerticeOrigem << "->";
                    for(unsigned i = 1; i < caminho.size(); i++){
                        std::cout << caminho[i] << "->";
                    }
                    std::cout << nomeVerticeDestino << std::endl;
                }
                
                //e retorna a distancia
                return verticeAtual.second;
            }

            // para cada aresta do vertice atual
            for(auto aresta : arestas){
                // verifica se a aresta é do vertice atual para outro vertice
                if(aresta->origem->getNome() == vertices[verticeAtual.first]->getNome()){
                    // se for, verifica se o vertice de destino já foi visitado
                    (void) getVertice(aresta->destino->getNome(), &indiceVerticeDestino);
                    if(verticesVisitados[indiceVerticeDestino] == 0){
                        // se não foi visitado, verifica se a distancia do vertice de destino é maior que a distancia do vertice atual + o peso da aresta
                        if(distancia[indiceVerticeDestino] > distancia[verticeAtual.first] + aresta->getPeso() || distancia[indiceVerticeDestino] == -1){
                            // se for, atualiza a distancia do vertice de destino
                            distancia[indiceVerticeDestino] = distancia[verticeAtual.first] + aresta->getPeso();
                            // insere o vertice de destino na fila de prioridade
                            filaPrioridade.push_back(std::make_pair(indiceVerticeDestino, distancia[indiceVerticeDestino]));
                            caminho.push_back(vertices[verticeAtual.first]->getNome());
                        }
                    }
                }
            }
        }
    }

    // encontra o indice do vertice de destino e retorna sua distancia
    (void) getVertice(nomeVerticeDestino, &indiceVerticeDestino);
    return distancia[indiceVerticeDestino];
}

int Grafo::verificaConectividade(){
    // verifica se o grafo é conexo

    // verificar se existe caminho entre todos os vertices

    return 1;
}

void Grafo::mostraVerticeComMaiorGrau(){
    // mostra o vertice com maior grau

    unsigned indiceMaiorGrau = 0;

    for(unsigned i = 0; i < vertices.size(); i++){
        for(auto aresta : arestas){
            if(aresta->origem->getNome() == vertices[i]->getNome() || aresta->destino->getNome() == vertices[i]->getNome()) vertices[i]->setGrau(aresta->getPeso() + vertices[i]->getGrau());
        }

        if(vertices[i]->getGrau() > vertices.at(indiceMaiorGrau)->getGrau()) indiceMaiorGrau = i;
    }

    std::cout << "Vertice com maior grau: " << vertices.at(indiceMaiorGrau)->getNome() << std::endl;
}