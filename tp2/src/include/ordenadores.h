#ifndef ORDENADORES_H
#define ORDENADORES_H

#include <string>

void QuickSort(int* vetor, unsigned int tam, std::string varQS,
               unsigned int* n_comp, unsigned int* n_mov);
void InsertionSort(int* vetor, int esq, int dir);
void InsertionSort(double* vetor, int esq, int dir);
void QuickComInsertion(int* vetor, unsigned int tam, std::string varQS,
                       unsigned int* n_comp, unsigned int* n_mov);
void QuickNaoRecursivo(int* vetor, unsigned int tam,
                       unsigned int* n_comp, unsigned int* n_mov);
#endif
