#include <iostream>
#include <iomanip>
#include "curso.h"

Curso::Curso(unsigned int id, std::string nome, unsigned int vagas){
    this->id = id;
    this->nome = nome;
    this->vagas = vagas;
    this->nota_corte = 0;
    this->classificados = new Lista<Aluno*>();
    this->espera = new Lista<Aluno*>();
    this->po = new Lista<Aluno*>();
    this->so = new Lista<Aluno*>();
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
    std::cout << this->nome << " "
              << std::setprecision(2)
              << this->nota_corte << std::endl;
}

void Curso::imprimir_entrada(){
    std::cout << this->nome << " " << this->vagas << std::endl << "po" << std::endl;
    this->po->imprimir_entrada();
    std::cout << "so" << std::endl;
    this->so->imprimir_entrada();
}

Lista<Aluno*>* Curso::get_po(){
    return this->po;
}

Lista<Aluno*>* Curso::get_so(){
    return this->so;
}
