#include <iostream>
#include <string>
#include "minisisu.h"
#include "celula.h"

MiniSisu::MiniSisu(){
    this->cursos = new Lista<Curso*>();
    this->alunos = new Lista<Aluno*>();
}

void MiniSisu::ler(){
    unsigned int n, m, vagas, p, s;
    float nota;
    std::string nome;
    Curso* curso;
    Aluno* aluno;

    std::cin >> n >> m;
    std::cin.ignore();
    for (unsigned int i = 1; i <= n; i++){
        std::getline(std::cin, nome);
        std::cin >> vagas;
        std::cin.ignore();
        curso = new Curso(i, nome, vagas);
        this->cursos->inserir(curso);
    }

    Lista<Curso*>* cursos = this->get_lista_cursos();
    cursos->imprimir();

    for (unsigned int i = 1; i <= m; i++){
        std::getline(std::cin, nome);
        std::cin >> nota >> p >> s;
        std::cin.ignore();

        //precisa aumentar 1 porque fiz a lista baseada
        //no fato de que a celula cabeça tem indice 0
        p++;
        s++;
        aluno = new Aluno(i, nome, nota, p, s);
        this->alunos->inserir(aluno);

        //insere o aluno na lista de po e so dos cursos escolhidos
        curso = cursos->get_objeto(p);
        curso->get_po()->inserir(aluno);
        curso = cursos->get_objeto(s);
        curso->get_so()->inserir(aluno);
    }
}

void MiniSisu::classificar(){
    Celula<Curso*>* celula = this->cursos->get_celula(0);
    Curso* curso;
    Aluno* aluno;
    unsigned int n = this->cursos->get_tamanho();
    unsigned int m;
    bool aprovado;

    for (unsigned int i = 1; i <= n ; i++){
        curso = this->cursos->get_objeto(i);
        auto po = curso->get_po();
        curso->ordenar_alunos(po);

        unsigned int m = po->get_tamanho();

        for (unsigned int i = 1; i <= m; i++){
            aluno = po->get_objeto(i);
            aprovado = curso->classificar(aluno);
        }
    }
}

Lista<Curso*>* MiniSisu::get_lista_cursos(){
    return this->cursos;
}

Lista<Aluno*>* MiniSisu::get_lista_alunos(){
    return this->alunos;
}

void MiniSisu::imprimir(){
    this->cursos->imprimir();
    this->alunos->imprimir();
}

void MiniSisu::imprimir_entrada(){
    this->cursos->imprimir_entrada();
    this->alunos->imprimir_entrada();
}
