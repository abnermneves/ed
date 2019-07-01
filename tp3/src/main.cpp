#include <iostream>
#include "no.h"

int main(int argc, char** argv){
  No* t = new No();
  No** trie = &t;
  t->insere(trie, 'A', ".");
  /*t->insere(trie, 'B', "-");
  t->insere(trie, 'C', "..");
  t->insere(trie, 'D', ".-");
  t->insere(trie, 'E', "-.");
  t->insere(trie, 'F', "--");*/
  //t->preOrdem();
  /*std::cout << t->pesquisa("--") << std::endl;
  std::cout << t->pesquisa(".-") << std::endl;
  std::cout << t->pesquisa("..") << std::endl;
  std::cout << t->pesquisa("-") << std::endl;*/
}
