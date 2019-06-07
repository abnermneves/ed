#include "celula.h"

Celula::Celula(){
  this->esq = 0;
  this->dir = 0;
  this->prox = nullptr;
}

Celula::Celula(int esq, int dir){
  this->esq = esq;
  this->dir = dir;
  this->prox = nullptr;
}

Celula::~Celula(){

}

int Celula::get_esq(){
  return this->esq;
}

int Celula::get_dir(){
  return this->dir;
}

Celula* Celula::get_prox(){
  return this->prox;
}

void Celula::set_esq(int esq){
  this->esq = esq;
}

void Celula::set_dir(int dir){
  this->dir = dir;
}

void Celula::set_prox(Celula* prox){
  this->prox = prox;
}
