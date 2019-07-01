#include "include/no.h"

No::No(){

}

No::~No(){

}

No* No::pesquisaR(No* t, std::string chave, int p){
  if (t == nullptr)
    return nullptr;
  if (t->get_esq() == nullptr && t->get_dir() == nullptr){
    std::string noChave = t->get_chave();
    if (noChave == chave){
      return t;
    }
    else {
      return nullptr;
    }
  }
  if (chave[p] == 0)

  return t;
}

No* No::pesquisa(No* trie, int chave){

  return trie;
}

No* No::insereR(No* t, std::string letra, int p){

  return t;
}

void No::insere(No** trie, std::string letra){

}

No* No::separa(No* no1, No* no2, int p){

  return no1;
}

void No::set_letra(std::string letra){
  this->letra = letra;
}

void No::set_chave(std::string chave){
  this->chave = chave;
}

std::string No::get_letra(){
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
