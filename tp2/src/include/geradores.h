#ifndef GERADORES_H
#define GERADORES_H

#include <string>

void gerarAleatorio(int* vetor, unsigned int tam);
void gerarAleatorioEntre(int* vetor, unsigned int tam, int a, int b);
void gerarOrdenadoCrescente(int* vetor, unsigned int tam);
void gerarOrdenadoDecrescente(int* vetor, unsigned int tam);
void gerarVetor(int* vetor, unsigned int tam, std::string tipoVetor);
void imprimir(int* vetor, unsigned int tam);
bool estaOrdenado(int* vetor, unsigned int tam);
int media(unsigned int* vetor, unsigned int tam);

#endif
