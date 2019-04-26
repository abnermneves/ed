#include "lista.h"
#include <iostream>

Lista::Lista(){
    Celula* cabeca = new Celula();
    this->primeira = cabeca;
    this->ultima = cabeca;
    this->tamanho = 0;
}

Lista::~Lista(){

}

void Lista::inserir(Aluno* aluno){
    Celula* c = new Celula(aluno);
    this->ultima->set_proxima(c);
    this->ultima = c;
    this->tamanho++;
    c->set_posicao(this->get_tamanho());
}

void Lista::imprimir(){
    Celula* atual = this->primeira->get_proxima();
    while (atual != nullptr){
        std::cout << atual->get_aluno()->get_nome() << " "
                  << atual->get_aluno()->get_nota() << std::endl;
        atual = atual->get_proxima();
    }
}

void Lista::esvaziar(){

}

bool Lista::vazia(){
    return this->primeira == this->ultima;
}

unsigned int Lista::get_tamanho(){
    return this->tamanho;
}

Celula* Lista::get_celula(unsigned int posicao){
    Celula* atual = this->primeira;
    while (atual->get_posicao() != posicao){
        atual = atual->get_proxima();
    }
    return atual;
}

Aluno* Lista::get_aluno(unsigned int posicao){
    return this->get_celula(posicao)->get_aluno();
}
