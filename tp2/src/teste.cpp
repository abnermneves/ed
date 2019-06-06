#include <iostream>
#include <string>
#include "gerador.cpp"
#include "qc.cpp"

using namespace std;

int main(int argc, char* argv[]){
  string tama = argv[1];
  unsigned int tam = stoi(argv[1]);
  int vetor[tam] = {};
  gerarAleatorioEntre(vetor, tam, 1, 100);
  imprimir(vetor, tam);
  unsigned int i = 0;
  unsigned int j = tam-1;
  Ordena(vetor, 0, tam-1);
  imprimir(vetor, tam);
  return 0;
}
