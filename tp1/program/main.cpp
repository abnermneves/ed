#include <iostream>
#include "aluno.h"
#include "curso.h"
#include "minisisu.h"

int main () {
    MiniSisu* sisu = new MiniSisu();
    sisu->ler();
    sisu->classificar();
    sisu->imprimir_entrada();

    delete sisu;

    return 0;
}
