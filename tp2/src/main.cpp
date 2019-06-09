#include <iostream>
#include <string>
#include "ordenadores.h"
#include "geradores.h"
#include "pilha.h"

#define N_TESTES 20

using namespace std;

int main(int argc, char* argv[]){
  string varQS = argv[1];
  string tipoVetor = argv[2];
  unsigned int tam = stoi(argv[3]);
  unsigned int n_comp[N_TESTES] = {};
  unsigned int n_mov[N_TESTES] = {};
  unsigned int tempo[N_TESTES] = {};
  int vetor[tam] = {};
  //int vetor[tam] = {1, 3, 8, 5, 7, 4};
  bool exibir = false;

  if (argc == 5){
    string p = argv[4];
    if(p == "-p")
      exibir = true;
  }


  //std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;

  if(varQS == "QC" || varQS == "QM3" || varQS == "QPE"){

    for (unsigned int i = 0; i < N_TESTES; i++){
      gerarVetor(vetor, tam, tipoVetor);
      imprimir(vetor, tam);
      QuickSort(vetor, tam, varQS, &(n_comp[i]), &(n_mov[i]));
      //imprimir(vetor, tam);
      //std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
    }
    int media_comp = media(n_comp, N_TESTES);
    int media_mov = media(n_mov, N_TESTES);
    std::cout << varQS << " " << tipoVetor << " " << tam << " "
              << media_comp << " " << media_mov << std::endl;

  } else if(varQS == "QI1" || varQS == "QI5" || varQS == "QI10"){

      for (unsigned int i = 0; i < N_TESTES; i++){
        gerarVetor(vetor, tam, tipoVetor);
        QuickComInsertion(vetor, tam, varQS, &(n_comp[i]), &(n_mov[i]));
        imprimir(vetor, tam);
        std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
      }
      int media_comp = media(n_comp, N_TESTES);
      int media_mov = media(n_mov, N_TESTES);
      std::cout << varQS << " " << tipoVetor << " " << tam << " "
                << media_comp << " " << media_mov << std::endl;

  } else if(varQS == "QNR"){

      for (unsigned int i = 0; i < N_TESTES; i++){
        gerarVetor(vetor, tam, tipoVetor);
        QuickNaoRecursivo(vetor, tam, &(n_comp[i]), &(n_mov[i]));
        imprimir(vetor, tam);
        std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;
      }
      int media_comp = media(n_comp, N_TESTES);
      int media_mov = media(n_mov, N_TESTES);
      std::cout << varQS << " " << tipoVetor << " " << tam << " "
                << media_comp << " " << media_mov << std::endl;

  } else if(varQS == "IS"){

      gerarVetor(vetor, tam, tipoVetor);
      InsertionSort(vetor, 0, tam-1);
      imprimir(vetor, tam);
      std::cout << "Ordenado: " << estaOrdenado(vetor, tam) << std::endl;

  } else{

      cout << "QuickSort inválido!" << endl;

  }

  return 0;
}
