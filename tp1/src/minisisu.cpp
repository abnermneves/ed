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

    std::cin >> n >> m;
    std::cin.ignore();
    for (unsigned int i = 1; i <= n; i++){
        std::string nome;
        std::getline(std::cin, nome);
        unsigned int vagas = 0;
        std::cin >> vagas;
        std::cin.ignore();
        Curso* curso = new Curso(i, nome, vagas);
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
        Aluno* aluno = new Aluno(i, nome, nota, p, s);
        this->alunos->inserir(aluno);

        //insere o aluno na lista de po e so dos cursos escolhidos
        /*curso = cursos->get_objeto(p);
        curso->get_po()->inserir(aluno);
        curso = cursos->get_objeto(s);
        curso->get_so()->inserir(aluno);*/
    }
}

void MiniSisu::classificar(){
    Aluno* aluno = nullptr;
    Aluno* proximo = nullptr;
    Lista<Aluno*>* alunos = this->alunos;
    Lista<Curso*>* cursos = this->cursos;
    unsigned int n = cursos->get_tamanho();
    unsigned int m = alunos->get_tamanho();
    bool aprovado = 0;
    float notaAtual = 0;
    float notaProx = 0;

    this->ordenar_alunos();
    this->imprimir_entrada();
    std::cout << std::endl << std::endl;

    //pra entrar no for, precisa ter mais de 1 aluno
    //aqui classifica só os alunos que não empataram
    unsigned int i = 1;
    for (; i <= m; i++){
        //std::cout << "i: " << i << std::endl;
        aluno = alunos->get_objeto(i);
        if (aluno){
            notaAtual = aluno->get_nota();
        }
        proximo = alunos->get_objeto(i+1);
        if (proximo != nullptr){
            notaProx = proximo->get_nota();
        }

        //encontra alunos com a nota igual à do atual
        unsigned int j = i;
        while (proximo != nullptr && j < m && notaAtual == notaProx){
            
            aluno = proximo;
            if (aluno){
                proximo = alunos->get_objeto(j+2);
            }
            if (proximo != nullptr){
                notaProx = proximo->get_nota();
            }
            j++;
            //std::cout << "j: " << j << std::endl;
        }

        //se não tem empate
        //então classifica o aluno atual
        if (i == j){
            //std::cout << "OI CHEGUEI AQUI ALGUEM NAO EMATOU A NOTA" << std::endl;
            Curso* cp = cursos->get_objeto(aluno->get_p());
            if (cp == nullptr){
                throw std::invalid_argument("Curso inválido! 1");
            }
            bool aprovado = cp->classificar(aluno);

            if (!aprovado){
                Curso* cs = cursos->get_objeto(aluno->get_s());
                if (cs == nullptr){
                    throw std::invalid_argument("Curso inválido! 2");
                }
                aprovado = cs->classificar(aluno);
            }
            if (aluno && alunos){
                alunos->remover(aluno);
            }
            i--;
            j--;
        } else {
            //std::cout << "OI CHEGUEI AQUI ALGUEM EMpATOU SIM A NOTA" << std::endl;
            //agora, se houve empate de nota,
            //desempata e continua a partir do proximo
            this->desempatar(&i, &j);
            //i = j;
        }
        if (alunos){
            m = alunos->get_tamanho();
        }
    }

}

void MiniSisu::desempatar(unsigned int* i, unsigned int* j){
    auto alunos = this->alunos;
    auto cursos = this->cursos;

    Aluno* atual = nullptr;
    bool aprovado = 0;

    for (unsigned int k = *i; k <= *j; k++){
        //std::cout << "k:" << k << std::endl
        //         << "j: " << *j << std::endl;
        if (alunos){
            atual = alunos->get_objeto(k);
        }
        //std::cout << "oi" << std::endl;
        Curso* cp = cursos->get_objeto(atual->get_p());
        if (cp == nullptr){
            throw std::invalid_argument("Curso inválido! 3");
        }
        //std::cout << "oi2" << std::endl;
        //std::cout << aprovado << std::endl;
        //std::cout << "cp " << cp << std::endl << "p " << atual->get_p() << std::endl;
        if (cp){
            aprovado = cp->classificar(atual);
        }
        std::cout << aprovado << std::endl;
        //std::cout << "oi3" << std::endl;

        if (aprovado && alunos){
            //std::cout << "oi4" << std::endl;
            alunos->remover(atual);
            //std::cout << "oi5" << std::endl;
            //*i--;
            *j--;
            k--;
        }
    }

    for (unsigned int k = *i; k <= *j; k++){
        std::cout << "k2:" << k << std::endl
                  << "j2: " << *j << std::endl;

        Curso* cs = nullptr;
        if (alunos && cursos){
            atual = alunos->get_objeto(k);
            Curso* cs = cursos->get_objeto(atual->get_s());
        }
        if (cs == nullptr){
            throw std::invalid_argument("Curso inválido! 4");
        }
        aprovado = cs->classificar(atual);
        if (alunos){
            alunos->remover(atual);
        }
        //*i--;
        *j--;
        k--;
    }
/*
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
    */
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
