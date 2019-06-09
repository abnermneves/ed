#ifndef OPERACOES_H
#define OPERACOES_H

void imprimir(int* vetor, unsigned int tam);
void copia(int* v1, int* v2, unsigned int tam);
bool estaOrdenado(int* vetor, unsigned int tam);
int media(unsigned int* vetor, unsigned int tam);
int mediana(int* vetor, unsigned int tam);
int mediana(int* vetor, unsigned int tam,
            unsigned int* n_comp, unsigned int* n_mov);
double mediana(double* vetor, unsigned int tam);

#endif
