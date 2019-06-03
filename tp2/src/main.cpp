#include <iostream>
#include <string>
#include "teste.cpp"
using namespace std;

int main(int argc, char* argv[]){
  teste(argc, argv);
  string varQS = argv[1];
  string tipoVetor = argv[2];
  unsigned int tam = stoi(argv[3]);
  bool exibir = false;
  
  if (argc == 5){
    string p = argv[4];
    if(p == "-p")
      exibir = true;
  }
  
  int vetor[tam];
  
  if(tipoVetor == "Ale"){
  
  } else if (tipoVetor == "OrdC"){
  
  } else if (tipoVetor == "OrdD"){
  
  } else {
    cout << "Tipo de vetor inválido!" << endl;
  }
  
  if(varQS == "QC"){
      cout << "QC" << endl;
  } else if(varQS == "QM3"){
      cout << "QM3" << endl;
  } else if(varQS == "QPE"){
      cout << "QPE" << endl;
  } else if(varQS == "QI1"){
    
  } else if(varQS == "QI5"){
    
  } else if(varQS == "QI10"){
    
  } else if(varQS == "QNR"){
  
  } else{
      cout << "QuickSort inválido!" << endl;  
  }
  
  return 0;
}
