#include "doctest.h"
#include "lista.h"

TEST_CASE("Testando construtor"){
    Lista* l1 = new Lista();
    CHECK_EQ(l1->get_tamanho(), 0);
    CHECK_EQ(l1->get_celula(0)->get_proxima(), nullptr);
    CHECK_EQ(l1->get_celula(0), l1->get_celula(l1->get_tamanho()));

    delete l1;
}

TEST_CASE("Testando inserção"){
    Lista* l = new Lista();
    Aluno* a1 = new Aluno("Samantha!", 700.51, 3, 2);
    Aluno* a2 = new Aluno("Percoço", 680.04, 1, 4);
    Aluno* a3 = new Aluno("Zé Pikeno", 790.67, 3, 2);

    Celula* cabeca = l->get_celula(0);
    l->inserir(a1);
    CHECK_EQ(l->get_tamanho(), 1);
    CHECK_EQ(l->get_aluno(1), a1);
    CHECK_EQ(l->get_celula(1)->get_proxima(), nullptr);
    CHECK_EQ(l->get_celula(1)->get_anterior(), cabeca);
    CHECK_EQ(l->get_celula(1)->get_anterior(), l->get_celula(0));
    CHECK_EQ(l->get_celula(0)->get_proxima()->get_aluno(), a1);
    CHECK_EQ(l->get_aluno(l->get_tamanho()), a1);

    l->inserir(a2);
    CHECK_EQ(l->get_tamanho(), 2);
    CHECK_EQ(l->get_aluno(2), a2);
    CHECK_EQ(l->get_celula(2)->get_proxima(), nullptr);
    CHECK_EQ(l->get_celula(2)->get_anterior()->get_aluno(), a1);
    CHECK_EQ(l->get_celula(2)->get_anterior(), l->get_celula(1));
    CHECK_EQ(l->get_celula(0)->get_proxima()->get_aluno(), a1);
    CHECK_EQ(l->get_celula(l->get_tamanho()-1)->get_proxima()->get_aluno(), a2);
    CHECK_EQ(l->get_aluno(l->get_tamanho()), a2);

    l->inserir(a3);
    CHECK_EQ(l->get_tamanho(), 3);
    CHECK_EQ(l->get_aluno(3), a3);
    CHECK_EQ(l->get_celula(3)->get_proxima(), nullptr);
    CHECK_EQ(l->get_celula(3)->get_anterior()->get_aluno(), a2);
    CHECK_EQ(l->get_celula(3)->get_anterior(), l->get_celula(2));
    CHECK_EQ(l->get_celula(0)->get_proxima()->get_aluno(), a1);
    CHECK_EQ(l->get_celula(0)->get_proxima()->get_proxima()->get_aluno(), a2);
    CHECK_EQ(l->get_aluno(l->get_tamanho()), a3);

    delete l;
    delete a1;
    delete a2;
    delete a3;
}

TEST_CASE("Testando ordenação 1"){
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
  CHECK_EQ(l.get_aluno(1), &a5);
  CHECK_EQ(l.get_aluno(2), &a2);
  CHECK_EQ(l.get_aluno(3), &a1);
  CHECK_EQ(l.get_aluno(4), &a6);
  CHECK_EQ(l.get_aluno(5), &a3);
  CHECK_EQ(l.get_aluno(6), &a7);
  CHECK_EQ(l.get_aluno(7), &a4);

}

TEST_CASE("Testando ordenação 2"){
  //muda uns valores
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
  CHECK_EQ(l.get_aluno(1), &a3);
  CHECK_EQ(l.get_aluno(2), &a4);
  CHECK_EQ(l.get_aluno(3), &a2);
  CHECK_EQ(l.get_aluno(4), &a5);
  CHECK_EQ(l.get_aluno(5), &a1);

}

TEST_CASE("Testando ordenação 3"){
  //muda a inserção
  Lista l = Lista();
  Aluno a1 = Aluno("Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno("Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno("Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno("Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno("Séverine", 400.54, 4, 3);

  l.inserir(&a4);
  l.inserir(&a1);
  l.inserir(&a2);
  l.inserir(&a3);
  l.inserir(&a5);

  l.ordenar();
  CHECK_EQ(l.get_aluno(1), &a5);
  CHECK_EQ(l.get_aluno(2), &a2);
  CHECK_EQ(l.get_aluno(3), &a1);
  CHECK_EQ(l.get_aluno(4), &a3);
  CHECK_EQ(l.get_aluno(5), &a4);

}

TEST_CASE("Testando ordenação 4"){
  //muda a inserção
  Lista l = Lista();
  Aluno a1 = Aluno("Samantha!", 700.51, 3, 2);
  Aluno a2 = Aluno("Percoço", 680.04, 1, 4);
  Aluno a3 = Aluno("Zé Pikeno", 790.67, 3, 2);
  Aluno a4 = Aluno("Wanda", 899.34, 1, 2);
  Aluno a5 = Aluno("Séverine", 400.54, 4, 3);

  l.inserir(&a2);
  l.inserir(&a1);
  l.inserir(&a3);
  l.inserir(&a4);
  l.inserir(&a5);

  l.ordenar();
  CHECK_EQ(l.get_aluno(1), &a5);
  CHECK_EQ(l.get_aluno(2), &a2);
  CHECK_EQ(l.get_aluno(3), &a1);
  CHECK_EQ(l.get_aluno(4), &a3);
  CHECK_EQ(l.get_aluno(5), &a4);

}
