#ifndef CURSO_H
#define CURSO_H

#include <string>
#include "lista-classificados.h"
#include "lista-espera.h"

class Curso {
private:
    std::string nome;
    unsigned int vagas;
    ListaClassificados* classificados;
    ListaEspera* espera;
    
public:
    Curso(std::string nome, unsigned int vagas);
    ~Curso();
    
};

#endif
