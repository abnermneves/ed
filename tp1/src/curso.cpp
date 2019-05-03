#include <iostream>
#include <iomanip>
#include "curso.h"

Curso::Curso(unsigned int id, std::string nome, unsigned int vagas){
    this->id = id;
    this->nome = nome;
    this->vagas = vagas;
    this->nota_corte = 0;
    this->classificados = new Lista<Aluno*>();
    this->espera = new Lista<Aluno*>();
    this->po = new Lista<Aluno*>();
    this->so = new Lista<Aluno*>();
}

Curso::~Curso(){
    //this->espera->~Lista();
}

std::string Curso::get_nome(){
    return this->nome;
}

unsigned int Curso::get_vagas(){
    return this->vagas;
}

unsigned int Curso::get_id(){
    return this->id;
}

void Curso::imprimir(){
    std::cout << this->nome << " "
              << std::setprecision(2) << std::fixed
              << this->nota_corte << std::endl
              << "Classificados" << std::endl;
    this->classificados->imprimir();
    std::cout << "Lista de espera" << std::endl;
    this->espera->imprimir();
    std::cout << std::endl;
}

void Curso::imprimir_entrada(){
    std::cout << this->nome << " " << this->vagas << std::endl << "po" << std::endl;
    this->po->imprimir_entrada();
    std::cout << "so" << std::endl;
    this->so->imprimir_entrada();
}

Lista<Aluno*>* Curso::get_po(){
    return this->po;
}

Lista<Aluno*>* Curso::get_so(){
    return this->so;
}

void Curso::ordenar_alunos(Lista<Aluno*>* lista){
  //a primeira é a célula cabeça
  Celula<Aluno*>* primeira = lista->get_celula(0);
  //então atual começa na segunda célula
  Celula<Aluno*>* atual = primeira->get_proxima();
  Celula<Aluno*>* anterior;
  Celula<Aluno*>* prox;
  Celula<Aluno*>* prox2;
  //tamanho é 0 se tiver só a célula cabeça
  unsigned int tamanho = lista->get_tamanho();

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

bool Curso::classificar(Aluno* aluno){
    if (this->classificados->get_tamanho() < this->vagas){
        this->classificados->inserir(aluno);
        if (this->classificados->get_tamanho() == this->vagas){
            this->nota_corte = aluno->get_nota();
        }
        return true;
    } else {
        this->espera->inserir(aluno);
        return false;
    }
}
