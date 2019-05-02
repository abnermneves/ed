#include <iostream>
#include "lista.h"

template class Lista<Curso*>;
template class Lista<Aluno*>;

template <typename T>
Lista<T>::Lista(){
    Celula<T>* cabeca = new Celula<T>();
    this->primeira = cabeca;
    this->ultima = cabeca;
    this->tamanho = 0;
}

template <typename T>
Lista<T>::~Lista(){

}

template <typename T>
void Lista<T>::inserir(T objeto){
    Celula<T>* c = new Celula<T>(objeto);
    c->set_anterior(this->ultima);
    this->ultima->set_proxima(c);
    this->ultima = c;
    this->tamanho++;
    c->set_posicao(this->get_tamanho());
}

template <typename T>
void Lista<T>::imprimir(){
    Celula<T>* atual = this->primeira->get_proxima();
    while (atual != nullptr){
        atual->get_objeto()->imprimir();
        atual = atual->get_proxima();
    }
}

template <typename T>
void Lista<T>::imprimir_entrada(){
    Celula<T>* atual = this->primeira->get_proxima();
    while (atual != nullptr){
        atual->get_objeto()->imprimir_entrada();
        atual = atual->get_proxima();
    }
}

template <typename T>
void Lista<T>::esvaziar(){
    this->ultima = this->primeira;
    this->tamanho = 0;
}

template <typename T>
bool Lista<T>::vazia(){
    return this->primeira == this->ultima;
}

template <typename T>
unsigned int Lista<T>::get_tamanho(){
    return this->tamanho;
}

template <typename T>
Celula<T>* Lista<T>::get_celula(unsigned int posicao){
    Celula<T>* atual = this->primeira;
    while (atual->get_posicao() != posicao){
        atual = atual->get_proxima();
    }
    return atual;
}

template <typename T>
T Lista<T>::get_objeto(unsigned int posicao){
    return this->get_celula(posicao)->get_objeto();
}
