#ifndef LISTA_CLASSIFICADOS_H
#define LISTA_CLASSIFICADOS_H

#include "aluno.h"

class ListaClassificados {
private:
    const unsigned int maxtam;
    unsigned int primeiro;
    unsigned int ultimo;
    Aluno* alunos[maxtam];
    
public:
    ListaClassificados(unsigned int maxtam);
    ~ListaClassificados();
    void inserir(Aluno* aluno);
    void imprimir();
    void esvaziar();
    bool vazia();
    Aluno* retirar(unsigned int id);
    
};

#endif
