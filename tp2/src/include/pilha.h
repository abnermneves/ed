#ifndef PILHA_H
#define PILHA_H

#include "celula.h"

class Pilha {
private:
  Celula* topo;
  Celula* fundo;

public:
  Pilha();
  ~Pilha();
  bool vazia();
  void empilha(Celula* celula);
  void empilha(int esq, int dir);
  void desempilha(int* esq, int* dir);

};

#endif
