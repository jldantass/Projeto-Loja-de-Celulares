  #ifndef CRUD_H
#define CRUD_H

#include <iostream>
using namespace std;
#include <string>
#include "Android.h"
#include "Ios.h"
#include <vector>
#include "Cliente.h"


class Crud {

  private:

    int contador;
    string nome;
    vector<Telefone*> telefones;
    vector<Pessoa*> pessoas;

  public:
      Crud();
      void imprimirCrud();
      int pesquisaTel(string nome);
      int pesquisaCliente(string nome, string  login);
  };

#endif
