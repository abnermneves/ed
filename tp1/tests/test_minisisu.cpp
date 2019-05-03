#include "doctest.h"
#include "minisisu.h"
#include "lista.h"
TEST_CASE("Testando ordenação 1"){
  MiniSisu* sisu = new MiniSisu();
  Lista<Aluno*>* l = sisu->get_lista_alunos();
  Aluno a1 = Aluno(1, "Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno(2, "Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno(3, "Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno(4, "Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno(5, "Séverine", 400.54, 4, 3);
  Aluno a6 = Aluno(6, "Chacal", 789.34, 1, 2);
  Aluno a7 = Aluno(7, "Zé Grande", 790.68, 1, 2);
  l->inserir(&a1);
  l->inserir(&a2);
  l->inserir(&a3);
  l->inserir(&a4);
  l->inserir(&a5);
  l->inserir(&a6);
  l->inserir(&a7);

  sisu->ordenar_alunos();
  CHECK_EQ(l->get_objeto(7), &a5);
  CHECK_EQ(l->get_objeto(6), &a2);
  CHECK_EQ(l->get_objeto(5), &a1);
  CHECK_EQ(l->get_objeto(4), &a6);
  CHECK_EQ(l->get_objeto(3), &a3);
  CHECK_EQ(l->get_objeto(2), &a7);
  CHECK_EQ(l->get_objeto(1), &a4);

  sisu->~MiniSisu();
}

TEST_CASE("Testando ordenação 2"){
  //muda uns valores
  MiniSisu* sisu = new MiniSisu();
  Lista<Aluno*>* l = sisu->get_lista_alunos();
  Aluno a1 = Aluno(1, "Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno(2, "Percoço", 580.04, 1, 4);
  Aluno a3 = Aluno(3, "Zé Pikeno", 235.67, 3, 2);
  Aluno a4 = Aluno(4, "Wanda", 499.84, 1, 2);
  Aluno a5 = Aluno(5, "Séverine", 600.54, 4, 3);

  l->inserir(&a1);
  l->inserir(&a2);
  l->inserir(&a3);
  l->inserir(&a4);
  l->inserir(&a5);

  sisu->ordenar_alunos();
  CHECK_EQ(l->get_objeto(5), &a3);
  CHECK_EQ(l->get_objeto(4), &a4);
  CHECK_EQ(l->get_objeto(3), &a2);
  CHECK_EQ(l->get_objeto(2), &a5);
  CHECK_EQ(l->get_objeto(1), &a1);

  sisu->~MiniSisu();
}

TEST_CASE("Testando ordenação 3"){
  //muda a inserção
  MiniSisu* sisu = new MiniSisu();
  Lista<Aluno*>* l = sisu->get_lista_alunos();
  Aluno a1 = Aluno(1, "Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno(2, "Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno(3, "Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno(4, "Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno(5, "Séverine", 400.54, 4, 3);

  l->inserir(&a4);
  l->inserir(&a1);
  l->inserir(&a2);
  l->inserir(&a3);
  l->inserir(&a5);

  sisu->ordenar_alunos();
  CHECK_EQ(l->get_objeto(5), &a5);
  CHECK_EQ(l->get_objeto(4), &a2);
  CHECK_EQ(l->get_objeto(3), &a1);
  CHECK_EQ(l->get_objeto(2), &a3);
  CHECK_EQ(l->get_objeto(1), &a4);

  sisu->~MiniSisu();
}

TEST_CASE("Testando ordenação 4"){
  //muda a inserção
  MiniSisu* sisu = new MiniSisu();
  Lista<Aluno*>* l = sisu->get_lista_alunos();
  Aluno a1 = Aluno(1, "Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno(2, "Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno(3, "Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno(4, "Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno(5, "Séverine", 400.54, 4, 3);

  l->inserir(&a2);
  l->inserir(&a1);
  l->inserir(&a3);
  l->inserir(&a4);
  l->inserir(&a5);

  sisu->ordenar_alunos();
  CHECK_EQ(l->get_objeto(5), &a5);
  CHECK_EQ(l->get_objeto(4), &a2);
  CHECK_EQ(l->get_objeto(3), &a1);
  CHECK_EQ(l->get_objeto(2), &a3);
  CHECK_EQ(l->get_objeto(1), &a4);

  sisu->~MiniSisu();
}

TEST_CASE("Testando ordenação 5"){
    MiniSisu* sisu = new MiniSisu();
  Lista<Aluno*>* l = sisu->get_lista_alunos();
    Aluno a = Aluno(1, "Olavo das Neves", 496.00, 0, 1);
    sisu->ordenar_alunos();
    l->inserir(&a);

    sisu->ordenar_alunos();
    CHECK_EQ(l->get_objeto(1), &a);

    sisu->~MiniSisu();
}
