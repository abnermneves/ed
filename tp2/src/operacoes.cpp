#include <iostream>
#include "operacoes.h"
#include "ordenadores.h"

void imprimir(int* vetor, unsigned int tam){
  for (unsigned int i = 0; i < tam; i++){
    std::cout << vetor[i] << " ";
  }
  std::cout << std::endl;
}

bool estaOrdenado(int* vetor, unsigned int tam){
  bool ordenado = true;
  for (unsigned int i = 0; i < tam-1; i++){
    if(vetor[i] > vetor[i+1])
      ordenado = false;
  }
  return ordenado;
}

int media(unsigned int* vetor, unsigned int tam){
  int soma = 0;
  for (unsigned int i = 0; i < tam; i++)
    soma += vetor[i];
  return soma/tam;
}

int mediana(int* vetor, unsigned int tam){
  InsertionSort(vetor, 0, tam-1);
  if (tam % 2 == 0)
    return (vetor[tam/2] + vetor[(tam/2)+1]) / 2;
  else
    return vetor[tam/2];
}

int mediana(int* vetor, unsigned int tam,
            unsigned int* n_comp, unsigned int* n_mov){
  InsertionSort(vetor, 0, tam-1, n_comp, n_mov);
  if (tam % 2 == 0)
    return (vetor[tam/2] + vetor[(tam/2)+1]) / 2;
  else
    return vetor[tam/2];
}

double mediana(double* vetor, unsigned int tam){
  InsertionSort(vetor, 0, tam-1);
  if (tam % 2 == 0)
    return (vetor[tam/2] + vetor[(tam/2)+1]) / 2;
  else
    return vetor[tam/2];
}

void copia(int* v1, int* v2, unsigned int tam){
  for (unsigned int i = 0; i < tam; i++)
    v1[i] = v2[i];
}
