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
    Curso* curso;
    Curso* cp;
    Curso* cs;
    Aluno* aluno;
    Aluno* proximo;
    auto alunos = this->alunos;
    auto cursos = this->cursos;
    unsigned int n = cursos->get_tamanho();
    unsigned int m = alunos->get_tamanho();
    bool aprovado;
    float notaAtual;
    float notaProx;

    this->ordenar_alunos();
    //this->imprimir_entrada();

    //pra entrar no for, precisa ter mais de 1 aluno
    //aqui classifica só os alunos que não empataram
    for (unsigned int i = 1; i < m; i++){
        aluno = alunos->get_objeto(i);
        notaAtual = aluno->get_nota();
        proximo = alunos->get_objeto(i+1);
        if (proximo){
            notaProx = proximo->get_nota();
        }

        //encontra alunos com a nota igual
        unsigned int j = i;
        while (proximo != nullptr && j < m && notaAtual == notaProx){
            aluno = proximo;
            proximo = alunos->get_objeto(j+2);
            if (proximo){
                notaProx = proximo->get_nota();
            }
            j++;
        }

        if (i == j){
            std::cout << "OI CHEGUEI AQUI ALGUEM NAO EMATOU A NOTA" << std::endl;
            cp = cursos->get_objeto(aluno->get_p());
            aprovado = cp->classificar(aluno);

            cs = cursos->get_objeto(aluno->get_s());
            if (aprovado){
                cs->get_so()->remover(aluno);
            } else {
                cs->classificar(aluno);
            }

            alunos->remover(aluno);
            m--;
        } else {
            std::cout << "OI CHEGUEI AQUI ALGUEM EMpATOU SIM A NOTA" << std::endl;
            //agora, se houve empate de nota,
            //desempata e continua a partir do proximo

            i = j;
        }
    }

    for (unsigned int i = 1; i <= n ; i++){
        curso = this->cursos->get_objeto(i);
        auto po = curso->get_po();
        curso->ordenar_alunos(po);
        m = po->get_tamanho();

        for (unsigned int i = 1; i <= m; i++){
            aluno = po->get_objeto(i);
            aprovado = curso->classificar(aluno);

            //se o aluno foi aprovado na primeira opção
            //então ele não vai concorrer na segunda
            if (aprovado){
                unsigned int s = aluno->get_s();
                auto cs = cursos->get_objeto(s);
                if (cs != nullptr){
                    cs->get_so()->remover(i);
                }
            }
        }
    }

    for (unsigned int i = 1; i <= n ; i++){
        curso = this->cursos->get_objeto(i);
        auto so = curso->get_so();
        curso->ordenar_alunos(so);
        m = so->get_tamanho();

        for (unsigned int i = 1; i <= m; i++){
            aluno = so->get_objeto(i);
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
}

void MiniSisu::imprimir_entrada(){
    this->cursos->imprimir_entrada();
    this->alunos->imprimir_entrada();
}

void MiniSisu::ordenar_alunos(){
    Curso* aux = new Curso(1, "Auxiliar pra ordenação pq fui burro", 0);
    aux->ordenar_alunos(this->alunos);
}
