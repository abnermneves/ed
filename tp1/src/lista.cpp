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
    c->set_anterior(this->ultima);
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
    this->ultima = this->primeira;
    this->tamanho = 0;
}

void Lista::ordenar(){
    Celula* atual = this->primeira;
    Celula* anterior = atual->get_anterior();
    Celula* prox = atual->get_proxima();
    Celula* prox2 = prox;


    if (this->get_tamanho() > 1){
      //se tem mais de 1 elemento, entao comeca a partir do segundo
      atual = atual->get_proxima()->get_proxima();

      float atualNota, anteriorNota;
      unsigned int pos;

        while (atual != nullptr){
          anterior = atual->get_anterior();
          prox = atual->get_proxima();
          prox2 = prox;
            atualNota = atual->get_aluno()->get_nota();
            anteriorNota = anterior->get_aluno()->get_nota();

            while (anterior != this->primeira && atualNota > anteriorNota){
                //troca as celulas
                anterior->set_proxima(prox);
                if (prox != nullptr){
                  prox->set_anterior(anterior);
                }
                atual->set_proxima(anterior);
                atual->set_anterior(anterior->get_anterior());
                anterior->get_anterior()->set_proxima(atual);
                anterior->set_anterior(atual);

                //atualiza as posicoes
                pos = anterior->get_posicao();
                anterior->set_posicao(atual->get_posicao());
                atual->set_posicao(pos);

                anterior = atual->get_anterior();
                if (anterior != this->primeira){
                  anteriorNota = anterior->get_aluno()->get_nota();
                }
                prox = atual->get_proxima();
            }
            atual = prox2;
        }
    }
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
