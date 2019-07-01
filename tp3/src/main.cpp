#include <iostream>
#include "no.h"

int main(int argc, char* argv[]){
  No* t = new No();
  t->insere('A', ".");
  t->insere('B', "-");
  t->insere('C', "..");
  t->insere('D', ".-");
  t->insere('E', "-.");
  t->insere('F', "--");
  t->preOrdem();
  std::cout << t->pesquisa("--")->get_letra() << std::endl;
  std::cout << t->pesquisa(".-")->get_letra() << std::endl;
  std::cout << t->pesquisa("..")->get_letra() << std::endl;
  std::cout << t->pesquisa("-")->get_letra() << std::endl;
}
