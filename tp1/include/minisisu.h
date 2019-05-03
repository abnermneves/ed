#ifndef MINISISU_H
#define MINISISU_H

#include "curso.h"
#include "aluno.h"
#include "lista.h"

class MiniSisu{
private:
    Lista<Curso*>* cursos;
    Lista<Aluno*>* alunos;

public:
    MiniSisu();
    void ler();
    void imprimir();
    void imprimir_entrada();
    Lista<Curso*>* get_lista_cursos();
    Lista<Aluno*>* get_lista_alunos();
    void classificar();
    void ordenar_alunos();
    void desempatar(unsigned int* i, unsigned int* j);
};

#endif
