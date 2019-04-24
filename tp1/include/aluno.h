#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    unsigned int nota;
    unsigned int p; //primeira opcao
    unsigned int s; //segunda opcao
    
public:
    Aluno(std::string nome,
          unsigned int nota,
          unsigned int p,
          unsigned int s);
    ~Aluno();
    
};

#endif
