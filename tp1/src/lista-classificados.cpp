#include "lista-classificados.h"
#include "aluno.h"

ListaClassificados::ListaClassificados(unsigned int maxtam){
    this->maxtam = maxtam;
    this->primeiro = 0;
    this->ultimo = 0;
    this->lista = new Aluno[maxtam];
}

ListaClassificados::~ListaClassificados(){

}

void ListaClassificados::inserir(Aluno* aluno){

}

void ListaClassificados::imprimir(){

}

void ListaClassificados::esvaziar(){

}

bool ListaClassificados::vazia(){
    
}

Aluno* ListaClassificados::retirar(unsigned int id){

}
