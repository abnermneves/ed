#include "curso.h"

Curso::Curso(std::string nome, unsigned int vagas){
    this->nome = nome;
    this->vagas = vagas;
    //this->espera = new Lista();
}

Curso::~Curso(){
    //this->espera->~Lista();
}

std::string Curso::get_nome(){
    return this->nome;
}

unsigned int Curso::get_vagas(){
    return this->vagas;
}
