#include <iostream>
#include "aluno.h"
#include "curso.h"
#include "minisisu.h"

int main () {
    MiniSisu* sisu = new MiniSisu();
    Lista<Aluno*>* l = sisu->get_lista_alunos();
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

    sisu->ordenar_alunos();
    l->imprimir();

    delete sisu;

    return 0;
}
