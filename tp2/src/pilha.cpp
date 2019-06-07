#include "pilha.h"

Pilha::Pilha(){
  Celula* cabeca = new Celula();
  this->topo = cabeca;
  this->fundo = cabeca;
}

Pilha::~Pilha(){

}

bool Pilha::vazia(){
  return this->topo == this->fundo;
}

void Pilha::empilha(int esq, int dir){
  Celula* celula = new Celula(esq, dir);
  celula->set_prox(this->topo);
  this->topo = celula;
}

void Pilha::desempilha(int* esq, int* dir){
  if (this->vazia())
    return;
  Celula* celula = this->topo;
  this->topo = celula->get_prox();
  *esq = celula->get_esq();
  *dir = celula->get_dir();
}
