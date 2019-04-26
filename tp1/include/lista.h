#ifndef LISTA_H
#define LISTA_H

#include "celula.h"

class Lista {
private:
    Celula* primeira;
    Celula* ultima;
    unsigned int tamanho;

public:
    Lista();
    ~Lista();

    void inserir(Aluno* aluno);
    void imprimir();
    void esvaziar();
    void ordenar();
    bool vazia();
    unsigned int get_tamanho();
    Aluno* get_aluno(unsigned int posicao);
    Celula* get_celula(unsigned int posicao);
};

#endif
