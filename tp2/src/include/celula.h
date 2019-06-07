#ifndef CELULA_H
#define CELULA_H

class Celula {
private:
  int esq;
  int dir;
  Celula* prox;

public:
  Celula();
  Celula(int esq, int dir);
  ~Celula();
  int get_esq();
  int get_dir();
  Celula* get_prox();
  void set_esq(int esq);
  void set_dir(int dir);
  void set_prox(Celula* prox);
};

#endif
