#include "lista-sequencial.h"
#include "aluno.h"
#include <iostream>
#include <iomanip>

ListaSequencial::ListaSequencial(unsigned int maxtam){
    this->maxtam = maxtam;
    this->primeiro = 0;
    this->ultimo = 0;
    this->lista = new Aluno[maxtam];
}

ListaSequencial::~ListaSequencial(){

}

void ListaSequencial::inserir(Aluno* aluno){
    if (this->cheia()){
        std::cout << "Lista cheia!" << std::endl;
    } else {
        this->lista[ultimo] = aluno;
        this->ultimo++;
    }
}

void ListaSequencial::imprimir(){
    for (unsigned int i = 0; i < this->maxtam; i++){
        std::cout << this->lista[i].get_nome() << " "
                  << std::setprecision(2)
                  << this->lista[i].get_nota()
                  << std::endl;
    }
}

void ListaSequencial::esvaziar(){
    
}

bool ListaSequencial::vazia(){
    return this->primeiro == this->ultimo;
}

bool ListaSequencial::cheia(){
    return this->ultimo == maxtam;
}

Aluno* ListaSequencial::retirar(unsigned int id){

}

unsigned int ListaSequencial::get_maxtam(){
    return this->maxtam;
}
