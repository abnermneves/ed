#include <iostream>
#include <string>
#include "minisisu.h"
#include "celula.h"

MiniSisu::MiniSisu(){
    this->cursos = new Lista<Curso*>();
    this->alunos = new Lista<Aluno*>();
}

MiniSisu::~MiniSisu(){
    this->cursos->~Lista();
    this->alunos->~Lista();
}

void MiniSisu::ler(){
    unsigned int n = 0, m = 0;
    Curso* curso = nullptr;
    Aluno* aluno = nullptr;

    std::cin >> n >> m;
    std::cin.ignore();
    for (unsigned int i = 1; i <= n; i++){
        std::string nome;
        std::getline(std::cin, nome);
        unsigned int vagas = 0;
        std::cin >> vagas;
        std::cin.ignore();
        curso = new Curso(i, nome, vagas);
        this->cursos->inserir(curso);
    }

    Lista<Curso*>* cursos = this->get_lista_cursos();

    for (unsigned int i = 1; i <= m; i++){
        std::string nome;
        std::getline(std::cin, nome);
        float nota = 0;
        unsigned int p = 0, s = 0;
        std::cin >> nota >> p >> s;
        std::cin.ignore();

        //precisa aumentar 1 porque fiz a lista baseada
        //no fato de que a celula cabeça tem indice 0
        p++;
        s++;
        aluno = new Aluno(i, nome, nota, p, s);
        this->alunos->inserir(aluno);
    }
}

void MiniSisu::classificar(){
    Curso* curso = nullptr;
    Curso* cp = nullptr;
    Curso* cs = nullptr;
    Aluno* aluno = nullptr;
    Aluno* proximo = nullptr;
    auto alunos = this->alunos;
    auto cursos = this->cursos;
    unsigned int n = cursos->get_tamanho();
    unsigned int m = alunos->get_tamanho();
    bool aprovado = 0;
    float notaAtual = 0;
    float notaProx = 0;

    this->ordenar_alunos();
    //this->imprimir_entrada();

    //pra entrar no for, precisa ter mais de 1 aluno
    //aqui classifica só os alunos que não empataram
    for (unsigned int i = 1; i <= m; i++){
        aluno = alunos->get_objeto(i);
        notaAtual = aluno->get_nota();
        proximo = alunos->get_objeto(i+1);
        if (proximo != nullptr){
            notaProx = proximo->get_nota();
        }

        //encontra alunos com a nota igual à do atual
        unsigned int j = i;
        while (proximo != nullptr && j < m && notaAtual == notaProx){
            
            aluno = proximo;
            proximo = alunos->get_objeto(j+2);
            if (proximo != nullptr){
                notaProx = proximo->get_nota();
            }
            j++;
        }

        //se não tem empate
        //então classifica o aluno atual
        if (i == j){
            cp = cursos->get_objeto(aluno->get_p());
            aprovado = cp->classificar(aluno);

            
            if (!aprovado){
                cs = cursos->get_objeto(aluno->get_s());
                aprovado = cs->classificar(aluno);
            }

            alunos->remover(aluno);
            i--;
            j--;
        } else {
            //agora, se houve empate de nota,
            //desempata e continua a partir do proximo
            this->desempatar(&i, &j);
        }
        m = alunos->get_tamanho();
    }

}

void MiniSisu::desempatar(unsigned int* i, unsigned int* j){
    auto alunos = this->alunos;
    auto cursos = this->cursos;

    Aluno* atual = nullptr;
    Curso* cp = nullptr;
    Curso* cs = nullptr;
    bool aprovado;

    for (unsigned int k = *i; k <= *j; k++){
        atual = alunos->get_objeto(k);
        if (atual){
            cp = cursos->get_objeto(atual->get_p());
            aprovado = cp->classificar(atual);

            if (aprovado){
                alunos->remover(atual);
                //*i--;
                *j--;
                k--;
            }
        }
    }

    for (unsigned int k = *i; k <= *j; k++){
        atual = alunos->get_objeto(k);
        cs = cursos->get_objeto(atual->get_s());
        aprovado = cs->classificar(atual);
        alunos->remover(atual);
        //*i--;
        *j--;
        k--;
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
}

void MiniSisu::imprimir_entrada(){
    this->cursos->imprimir_entrada();
    this->alunos->imprimir_entrada();
}

void MiniSisu::ordenar_alunos(){
    //a primeira é a célula cabeça
    Celula<Aluno*>* primeira = this->alunos->get_celula(0);
    //então atual começa na segunda célula
    Celula<Aluno*>* atual = primeira->get_proxima();
    Celula<Aluno*>* anterior = nullptr;
    Celula<Aluno*>* prox = nullptr;
    Celula<Aluno*>* prox2 = nullptr;
    //tamanho é 0 se tiver só a célula cabeça
    unsigned int tamanho = this->alunos->get_tamanho();

    if (tamanho > 1){
    //se tem mais de 1 celula com aluno, entao começa da segunda
    atual = atual->get_proxima();
    anterior = atual->get_anterior();
    prox = atual->get_proxima();
    prox2 = prox;

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
