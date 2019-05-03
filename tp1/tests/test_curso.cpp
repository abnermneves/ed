#include "doctest.h"
#include "curso.h"

TEST_CASE("Testando construtor"){
    Curso c1 = Curso(0, "Alquimia", 20);
    CHECK_EQ(c1.get_id(), 0);
    CHECK_EQ(c1.get_nome(), "Alquimia");
    //CHECK_EQ(c1.classificados->size(), 20);

    Curso* c2 = new Curso(1, "Física", 15);
    CHECK_EQ(c2->get_id(), 1);
    CHECK_EQ(c2->get_nome(), "Física");
    CHECK_EQ(c2->get_vagas(), 15);

    delete c2;
}

TEST_CASE("Testando ordenação 1"){
  Curso* curso = new Curso(1, "Maquiagem", 3);
  Lista<Aluno*>* l = curso->get_po();
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

  curso->ordenar_alunos(l);
  CHECK_EQ(l->get_objeto(7), &a5);
  CHECK_EQ(l->get_objeto(6), &a2);
  CHECK_EQ(l->get_objeto(5), &a1);
  CHECK_EQ(l->get_objeto(4), &a6);
  CHECK_EQ(l->get_objeto(3), &a3);
  CHECK_EQ(l->get_objeto(2), &a7);
  CHECK_EQ(l->get_objeto(1), &a4);

}

TEST_CASE("Testando ordenação 2"){
  //muda uns valores
  Curso* curso = new Curso(1, "Maquiagem", 3);
  Lista<Aluno*>* l = curso->get_po();
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

  curso->ordenar_alunos(l);
  CHECK_EQ(l->get_objeto(5), &a3);
  CHECK_EQ(l->get_objeto(4), &a4);
  CHECK_EQ(l->get_objeto(3), &a2);
  CHECK_EQ(l->get_objeto(2), &a5);
  CHECK_EQ(l->get_objeto(1), &a1);

}

TEST_CASE("Testando ordenação 3"){
  //muda a inserção
  Curso* curso = new Curso(1, "Maquiagem", 3);
  Lista<Aluno*>* l = curso->get_po();
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

  curso->ordenar_alunos(l);
  CHECK_EQ(l->get_objeto(5), &a5);
  CHECK_EQ(l->get_objeto(4), &a2);
  CHECK_EQ(l->get_objeto(3), &a1);
  CHECK_EQ(l->get_objeto(2), &a3);
  CHECK_EQ(l->get_objeto(1), &a4);

}

TEST_CASE("Testando ordenação 4"){
  //muda a inserção
  Curso* curso = new Curso(1, "Maquiagem", 3);
  Lista<Aluno*>* l = curso->get_po();
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

  curso->ordenar_alunos(l);
  CHECK_EQ(l->get_objeto(5), &a5);
  CHECK_EQ(l->get_objeto(4), &a2);
  CHECK_EQ(l->get_objeto(3), &a1);
  CHECK_EQ(l->get_objeto(2), &a3);
  CHECK_EQ(l->get_objeto(1), &a4);

}

TEST_CASE("Testando ordenação 5"){
    Curso* curso = new Curso(1, "Maquiagem", 3);
    Lista<Aluno*>* l = curso->get_po();
    Aluno a = Aluno(1, "Olavo das Neves", 496.00, 0, 1);
    curso->ordenar_alunos(l);
    l->inserir(&a);

    curso->ordenar_alunos(l);
    CHECK_EQ(l->get_objeto(1), &a);
}
