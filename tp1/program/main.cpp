#include <iostream>
#include "aluno.h"
#include "curso.h"

int main () {
    Lista* l = new Lista();
    Aluno* a1 = new Aluno("Samantha!", 700.51, 3, 2);
    Aluno* a2 = new Aluno("Percoço", 680.04, 1, 4);
    Aluno* a3 = new Aluno("Zé Pikeno", 790.67, 3, 2);
    l->inserir(a1);
    l->inserir(a2);
    l->inserir(a3);
    l->imprimir();

    delete l;
    delete a1;
    delete a2;
    delete a3;
    
    return 0;
}
