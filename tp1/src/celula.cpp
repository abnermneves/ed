#include "celula.h"
#include "aluno.h"
#include "curso.h"

template class Celula<Aluno*>;
template class Celula<Curso*>;

template <typename T>
Celula<T>::Celula(){
    this->objeto = nullptr;
    this->proxima = nullptr;
    this->anterior = nullptr;
    this->posicao = 0;
}

template <typename T>
Celula<T>::Celula(T objeto){
    this->objeto = objeto;
    this->proxima = nullptr;
    this->anterior = nullptr;
    this->posicao = 0;
}

template <typename T>
Celula<T>::~Celula(){

}

template <typename T>
T Celula<T>::get_objeto(){
    return this->objeto;
}

template <typename T>
Celula<T>* Celula<T>::get_proxima(){
    return this->proxima;
}

template <typename T>
Celula<T>* Celula<T>::get_anterior(){
    return this->anterior;
}

template <typename T>
unsigned int Celula<T>::get_posicao(){
    return this->posicao;
}

template <typename T>
void Celula<T>::set_objeto(T objeto){
    this->objeto = objeto;
}

template <typename T>
void Celula<T>::set_proxima(Celula<T>* celula){
    this->proxima = celula;
}

template <typename T>
void Celula<T>::set_anterior(Celula<T>* celula){
    this->anterior = celula;
}

template <typename T>
void Celula<T>::set_posicao(unsigned int posicao){
    this->posicao = posicao;
}

template <typename T>
void Celula<T>::trocar(Celula<T>* anterior){
  Celula<T>* posterior = this->get_proxima();
  Celula<T>* trasAnterior = anterior->get_anterior();

  anterior->set_proxima(posterior);

  if (posterior != nullptr){
      posterior->set_anterior(anterior);
  }
  this->set_proxima(anterior);
  this->set_anterior(trasAnterior);
  if (trasAnterior != nullptr){
      trasAnterior->set_proxima(this);
  }
  anterior->set_anterior(this);

  //thisiza as posicoes
  unsigned int pos = anterior->get_posicao();
  anterior->set_posicao(this->get_posicao());
  this->set_posicao(pos);
}
