#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "no.h"

int main(int argc, char* argv[]){
  No* trie = new No();
  char letra;
  std::string chave, codigo, linha;
  std::ifstream morse;
  morse.open("morse.txt");
  //se abriu com sucesso o arquivo
  if (morse.is_open()){
    //enquanto não chega o fim do arquivo
    while(!morse.eof()){
      morse >> letra >> chave;
      trie->insere(letra, chave);
    }
    morse.close();
  }

  while(std::getline(std::cin, linha)){
    std::istringstream iss (linha);
    while(iss >> codigo){
      if (codigo == "/"){
        std::cout << " ";
      }
      else{
        std::cout << trie->pesquisa(codigo)->get_letra();
      }
    }
    std::cout << std::endl;
  }

}
