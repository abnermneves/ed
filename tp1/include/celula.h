#ifndef CELULA_H
#define CELULA_H

#include "aluno.h"

class Celula {
private:
    Aluno* aluno;
    Celula* proximo;
    
public:
    Celula();
    Celula(Aluno* aluno);
    ~Celula();
    
    Aluno* get_aluno();
    Celula* get_proximo();
    void set_aluno(Aluno* aluno);
    void set_proximo(Celula* aluno);
};

#endif
