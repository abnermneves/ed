#include <iostream>
#include <string>
#include <chrono>
#include "ordenadores.h"
#include "geradores.h"
#include "operacoes.h"
#include "pilha.h"

#define N_TESTES 20

int main(int argc, char* argv[]){
  std::string varQS = argv[1];
  std::string tipoVetor = argv[2];
  unsigned int tam = std::stoi(argv[3]);
  unsigned int n_comp[N_TESTES] = {};
  unsigned int n_mov[N_TESTES] = {};
  double tempo[N_TESTES] = {};
  std::chrono::high_resolution_clock::time_point start, end;
  int vetor[tam] = {};

  //matriz com N_TESTES linhas e tam colunas
  //para armazenar os vetores de teste
  unsigned int a = N_TESTES;
  unsigned int b = tam;
  int vetores[a][b] = {};

  bool exibir = false;
  if (argc == 5){
    std::string p = argv[4];
    if(p == "-p")
      exibir = true;
  }

  if(varQS == "QC" || varQS == "QM3" || varQS == "QPE"){
    for (unsigned int i = 0; i < N_TESTES; i++){
      gerarVetor(vetores[i], tam, tipoVetor, i);
      copia(vetor, vetores[i], tam);

      //marca o horário antes e depois de ordenar
      start = std::chrono::high_resolution_clock::now();
      QuickSort(vetor, tam, varQS, &(n_comp[i]), &(n_mov[i]));
      end = std::chrono::high_resolution_clock::now();

      //calcula a diferença do tempo de fim e início
      std::chrono::duration<double, std::micro> elapsed_time
      = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
      tempo[i] = elapsed_time.count();

    }

  } else if(varQS == "QI1" || varQS == "QI5" || varQS == "QI10"){
      for (unsigned int i = 0; i < N_TESTES; i++){
        gerarVetor(vetores[i], tam, tipoVetor, i);
        copia(vetor, vetores[i], tam);

        //marca o horário antes e depois de ordenar
        start = std::chrono::high_resolution_clock::now();
        QuickComInsertion(vetor, tam, varQS, &(n_comp[i]), &(n_mov[i]));
        end = std::chrono::high_resolution_clock::now();

        //calcula a diferença do tempo de fim e início
        std::chrono::duration<double, std::micro> elapsed_time
        = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
        tempo[i] = elapsed_time.count();

      }

  } else if(varQS == "QNR"){
      for (unsigned int i = 0; i < N_TESTES; i++){
        gerarVetor(vetores[i], tam, tipoVetor, i);
        copia(vetor, vetores[i], tam);

        //marca o horário antes e depois de ordenar
        start = std::chrono::high_resolution_clock::now();
        QuickNaoRecursivo(vetor, tam, &(n_comp[i]), &(n_mov[i]));
        end = std::chrono::high_resolution_clock::now();

        //calcula a diferença do tempo de fim e início
        std::chrono::duration<double, std::micro> elapsed_time
        = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
        tempo[i] = elapsed_time.count();

      }

  } else{
      std::cout << "QuickSort inválido!" << std::endl;
  }

  //calcula as médias e mediana de
  //comparações, movimentações e tempo de execução
  int media_comp = media(n_comp, N_TESTES);
  int media_mov = media(n_mov, N_TESTES);
  int mediana_tempo = mediana(tempo, N_TESTES);

  std::cout << varQS << " " << tipoVetor << " " << tam << " "
            << media_comp << " " << media_mov << " " << mediana_tempo
            << std::endl;

  if(exibir){
    for (unsigned int i = 0; i < N_TESTES; i++){
      imprimir(vetores[i], tam);
    }
  }
  return 0;
}
