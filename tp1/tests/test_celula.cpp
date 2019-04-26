#include "doctest.h"
#include "celula.h"
#include "aluno.h"

TEST_CASE("Testando construtores"){
    Celula c1 = Celula();
    CHECK_EQ(c1.get_aluno(), nullptr);
    CHECK_EQ(c1.get_proximo(), nullptr);
    
    Aluno* a = new Aluno("Marina", 998.0, 3, 1);
    
    Celula* c2 = new Celula(a);
    CHECK_EQ(c2->get_aluno(), a);
    CHECK_EQ(c2->get_proximo(), nullptr);
    
    
    
    delete a;
    delete c2;
    
}

TEST_CASE("Testando setters"){
    Aluno* a = new Aluno("Marina", 998.0, 3, 1);
    Aluno* a2 = new Aluno("Lana", 780.0, 2, 1);
    Aluno* a3 = new Aluno("c", 900.0, 4, 3);
    
    Celula* c1 = new Celula(a);
    Celula* c2 = new Celula(a2);
    
    c1->set_proximo(c2);
    CHECK_EQ(c1->get_proximo(), c2);
    
    c1->set_aluno(a3);
    CHECK_EQ(c1->get_aluno(), a3);

    delete a;
}
