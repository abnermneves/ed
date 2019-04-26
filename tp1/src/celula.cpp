#include "celula.h"
#include "aluno.h"

Celula::Celula(){
    this->aluno = nullptr;
    this->proxima = nullptr;
    this->anterior = nullptr;
    this->posicao = 0;
}

Celula::Celula(Aluno* aluno){
    this->aluno = aluno;
    this->proxima = nullptr;
    this->anterior = nullptr;
    this->posicao = 0;
}

Celula::~Celula(){

}

Aluno* Celula::get_aluno(){
    return this->aluno;
}

Celula* Celula::get_proxima(){
    return this->proxima;
}

Celula* Celula::get_anterior(){
    return this->anterior;
}

unsigned int Celula::get_posicao(){
    return this->posicao;
}

void Celula::set_aluno(Aluno* aluno){
    this->aluno = aluno;
}

void Celula::set_proxima(Celula* celula){
    this->proxima = celula;
}

void Celula::set_anterior(Celula* celula){
    this->anterior = celula;
}

void Celula::set_posicao(unsigned int posicao){
    this->posicao = posicao;
}
