#include "quicksorts.h"
#include "geradores.h"
#include <iostream>

void Particiona(int* vetor, unsigned int esq, unsigned int dir,
                unsigned int* i, unsigned int* j){
  int aux, pivo;
  *i = esq;
  *j = dir;
  unsigned int indpivo = (*i+*j)/2;
  //std::cout << "pivo: " << indpivo << std::endl;
  pivo = vetor[indpivo];

  do{
    while (vetor[*i] < pivo)
      (*i)++;
    while (vetor[*j] > pivo)
      (*j)--;
    if (*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int* vetor, unsigned int esq, unsigned int dir){
  unsigned int i, j;
  Particiona(vetor, esq, dir, &i, &j);
imprimir(vetor, dir);
  if (j > esq)
    Ordena(vetor, esq, j);
  imprimir(vetor, dir);
  if (i < dir)
    Ordena(vetor, i, dir);
  imprimir(vetor, dir);
}

void QC(int* vetor, unsigned int tam){
  Ordena(vetor, 0, tam-1);
}

//acho que na linha 15 é só <
