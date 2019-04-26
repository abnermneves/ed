#ifndef CURSO_H
#define CURSO_H

#include <string>
#include "lista.h"

class Curso {
private:
    std::string nome;
    unsigned int vagas;
    Lista* classificados;
    Lista* espera;
    
public:
    Curso(std::string nome, unsigned int vagas);
    ~Curso();
    
    std::string get_nome();
    unsigned int get_vagas();
};

#endif
