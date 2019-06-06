void Particiona(int* vetor, unsigned int esq, unsigned int dir,
                unsigned int* i, unsigned int* j){
  int aux;
  *i = esq;
  *j = dir;
  int pivo = vetor[(*i+*j)/2];
  
  do{
    while (vetor[*i] < pivo)
      (*i)++;
    while (vetor[*j] > pivo)
      (*j)--;
    if (*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int* vetor, unsigned int esq, unsigned int dir){
  unsigned int i, j;
  Particiona(vetor, esq, dir, &i, &j);
  if (j > esq)
    Ordena(vetor, esq, j);
  if (i < dir)
    Ordena(vetor, i, dir);
}

void QC(int* vetor, unsigned int tam){
  Ordena(vetor, 0, tam-1);
}
