#include <cstdlib>
#include <ctime>

void gerarAleatorio(int* vetor, unsigned int tam){
  srand(time(NULL));
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = rand();
  }
}

void gerarOrdenadoCrescente(int* vetor, unsigned int tam){
  int max = RAND_MAX - tam;
  srand(time(NULL));
  int ale = rand() % max;
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = ale+i;
  }
}

void gerarOrdenadoDecrescente(int* vetor, unsigned int tam){
  srand(time(NULL));
  int ale = rand();
  for(unsigned int i = 0; i < tam; i++){
    vetor[i] = ale-i;
  }
}

void imprimir(int* vetor, unsigned int tam){
  for (unsigned int i = 0; i < tam; i++){
    std::cout << vetor[i] << " ";
  }
  std::cout << std::endl;
}
