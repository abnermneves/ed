#include <iostream>
#include "include/no.h"

No::No(){
  this->esq = nullptr;
  this->dir = nullptr;
  this->letra = '\0';
  this->chave = "";
}

No::~No(){
  if(this->esq)
    delete this->esq;
  if(this->dir)
    delete this->dir;
}

//-------------------------PESQUISA--------------------------//

No* No::pesquisaR(std::string chave, int p){
  //como as letras não ficam apenas nas folhas, é preciso
  //verificar se já está no último char do código buscado.
  //se estiver e o código tiver sido encontrado,
  //então retorna o nó atual. se não, retorna nullptr
  if (p == chave.size()){
    if (this->chave == chave)
      return this;
    else
      return nullptr;
  }

  //se o nó da esquerda existe e o char atual do código buscado é um ponto
  //então procura com o próximo char na subárvore da esquerda.
  //se o char atual é um traço e o nó da direita existe,
  //então procura com o próximo char na subárvore da esquerda.
  if (this->esq && chave[p] == '.')
    return this->esq->pesquisaR(chave, p+1);
  else if (this->dir)
    return this->dir->pesquisaR(chave, p+1);
  else
    return nullptr;
}

//chama o método recursivo de pesquisa para a raiz da árvore
No* No::pesquisa(std::string chave){
  return this->pesquisaR(chave, 0);
}

//-------------------------INSERE-----------------------------//

void No::insereR(char letra, std::string chave, int p){
  //se já desceu na árvore tanto quanto o número de char precisa
  //então insere a letra e a chave no nó atual
  if (p == chave.size()){
    this->letra = letra;
    this->chave = chave;
    return;
  }

  //se ainda falta char para ser percorrido no código
  //verifica se o próximo é um ponto ou traço
  //e insere na subárvore da esquerda ou da direita,
  //sendo que, se o nó adequado ainda não existir,
  //então ele é criado
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

//chama o método recursivo de inserir para a raiz da árvore
void No::insere(char letra, std::string chave){
  this->insereR(letra, chave, 0);
}

//-------------------------PRE-ORDEM---------------------------//

//imprime o elemento do nó atual e depois passa para os filhos
void No::preOrdem(){
  //só imprime se o nó realmente tiver uma letra e código
  //ie, se o tamanho da chave é diferente de zero
  if(this->chave.size())
    std::cout << this->letra << " " << this->chave << std::endl;

  //e agora chama o método recursivo para os nós filhos
  if(this->esq)
    this->esq->preOrdem();
  if (this->dir)
    this->dir->preOrdem();
}

//---------------------SETTERS E GETTERS-----------------------//

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
