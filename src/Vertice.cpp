#include "Vertice.h"

Vertice::Vertice(std::string nomeVertice){
    this->nome = nomeVertice;
    this->grau = 0.0;
}

std::string Vertice::getNome(){
    return nome;
}

void Vertice::setGrau(float grau){
    this->grau = grau;
}

float Vertice::getGrau(){
    return grau;
}