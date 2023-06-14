#include <iostream>
#include "Grafo.h"

int main(int argc, char *argv[]){

    Grafo grafo;
    float pesoCaminho;
    std::string verticeOrigem, verticeDestino;

    if(argc < 2){
        std::cout << "Uso: " << argv[0] << " [operação desejada]" << std::endl;
        std::cout << "0 - Número de Enlaces dos vértices" << std::endl;
        std::cout << "1 - Matriz de Adjacência" << std::endl;
        std::cout << "2 - Identificar o menor caminho que conecta os vértices" << std::endl;
        std::cout << "3 - Verificar se o grafo é conexo" << std::endl;
        std::cout << "4 - Identificar o vértice com maior grau" << std::endl;
        return 1;
    }

    int operacao = std::stoi(argv[1]);

    switch(operacao){
        case 0:
            std::cout << "Número de Enlaces dos vértices: " << std::endl;
            grafo.mostraEnlacesVertices();
            break;
        case 1:
            std::cout << "Matriz de Adjacência: " << std::endl;
            grafo.mostraMatrizAdjacencia();
            break;
        case 2:
            std::cout << "Identificando o menor caminho que conecta os vértices" << std::endl;

            std::cout << "Insira o vertice de origem e o vertice de destino (Ex. A B)" << std::endl;
            std::cin >> verticeOrigem >> verticeDestino;

            pesoCaminho = grafo.mostraMenorCaminho(verticeOrigem, verticeDestino, 1);

            if(pesoCaminho == -1){
                std::cout << "Não existe um caminho que conecte os vértices " << verticeOrigem << " e " << verticeDestino << "." << std::endl;
            }
            else std::cout << "O caminho que conecta os vértices " << verticeOrigem << " e " << verticeDestino << " tem peso " << pesoCaminho << "." << std::endl;
            break;
        case 3:
            std::cout << "Verificando se o grafo é conexo: " << std::endl;
            std::cout << (grafo.verificaConectividade() ? "True" : "False");
            std::cout << std::endl;
            break;
        case 4:
            grafo.mostraVerticeComMaiorGrau();
            break;
        default:
            std::cout << "Operação inválida" << std::endl;
            return 1;
    }

    return 0;
}