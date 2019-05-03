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

public:
    Curso(unsigned int id, std::string nome, unsigned int vagas);
    ~Curso();

    std::string get_nome();
    unsigned int get_vagas();
    unsigned int get_id();
    void imprimir();
    void imprimir_entrada();
    bool classificar(Aluno* aluno);
};

#endif
