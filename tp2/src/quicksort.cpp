#include "ordenadores.h"
#include "geradores.h"
#include "operacoes.h"
#include "pilha.h"
#include <iostream>
#include <string>

//escolhe o pivô de acordo com a variação escolhida
int escolhePivo(int* vetor, int esq, int dir, std::string varQS,
                unsigned int* n_comp, unsigned int* n_mov){
  if(varQS == "QM3"){
    //coloca os três candidatos a pivô num vetor
    int pivos[3] = {vetor[esq],
                    vetor[(esq+dir)/2],
                    vetor[dir]};
    //em partições com dois elementos,
    //serão feitas duas cópias do primeiro,
    //logo, ele sempre será o escolhido para pivô nesse caso
    return mediana(pivos, 3, n_comp, n_mov);

  } else if(varQS == "QPE"){
      return vetor[esq];
  } else{
      return vetor[(esq+dir)/2];
  }
}

//troca os elementos de modo que os menores que o pivô
//fiquem à esquerda e os maiores, à direita
void Particiona(int* vetor, int esq, int dir,
                int* i, int* j, std::string varQS,
                unsigned int* n_comp, unsigned int* n_mov){
  int aux, pivo;
  *i = esq;
  *j = dir;
  pivo = escolhePivo(vetor, esq, dir, varQS, n_comp, n_mov);
  //std::cout << "pivo: " << pivo << std::endl;
  do{
    //encontra o primeiro elemento à esquerda do pivô
    //que é maior ou igual a ele
    while (vetor[*i] < pivo){
      (*n_comp)++;
      (*i)++;
    }
    (*n_comp)++;

    //encontra o primeiro elemento à direita do pivô
    //que é menor ou igual a ele
    while (vetor[*j] > pivo){
      (*n_comp)++;
      (*j)--;
    }
    (*n_comp)++;

    //troca os dois de lugares se i e j
    //ainda não tiverem passado pela partição inteira
    if (*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*n_mov)++;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
  //repete enquanto i e j ainda não tiverem
  //passado pela partição inteira
}

void Ordena(int* vetor, int esq, int dir, std::string varQS,
               unsigned int* n_comp, unsigned int* n_mov){
  int i, j;
  Particiona(vetor, esq, dir, &i, &j, varQS, n_comp, n_mov);

  //ordena novamente as partições resultantes
  //se elas ainda tiverem elementos
  if (j > esq)
    Ordena(vetor, esq, j, varQS, n_comp, n_mov);
  if (i < dir)
    Ordena(vetor, i, dir, varQS, n_comp, n_mov);
}

//-------------- QUICKSORT CLÁSSICO, PE e M3 -------------------//

void QuickSort(int* vetor, unsigned int tam, std::string varQS,
               unsigned int* n_comp, unsigned int* n_mov){
  Ordena(vetor, 0, tam-1, varQS, n_comp, n_mov);
}

//---------------------QUICKSORT COM INSERTION----------------------//

void OrdenaQuickInsertion(int* vetor, int esq, int dir,
                          unsigned int tam, std::string varQS,
                          unsigned int* n_comp, unsigned int* n_mov){
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
  Particiona(vetor, esq, dir, &i, &j, "QM3", n_comp, n_mov);

  if (j > esq){
    //porcentagem representada pelo tamanho do subvetor [esq, j]
    //em relação ao vetor inteiro de tamanho tam
    float porcento = (float)(j-esq)/(float)tam;

    //se a porcentagem for menor que k, ordena com insertion
    if (porcento < k){
      InsertionSort(vetor, esq, j, n_comp, n_mov);
    } else{
        OrdenaQuickInsertion(vetor, esq, j, tam, varQS, n_comp, n_mov);
    }
  }
  if (i < dir){
    //porcentagem representada pelo tamanho do subvetor [i, dir]
    //em relação ao vetor inteiro de tamanho tam
    float porcento = (float)(dir-i)/(float)tam;

    //se a porcentagem for menor que k, ordena com insertion
    if (porcento < k){
      InsertionSort(vetor, i, dir, n_comp, n_mov);
    } else{
        OrdenaQuickInsertion(vetor, i, dir, tam, varQS, n_comp, n_mov);
    }
  }
}

void QuickComInsertion(int* vetor, unsigned int tam, std::string varQS,
                       unsigned int* n_comp, unsigned int* n_mov){
  OrdenaQuickInsertion(vetor, 0, tam-1, tam, varQS, n_comp, n_mov);
}

//--------------------QUICKSORT NÃO RECURSIVO-------------------//

void QuickNaoRecursivo(int* vetor, unsigned int tam,
                       unsigned int* n_comp, unsigned int* n_mov){
  Pilha pilha = Pilha();
  int esq, dir, i, j;
  esq = 0;
  dir = tam-1;
  pilha.empilha(esq, dir);

  do {
    //verifica se ainda não percorreu o (sub)vetor inteiro
    if (dir > esq){
      Particiona(vetor, esq, dir, &i, &j, "QC", n_comp, n_mov);

      //empilha a partição que for maior e particiona a menor
      if((j-esq) > (dir-i)){
        pilha.empilha(esq, j);
        esq = i;
      } else {
          pilha.empilha(i, dir);
          dir = j;
      }
    } else {
        //se já percorreu inteiro,
        //então começa de novo na próxima partição
        pilha.desempilha(&esq, &dir);
    }
  } while(!pilha.vazia());
}
