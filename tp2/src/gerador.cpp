#include <cstdlib>
#include <ctime>

void gerarAleatorio(int* vetor, unsigned int tam){
  srand(time(NULL));
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = rand();
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

void imprimir(int* vetor, unsigned int tam){
  for (unsigned int i = 0; i < tam; i++){
    std::cout << vetor[i] << " ";
  }
  std::cout << std::endl;
}
