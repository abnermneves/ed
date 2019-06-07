#include "quicksorts.h"
#include "geradores.h"
#include <iostream>
#include <string>

int escolhePivo(int* vetor, int esq, int dir, std::string varQS){
  if(varQS == "QM3"){
    //coloca os três candidatos a pivô num vetor
    int pivos[3] = {vetor[esq],
                    vetor[(esq+dir)/2],
                    vetor[dir]};

    //se houver apenas dois candidatos a pivô,
    //serão feitas duas cópias do primeiro,
    //logo, ele será o escolhido

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

void Particiona(int* vetor, int esq, int dir,
                int* i, int* j, std::string varQS){
  int aux, pivo;
  *i = esq;
  *j = dir;
  pivo = escolhePivo(vetor, esq, dir, varQS);
  //std::cout << "pivo: " << pivo << std::endl;
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

void Ordena(int* vetor, int esq, int dir, std::string varQS){
  int i, j;
  Particiona(vetor, esq, dir, &i, &j, varQS);
  if (j > esq)
    Ordena(vetor, esq, j, varQS);
  if (i < dir)
    Ordena(vetor, i, dir, varQS);
}

void QuickSort(int* vetor, unsigned int tam, std::string varQS){
  Ordena(vetor, 0, tam-1, varQS);
}
