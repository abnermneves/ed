#include <iostream>
#include "aluno.h"
#include "curso.h"

int main () {
  Lista l = Lista();
  Aluno a1 = Aluno("Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno("Percoço", 580.04, 1, 4);
  Aluno a3 = Aluno("Zé Pikeno", 235.67, 3, 2);
  Aluno a4 = Aluno("Wanda", 499.84, 1, 2);
  Aluno a5 = Aluno("Séverine", 600.54, 4, 3);

  l.inserir(&a1);
  l.inserir(&a2);
  l.inserir(&a3);
  l.inserir(&a4);
  l.inserir(&a5);

  l.ordenar();
  l.imprimir();

    return 0;
}
