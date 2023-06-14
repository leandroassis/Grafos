#include "Vertice.h"

Vertice::Vertice(std::string nomeVertice){
    this->nome = nomeVertice;
}

std::string Vertice::getNome(){
    return nome;
}