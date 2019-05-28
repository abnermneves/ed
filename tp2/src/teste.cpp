#include <iostream>

void teste(int argc, char* argv[]){
  std::cout << "Tamanho: " << argc << std::endl;
  for (int i = 0; i < argc; i++)
    std::cout << argv[i] << std::endl;
}
