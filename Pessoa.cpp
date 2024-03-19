#include <iostream>
#include "Pessoa.h"
using namespace std;
#include <string>

Pessoa::Pessoa(string n, string c, string na) {
    nome = n;
    cpf = c;
    nascimento = na;
}

    void Pessoa::setNome (string n) {
        nome = n;
    }

    string Pessoa::getNome() {
        return nome;
    }

    void Pessoa::setCpf (int c) {
        cpf = c;
    }

    string Pessoa::getCpf() {
        return cpf;
    }

    void Pessoa::setNascimento (string na) {
        nascimento = na;
    }

    string Pessoa::getNascimento() {
        return nascimento;
    }

    void Pessoa::imprimirInformacao(){
      cout << "*****************************************************" << endl;
      cout << "* Nome " << nome <<  endl;
      cout << "* CPF: " << cpf << endl;
      cout << "* Nascimento: " << nascimento << endl;
    
      
    }