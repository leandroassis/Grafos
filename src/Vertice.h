#ifndef VERTICE_H
#define VERTICE_H

#include <string>

class Vertice{
    public:
        Vertice(std::string);

        std::string getNome();
    private:
        std::string nome;
};

#endif