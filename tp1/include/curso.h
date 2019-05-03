#ifndef CURSO_H
#define CURSO_H

#include <string>
#include "lista.h"

template <typename T>
class Lista;

class Curso {
private:
    unsigned int id;
    std::string nome;
    unsigned int vagas;
    float nota_corte;
    Lista<Aluno*>* classificados;
    Lista<Aluno*>* espera;
    Lista<Aluno*>* po; //alunos que escolheram como primeira opção
    Lista<Aluno*>* so; //alunos que escolheram como segunda opção

public:
    Curso(unsigned int id, std::string nome, unsigned int vagas);
    ~Curso();

    std::string get_nome();
    unsigned int get_vagas();
    unsigned int get_id();
    void imprimir();
    void imprimir_entrada();
    Lista<Aluno*>* get_po();
    Lista<Aluno*>* get_so();
};

#endif
