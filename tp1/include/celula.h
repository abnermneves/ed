#ifndef CELULA_H
#define CELULA_H

#include "aluno.h"

class Celula {
private:
    Aluno* aluno;
    Celula* proximo;
    
public:
    Celula(Aluno* aluno);
    ~Celula();
    
};

#endif
