#include "lista.h"

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
    this->ultimo->proximo = c;
    this->ultimo = c;
}

void Lista::imprimir(){
    atual = this->primeiro->proximo;
    while (atual != nullptr){
        std::cout << atual->get_nome() << " "
                  << atual->get_nota() << std::endl;
        atual = atual->proximo;
    }
}

void Lista::esvaziar(){
    
}

bool Lista::vazia(){
    return this->primeiro == this->ultimo;
}

Aluno* Lista::retirar(unsigned int id){

}
