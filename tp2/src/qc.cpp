#include "quicksorts.h"
#include "geradores.h"
#include <iostream>

void Particiona(int* vetor, int esq, int dir,
                int* i, int* j){
  int aux, pivo;
  *i = esq;
  *j = dir;
  pivo = vetor[(*i+*j)/2];
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

void Ordena(int* vetor, int esq, int dir){
  int i, j;
  Particiona(vetor, esq, dir, &i, &j);
  if (j > esq)
    Ordena(vetor, esq, j);
  if (i < dir)
    Ordena(vetor, i, dir);
}

void QC(int* vetor, unsigned int tam){
  Ordena(vetor, 0, tam-1);
}
