#include <iostream>
#include <string>
#include "ordenadores.h"
#include "geradores.h"
#include "pilha.h"

using namespace std;

int main(int argc, char* argv[]){
  string varQS = argv[1];
  string tipoVetor = argv[2];
  unsigned int tam = stoi(argv[3]);
  int vetor[tam] = {};
  //int vetor[tam] = {1, 3, 8, 5, 7, 4};
  bool exibir = false;

  if (argc == 5){
    string p = argv[4];
    if(p == "-p")
      exibir = true;
  }

  if(tipoVetor == "Ale"){
    gerarAleatorio(vetor, tam);
  } else if (tipoVetor == "OrdC"){
    gerarOrdenadoCrescente(vetor, tam);
  } else if (tipoVetor == "OrdD"){
    gerarOrdenadoDecrescente(vetor, tam);
  } else {
    cout << "Tipo de vetor inválido!" << endl;
  }
  imprimir(vetor, tam);
  //std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
  if(varQS == "QC" || varQS == "QM3" || varQS == "QPE"){
      QuickSort(vetor, tam, varQS);
      imprimir(vetor, tam);
      std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
  } else if(varQS == "QI1" || varQS == "QI5" || varQS == "QI10"){
      QuickComInsertion(vetor, tam, varQS);
      imprimir(vetor, tam);
      std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
  } else if(varQS == "QNR"){

  } else if(varQS == "IS"){
    InsertionSort(vetor, 0, tam-1);
    imprimir(vetor, tam);
    std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
  } else{
      cout << "QuickSort inválido!" << endl;
  }

  return 0;
}
