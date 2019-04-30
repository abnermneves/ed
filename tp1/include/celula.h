#ifndef CELULA_H
#define CELULA_H

#include "aluno.h"
#include "curso.h"

template <typename T>
class Celula {
private:
    unsigned int posicao;
    T objeto;
    Celula<T>* proxima;
    Celula<T>* anterior;

public:
    Celula();
    Celula(T objeto);
    ~Celula();

    T get_objeto();
    Celula<T>* get_proxima();
    Celula<T>* get_anterior();
    unsigned int get_posicao();
    void set_objeto(T aluno);
    void set_proxima(Celula<T>* celula);
    void set_anterior(Celula<T>* celula);
    void set_posicao(unsigned int posicao);
    void trocar(Celula<T>* anterior);
};

#endif
