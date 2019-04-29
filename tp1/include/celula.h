#ifndef CELULA_H
#define CELULA_H

#include "aluno.h"

class Celula {
private:
    unsigned int posicao;
    Aluno* aluno;
    Celula* proxima;
    Celula* anterior;

public:
    Celula();
    Celula(Aluno* aluno);
    ~Celula();

    Aluno* get_aluno();
    Celula* get_proxima();
    Celula* get_anterior();
    unsigned int get_posicao();
    void set_aluno(Aluno* aluno);
    void set_proxima(Celula* celula);
    void set_anterior(Celula* celula);
    void set_posicao(unsigned int posicao);
    void swap(Celula* anterior);
};

#endif
