#include "doctest.h"
#include "lista-sequencial.h"

TEST_CASE("Testando construtor"){
    ListaSequencial l1 = ListaSequencial(5);
    CHECK_EQ(l1.get_maxtam(), 5);
}
