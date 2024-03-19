#include <iostream>
#include "Pessoa.h"
#include "Cliente.h"
using namespace std;
#include <string>

Cliente::Cliente(string n, string c, string na, string l,  string numc, string e, string em) : Pessoa(n, c, na) {
    login = l;
    numcelular = numc;
    endereco = e;
    email = em;
}

void Cliente::setLogin(string l){
  login = l;
}

string Cliente::getLogin() {
  return login;

}

void Cliente::setNumCelular(string numc) {
    numcelular = numc;
}

string Cliente::getNumCelular() {
    return numcelular;
}

void Cliente::setEndereco(string e) {
    endereco = e;
}

string Cliente::getEndereco() {
    return endereco;
}

void Cliente::setEmail(string em) {
    email = em;
}

string Cliente::getEmail() {
    return email;

}

void Cliente::imprimirInformacao(){
    Pessoa::imprimirInformacao();
     cout << "* Login: " << login << endl;
     cout << "* Numero do celular: " << numcelular << endl;
     cout << "* Endereço: " << endereco << endl;
     cout << "* Email: " << email << endl;
     cout << "*****************************************************" << endl;
    
}
