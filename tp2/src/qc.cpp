#include "quicksorts.h"
#include "geradores.h"
#include <iostream>
#include <string>

void Particiona(int* vetor, int esq, int dir,
                int* i, int* j){
  int aux, pivo;
  *i = esq;
  *j = dir;
  pivo = vetor[(*i+*j)/2];
  do{
    //encontra o primeiro elemento à esquerda do pivô
    //que é maior ou igual a ele
    while (vetor[*i] < pivo)
      (*i)++;

    //encontra o primeiro elemento à direita do pivô
    //que é menor ou igual a ele
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

int escolhePivo(int* vetor, int esq, int dir, std::string varQS){
  if(varQS == "QM3"){
/*  int a, b, c;
    a = vetor[esq];
    b = vetor[(esq+dir)/2];
    c = vetor[dir];
*/
    //coloca os três pivos a pivô num vetor
    int pivos[3] = {vetor[esq],
                    vetor[(esq+dir)/2],
                    vetor[dir]};

    //ordena o vetor de pivôs
    InsertionSort(pivos, 0, 2);

    //o pivô escolhido é o do meio
    return pivos[1];

  } else if(varQS == "QPE"){
    return vetor[esq];
  } else{
    return vetor[(esq+dir)/2];
  }
}
