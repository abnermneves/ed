#include "curso.h"

Curso::Curso(std::string nome, unsigned int vagas){
    this->nome = nome;
    this->vagas = vagas;
    //this->classificados = new ListaClassificados();
    //this->ListaEspera = new ListaEspera();
}

Curso::~Curso(){
    //this->classificados->~ListaClassificados();
    //this->espera->~ListaEspera();
}
