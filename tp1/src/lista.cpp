#include "lista.h"
#include <iostream>

Lista::Lista(){
    Celula* cabeca = new Celula();
    this->primeiro = cabeca;
    this->ultimo = cabeca;
    this->tamanho = 0;
}

Lista::~Lista(){
    
}

void Lista::inserir(Aluno* aluno){
    Celula* c = new Celula(aluno);
    this->ultimo->set_proximo(c);
    this->ultimo = c;
}

void Lista::imprimir(){
    Celula* atual = this->primeiro->get_proximo();
    while (atual != nullptr){
        std::cout << atual->get_aluno()->get_nome() << " "
                  << atual->get_aluno()->get_nota() << std::endl;
        atual = atual->get_proximo();
    }
}

void Lista::esvaziar(){
    
}

bool Lista::vazia(){
    return this->primeiro == this->ultimo;
}

Aluno* Lista::retirar(unsigned int id){

}
