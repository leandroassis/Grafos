#ifndef VERTICE_H
#define VERTICE_H

#include <string>

class Vertice{
    public:
        Vertice(std::string);

        std::string getNome();
        
        float getGrau();
        void setGrau(float);
    private:
        std::string nome;
        float grau;
};

#endif