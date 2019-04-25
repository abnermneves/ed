#include "doctest.h"
#include "curso.h"

TEST_CASE("Testando construtor"){
    Curso c1 = Curso("Alquimia", 20);
    CHECK_EQ(c1.get_nome(), "Alquimia");
    CHECK_EQ(c1.get_vagas(), 20);
    //CHECK_EQ(c1.classificados->size(), 20);
    
    Curso* c2 = new Curso("Física", 15);
    CHECK_EQ(c2->get_nome(), "Física");
    CHECK_EQ(c2->get_vagas(), 15);
    
    delete c2;
}


