#include "ordenadores.h"

void InsertionSort(int* vetor, int esq, int dir){
  int i, j, aux;
  for (i = esq+1; i <= dir; i++){
    aux = vetor[i];
    for (j = i-1; (j >= 0) && (aux < vetor[j]); j--){
      vetor[j+1] = vetor[j];
    }
    vetor[j+1] = aux;
  }
}

void InsertionSort(int* vetor, int esq, int dir,
                   unsigned int* n_comp, unsigned int* n_mov){
  int i, j, aux;
  for (i = esq+1; i <= dir; i++){
    aux = vetor[i];
    for (j = i-1; (j >= 0) && (aux < vetor[j]); j--){
      vetor[j+1] = vetor[j];
      (*n_comp)++;
      (*n_mov)++;
    }
    (*n_comp)++; //conta a comparação que faz sair do loop
    vetor[j+1] = aux;
  }
}

void InsertionSort(double* vetor, int esq, int dir){
  int i, j;
  double aux;
  for (i = esq+1; i <= dir; i++){
    aux = vetor[i];
    for (j = i-1; (j >= 0) && (aux < vetor[j]); j--){
      vetor[j+1] = vetor[j];
    }
    vetor[j+1] = aux;
  }
}
