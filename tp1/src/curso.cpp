#include <iostream>
#include "curso.h"

Curso::Curso(unsigned int id, std::string nome, unsigned int vagas){
    this->id = id;
    this->nome = nome;
    this->vagas = vagas;
    this->nota_corte = 0;
    this->classificados = new Lista<Aluno*>();
    this->espera = new Lista<Aluno*>();
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

unsigned int Curso::get_id(){
    return this->id;
}

void Curso::imprimir(){
  std::cout << this->nome << " " << this->nota_corte << std::endl;
}
