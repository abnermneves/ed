#include "ordenadores.h"
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

//---------------------QUICKSORT COM INSERTION----------------------//

void OrdenaQuickInsertion(int* vetor, int esq, int dir,
                          unsigned int tam, std::string varQS){
  int i, j;
  float k;
  if (varQS == "QI1"){
    k = 0.01;
  } else if(varQS == "QI5"){
    k = 0.05;
  } else{
    k = 0.1;
  }

  //particiona selecionando o pivô pela mediana de 3
  Particiona(vetor, esq, dir, &i, &j, "QM3");

  if (j > esq){
    //porcentagem representada pelo tamanho do subvetor [esq, j]
    //em relação ao vetor inteiro de tamanho tam
    float porcento = (float)(j-esq)/(float)tam;
    std::cout << "porcento: " << porcento << std::endl;
    //se a porcentagem for menor que k, ordena com insertion
    if (porcento < k){
      std::cout << "Insertion com " << porcento << "%" << std::endl;
      InsertionSort(vetor, esq, j);
    }
    else
      OrdenaQuickInsertion(vetor, esq, j, tam, varQS);
  }
  if (i < dir){
    //porcentagem representada pelo tamanho do subvetor [i, dir]
    //em relação ao vetor inteiro de tamanho tam
    float porcento = (float)(dir-i)/(float)tam;
    std::cout << "porcento: " << porcento << std::endl;
    //se a porcentagem for menor que k, ordena com insertion
    if (porcento < k){
      std::cout << "Insertion com " << porcento << "%" << std::endl;
      InsertionSort(vetor, i, dir);
    }
    else
      OrdenaQuickInsertion(vetor, i, dir, tam, varQS);
  }
}

void QuickComInsertion(int* vetor, unsigned int tam, std::string varQS){
  OrdenaQuickInsertion(vetor, 0, tam-1, tam, varQS);
}
