#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include "aluno.h"

class ListaSequencial {
private:
    unsigned int maxtam;
    unsigned int primeiro;
    unsigned int ultimo;
    Aluno* lista;
    
public:
    ListaSequencial(unsigned int maxtam);
    ~ListaSequencial();
    void inserir(Aluno* aluno); //implementado
    void imprimir(); //implementado
    void esvaziar();
    bool vazia(); //implementado
    bool cheia(); //implementado
    Aluno* retirar(unsigned int id);
    
    unsigned int get_maxtam();
};

#endif
