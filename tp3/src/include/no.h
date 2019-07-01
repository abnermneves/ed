#ifndef NO_H
#define NO_H

#include <string>

class No {
private:
  No* esq;
  No* dir;
  char letra;
  std::string chave;

public:
  No();
  ~No();
  No* pesquisaR(std::string chave, int p);
  No* pesquisa(std::string chave);
  No* separa(No* no1, No* no2, int p);
  void insereR(char letra, std::string chave, int p);
  void insere(char letra, std::string chave);
  void preOrdem();

  void set_letra(char letra);
  void set_chave(std::string chave);
  void set_esq(No* esq);
  void set_dir(No* dir);
  char get_letra();
  std::string get_chave();
  No* get_esq();
  No* get_dir();
};

#endif
