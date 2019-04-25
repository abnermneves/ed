#include "curso.h"

Curso::Curso(std::string nome, unsigned int vagas){
    this->nome = nome;
    this->vagas = vagas;
    //this->classificados = new ListaSequencial();
    //this->ListaEspera = new ListaEspera();
}

Curso::~Curso(){
    //this->classificados->~ListaSequencial();
    //this->espera->~ListaEspera();
}

std::string Curso::get_nome(){
    return this->nome;
}

unsigned int Curso::get_vagas(){
    return this->vagas;
}
