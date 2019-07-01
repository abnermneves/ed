#include <iostream>
#include "include/no.h"

No::No(){
  this->esq = nullptr;
  this->dir = nullptr;
  this->letra = '\0';
  this->chave = "";
}

No::~No(){

}

No* No::pesquisaR(std::string chave, int p){
  if (p == chave.size()){
    if (this->chave == chave)
      return this;
  }
  if (this->esq && chave[p] == '.')
    return this->esq->pesquisaR(chave, p+1);
  else if (this->dir)
    return this->dir->pesquisaR(chave, p+1);
  else
    return nullptr;
}

No* No::pesquisa(std::string chave){
  return this->pesquisaR(chave, 0);
}

No* No::separa(No* no1, No* no2, int p){
  No* novo = new No();
  char c1 = no1->chave[p];
  char c2 = no2->chave[p];

  if (c1 == '.' && c2 == '.'){
    novo->set_esq(separa(no1, no2, p+1));
  } else if (c1 == '.' && c2 == '-'){
      novo->set_esq(no1);
      novo->set_dir(no2);
  } else if (c1 == '-' && c2 == '.'){
      novo->set_esq(no2);
      novo->set_dir(no1);
  } else if (c1 == '-' && c2 == '-'){
      novo->set_dir(separa(no1, no2, p+1));
  }

  return novo;
}

void No::insereR(char letra, std::string chave, int p){
  if (p == chave.size()){
    this->letra = letra;
    this->chave = chave;
    return;
  }
  if (chave[p] == '.'){
    if (!this->esq)
      this->esq = new No();
    this->esq->insereR(letra, chave, p+1);
  }
  else {
    if (!this->dir)
      this->dir = new No();
    this->dir->insereR(letra, chave, p+1);
  }

}

void No::insere(char letra, std::string chave){
  this->insereR(letra, chave, 0);
}

void No::preOrdem(){
  std::cout << this->letra << " " << this->chave << std::endl;
  if(this->esq)
    this->esq->preOrdem();
  if (this->dir)
    this->dir->preOrdem();
}

void No::set_letra(char letra){
  this->letra = letra;
}

void No::set_chave(std::string chave){
  this->chave = chave;
}

char No::get_letra(){
  return this->letra;
}

std::string No::get_chave(){
  return this->chave;
}

No* No::get_esq(){
  return this->esq;
}

No* No::get_dir(){
  return this->dir;
}

void No::set_esq(No* esq){
  this->esq = esq;
}

void No::set_dir(No* dir){
  this->dir = dir;
}
