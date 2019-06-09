#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "geradores.h"

void gerarAleatorio(int* vetor, unsigned int tam){
  srand(time(NULL));
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = rand() % tam;
  }
}

void gerarAleatorioEntre(int* vetor, unsigned int tam, int a, int b){
  srand(time(NULL));
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = (rand() % b) + a;
  }
}

void gerarOrdenadoCrescente(int* vetor, unsigned int tam){
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = i+1;
  }
}

void gerarOrdenadoDecrescente(int* vetor, unsigned int tam){
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = tam-i;
  }
}

void gerarVetor(int* vetor, unsigned int tam, std::string tipoVetor){
  if(tipoVetor == "Ale"){
    gerarAleatorio(vetor, tam);
  } else if (tipoVetor == "OrdC"){
      gerarOrdenadoCrescente(vetor, tam);
  } else if (tipoVetor == "OrdD"){
      gerarOrdenadoDecrescente(vetor, tam);
  }
}
