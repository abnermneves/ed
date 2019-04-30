#include <iostream>
#include <string>
#include "minisisu.h"
#include "celula.h"

MiniSisu::MiniSisu(){
    this->cursos = new Lista<Curso*>();
    this->alunos = new Lista<Aluno*>();
}

void MiniSisu::ler(){
    unsigned int n, m, vagas, nota, p, s;
    std::string nome;

    std::cin >> n >> m;
    for (unsigned int i = 0; i < n; i++){
        std::cin >> nome;
        std::cin >> vagas;
        Curso* curso = new Curso(i, nome, vagas);
        this->cursos->inserir(curso);
    }
}

void MiniSisu::ordenar_alunos(){
    //a primeira é a célula cabeça
    Celula<Aluno*>* primeira = this->alunos->get_celula(0);
    //então atual começa na segunda célula
    Celula<Aluno*>* atual = primeira->get_proxima();
    Celula<Aluno*>* anterior = atual->get_anterior();
    Celula<Aluno*>* prox = atual->get_proxima();
    Celula<Aluno*>* prox2 = prox;
    //tamanho é 0 se tiver só a célula cabeça
    unsigned int tamanho = this->alunos->get_tamanho();

    if (tamanho > 1){
      //se tem mais de 1 celula com aluno, entao começa da segunda
      atual = atual->get_proxima();

      float atualNota, anteriorNota;

        while (atual != nullptr){
            anterior = atual->get_anterior();
            prox = atual->get_proxima();
            prox2 = prox;
            atualNota = atual->get_objeto()->get_nota();
            anteriorNota = anterior->get_objeto()->get_nota();

            while (anterior != primeira && atualNota > anteriorNota){
                //troca a celula atual com a anterior
                atual->trocar(anterior);
                //atualiza a anterior e proxima
                anterior = atual->get_anterior();
                prox = atual->get_proxima();
                if (anterior != primeira){
                    anteriorNota = anterior->get_objeto()->get_nota();
                }
            }
            atual = prox2;
        }
    }
}

Lista<Curso*>* MiniSisu::get_lista_cursos(){
    return this->cursos;
}

Lista<Aluno*>* MiniSisu::get_lista_alunos(){
    return this->alunos;
}
