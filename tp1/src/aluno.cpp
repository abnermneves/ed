#include "aluno.h"

Aluno::Aluno(std::string nome,
          unsigned int nota,
          unsigned int p,
          unsigned int s){

    this->nome = nome;
    this->nota = nota;
    this->p = p;
    this->s = s;
}

Aluno::Aluno(){
    
}

Aluno::~Aluno(){

}
