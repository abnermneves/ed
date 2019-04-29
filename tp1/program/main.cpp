#include <iostream>
#include "aluno.h"
#include "curso.h"

int main () {
  Lista l = Lista();
  Aluno a1 = Aluno("Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno("Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno("Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno("Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno("Séverine", 400.54, 4, 3);
  Aluno a6 = Aluno("Chacal", 789.34, 1, 2);
  Aluno a7 = Aluno("Zé Grande", 790.68, 1, 2);
  l.inserir(&a1);
  l.inserir(&a2);
  l.inserir(&a3);
  l.inserir(&a4);
  l.inserir(&a5);
  l.inserir(&a6);
  l.inserir(&a7);

  l.ordenar();
  l.imprimir();

    return 0;
}
