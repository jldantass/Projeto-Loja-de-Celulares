#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;
#include <string>

class Pessoa {

    protected:
        string nome;
        string cpf;
        string nascimento;
    public:
        Pessoa(string n, string c, string na);

        void setNome (string n);
        string getNome();

        void setCpf (int c);
        string getCpf();

        void setNascimento (string na);
        string getNascimento();

        virtual void imprimirInformacao();
};

#endif