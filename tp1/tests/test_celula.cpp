#include "doctest.h"
#include "celula.h"
#include "aluno.h"

TEST_CASE("Testando construtores"){
    Celula<Aluno*> c1 = Celula<Aluno*>();
    CHECK_EQ(c1.get_objeto(), nullptr);
    CHECK_EQ(c1.get_proxima(), nullptr);
    CHECK_EQ(c1.get_anterior(), nullptr);
    CHECK_EQ(c1.get_posicao(), 0);

    Aluno* a = new Aluno(0, "Marina", 998.0, 3, 1);

    Celula<Aluno*>* c2 = new Celula<Aluno*>(a);
    CHECK_EQ(c2->get_objeto(), a);
    CHECK_EQ(c2->get_proxima(), nullptr);
    CHECK_EQ(c2->get_anterior(), nullptr);
    CHECK_EQ(c2->get_posicao(), 0);

    delete a;
    delete c2;

}

TEST_CASE("Testando setters"){
    Aluno* a = new Aluno(0, "Marina", 998.0, 3, 1);
    Aluno* a2 = new Aluno(1, "Lana", 780.0, 2, 1);
    Aluno* a3 = new Aluno(2, "c", 900.0, 4, 3);

    Celula<Aluno*>* c1 = new Celula<Aluno*>(a);
    Celula<Aluno*>* c2 = new Celula<Aluno*>(a2);

    c1->set_proxima(c2);
    CHECK_EQ(c1->get_proxima(), c2);

    c1->set_objeto(a3);
    CHECK_EQ(c1->get_objeto(), a3);

    delete a;
}
