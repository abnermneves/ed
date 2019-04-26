#ifndef LISTA_H
#define LISTA_H

#include "celula.h"

class Lista {
private:
    Celula* primeiro;
    Celula* ultimo;
    unsigned int tamanho;
    
public:
    Lista();
    ~Lista();
    
    void inserir(Aluno* aluno);
    void imprimir();
    void esvaziar();
    bool vazia();
    unsigned int get_tamanho();
    Aluno* retirar(unsigned int id);
};

#endif
