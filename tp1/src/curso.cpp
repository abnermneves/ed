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
}

Curso::~Curso(){
    this->classificados->~Lista();
    this->espera->~Lista();
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
              << std::setprecision(2) << std::fixed
              << this->nota_corte << std::endl
              << "Classificados" << std::endl;
    this->classificados->imprimir();
    std::cout << "Lista de espera" << std::endl;
    this->espera->imprimir();
    std::cout << std::endl;
}

void Curso::imprimir_entrada(){
    std::cout << this->nome << " " << this->vagas << std::endl;
}

bool Curso::classificar(Aluno* aluno){
    if (this->classificados->get_tamanho() < this->vagas){
        this->classificados->inserir(aluno);
        if (this->classificados->get_tamanho() == this->vagas){
            this->nota_corte = aluno->get_nota();
        }
        return true;
    } else {
        this->espera->inserir(aluno);
        return false;
    }
}