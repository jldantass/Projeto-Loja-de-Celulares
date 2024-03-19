#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;
#include <string>
#include "Pessoa.h"

class Cliente : public Pessoa {

    private:
        string numcelular;
        string endereco;
        string email;
        string login;
    public:
        Cliente(string n, string c, string na, string l, string numc, string e, string em);

        void setLogin(string l);
        string getLogin();

        void setNumCelular(string numc);
        string getNumCelular();

        void setEndereco(string e);
        string getEndereco();

        void setEmail(string em);
        string getEmail();


         void imprimirInformacao() override;
};

#endif