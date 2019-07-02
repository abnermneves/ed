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
  //verifica se abriu com sucesso o arquivo
  if (!morse.is_open()){
    std::cout << "Falha ao ler arquivo morse.txt" << std::endl;
    return 0;
  }

  //lê as letras e códigos enquanto não chega o fim do arquivo
  while(!morse.eof()){
    morse >> letra >> chave;
    trie->insere(letra, chave);
  }
  morse.close();

  //lê a entrada padrão linha por linha
  while(std::getline(std::cin, linha)){
    std::istringstream iss (linha);
    //lê uma linha código por código
    while(iss >> codigo){
      //imprime a letra ou um espaço
      if (codigo == "/")
        std::cout << " ";
      else
        std::cout << trie->pesquisa(codigo)->get_letra();
    }
    std::cout << std::endl;
  }
  trie->~No();
  return 0;
}
