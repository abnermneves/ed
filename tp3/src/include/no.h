#ifndef NO_H
#define NO_H

#include <string>

class No {
private:
  No* esq;
  No* dir;
  std::string letra;
  std::string chave;

public:
  No();
  ~No();
  No* pesquisaR(No* t, std::string chave, int p);
  No* pesquisa(No* trie, int chave);
  No* separa(No* no1, No* no2, int p);
  No* insereR(No* t, std::string letra, int p);
  void insere(No** trie, std::string letra);
  void set_letra(std::string letra);
  void set_chave(std::string chave);
  std::string get_letra();
  std::string get_chave();
  No* get_esq();
  No* get_dir();
};

#endif
