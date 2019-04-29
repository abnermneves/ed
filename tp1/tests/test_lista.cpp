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
    Aluno* a1 = new Aluno(0, "Samantha!", 700.51, 3, 2);
    Aluno* a2 = new Aluno(1, "Percoço", 680.04, 1, 4);
    Aluno* a3 = new Aluno(2, "Zé Pikeno", 790.67, 3, 2);

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
