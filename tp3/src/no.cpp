#include <iostream>
#include "include/no.h"

No::No(){
  this->esq = nullptr;
  this->dir = nullptr;
  letra = NULL;
  chave = nullptr;
}

No::~No(){

}

No* No::pesquisaR(No* t, std::string chave, int p){
  if (t == nullptr)
    return nullptr;
  if (p == chave.size()){
    std::string tChave = t->get_chave();
    if (tChave == chave)
      return t;
    else
      return nullptr;
  }
  if (chave[p] == '.')
    return pesquisaR(t->get_esq(), chave, p+1);
  else
    return pesquisaR(t->get_dir(), chave, p+1);

}

No* No::pesquisa(No* trie, std::string chave){
  return pesquisaR(trie, chave, 0);
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

No* No::insereR(No* t, char letra, std::string chave, int p){
  if (t == nullptr){
    return new No();
  }
  if (t->get_esq() == nullptr && t->get_dir() == nullptr){
    No* vazio = new No();
    return separa(vazio, t, p);
  }
  if (chave[p] == '.'){
    t->set_esq(insereR(t->get_esq(), letra, chave, p+1));
  }
  else {
    t->set_dir(insereR(t->get_dir(), letra, chave, p+1));
  }

  return t;
}

void No::insere(No** trie, char letra, std::string chave){
  *trie = insereR(*trie, letra, chave, 0);
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
