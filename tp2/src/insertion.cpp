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
