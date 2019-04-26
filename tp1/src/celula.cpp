#include "celula.h"
#include "aluno.h"

Celula::Celula(){
    this->aluno = nullptr;
    this->proximo = nullptr;
}

Celula::Celula(Aluno* aluno){
    this->aluno = aluno;
    this->proximo = nullptr;
}

Celula::~Celula(){
    
}

Aluno* Celula::get_aluno(){
    return this->aluno;
}

Celula* Celula::get_proximo(){
    return this->proximo;
}

void Celula::set_aluno(Aluno* aluno){
    this->aluno = aluno;
}

void Celula::set_proximo(Celula* aluno){
    this->proximo = aluno;
}
