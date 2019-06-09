#ifndef GERADORES_H
#define GERADORES_H

#include <string>

void gerarAleatorio(int* vetor, unsigned int tam, unsigned int i);
void gerarOrdenadoCrescente(int* vetor, unsigned int tam);
void gerarOrdenadoDecrescente(int* vetor, unsigned int tam);
void gerarVetor(int* vetor, unsigned int tam, std::string tipoVetor, unsigned int i);

#endif
