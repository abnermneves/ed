#include <iostream>
#include <string>
#include "quicksorts.h"
#include "geradores.h"

using namespace std;

int main(int argc, char* argv[]){
  string varQS = argv[1];
  string tipoVetor = argv[2];
  unsigned int tam = stoi(argv[3]);
  int vetor[tam] = {};
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

  if(varQS == "QC"){
      QC(vetor, tam);
      imprimir(vetor, tam);
  } else if(varQS == "QM3"){
      cout << "QM3" << endl;
  } else if(varQS == "QPE"){
      cout << "QPE" << endl;
  } else if(varQS == "QI1"){

  } else if(varQS == "QI5"){

  } else if(varQS == "QI10"){

  } else if(varQS == "QNR"){

  } else{
      cout << "QuickSort inválido!" << endl;
  }

  return 0;
}
