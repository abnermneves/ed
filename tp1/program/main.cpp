#include <iostream>
#include "aluno.h"
#include "curso.h"
#include "minisisu.h"

int main () {
    MiniSisu* sisu = new MiniSisu();
    sisu->ler();
    //sisu->imprimir_entrada();
    sisu->classificar();
    sisu->imprimir();

    delete sisu;

    return 0;
}
