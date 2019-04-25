#include "doctest.h"
#include "aluno.h"

TEST_CASE("Testando construtor"){
    Aluno a1 = Aluno("Snufkin", 819, 1, 2);
    CHECK_EQ(a1.get_nome(), "Snufkin");
    CHECK_EQ(a1.get_nota(), 819);
    CHECK_EQ(a1.get_p(), 1);
    CHECK_EQ(a1.get_s(), 2);
    
    Aluno* a2 = new Aluno("Moomin", 750, 3, 1);
    CHECK_EQ(a2->get_nome(), "Moomin");
    CHECK_EQ(a2->get_nota(), 750);
    CHECK_EQ(a2->get_p(), 3);
    CHECK_EQ(a2->get_s(), 1);
    
    delete a2;
}
