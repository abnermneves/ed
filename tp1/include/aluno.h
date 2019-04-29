#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    unsigned int id; //id de acordo com a ordem de inscrição
    std::string nome;
    float nota;
    unsigned int p; //primeira opcao
    unsigned int s; //segunda opcao

public:
    Aluno();
    Aluno(unsigned int id,
          std::string nome,
          float nota,
          unsigned int p,
          unsigned int s);
    ~Aluno();

    std::string get_nome();
    float get_nota();
    unsigned int get_p();
    unsigned int get_s();
    unsigned int get_id();

};

#endif
