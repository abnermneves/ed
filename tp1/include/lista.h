#ifndef LISTA_H
#define LISTA_H

#include "celula.h"

template <typename T>
class Celula;

template <typename T>
class Lista {
private:
    Celula<T>* primeira;
    Celula<T>* ultima;
    unsigned int tamanho;

public:
    Lista();
    ~Lista();

    void inserir(T objeto);
    void imprimir();
    void esvaziar();
    bool vazia();
    unsigned int get_tamanho();
    T get_objeto(unsigned int posicao);
    Celula<T>* get_celula(unsigned int posicao);
    void imprimir_entrada();
    void remover(unsigned int posicao);
};

#endif
