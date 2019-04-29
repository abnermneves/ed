#include "aluno.h"

Aluno::Aluno(unsigned int id,
          std::string nome,
          float nota,
          unsigned int p,
          unsigned int s){

    this->id = id;
    this->nome = nome;
    this->nota = nota;
    this->p = p;
    this->s = s;
}

Aluno::Aluno(){

}

Aluno::~Aluno(){

}

std::string Aluno::get_nome(){
    return this->nome;
}

float Aluno::get_nota(){
    return this->nota;
}

unsigned int Aluno::get_p(){
    return this->p;
}

unsigned int Aluno::get_s(){
    return this->s;
}

unsigned int Aluno::get_id(){
    return this->id;
}
