#ifndef TELEFONE_H
#define TELEFONE_H

#include <iostream>
using namespace std;
#include <string>

class Telefone {

protected:
    string tipo;
    string marca;
    string nometel;
    string tamTela;
    string bateria;
    string mram;
    string camFrontal;
    string camTraseira;
    string conectividade;
    string processador;
    string memoria;
    string preco;
    string quantidade;

public:
    Telefone(string type, string ma, string nt, string preco, string tt, string b, string mr, string cf, string ct, string co, string p, string m,string q);

    virtual ~Telefone();

    string getTipo();

    void setPreco(string prc);
    string getPreco();

    void setMarca(string ma);
    string getMarca();

    void setNomeTel(string nt);
    string getNomeTel();

    void setTamTela(string tt);
    string getTamTela();

    void setBateria(string b);
    string getBateria();

    void setMRam(string mram);
    string getMRam();

    void setCamFrontal(string cf);
    string getCamFrontal();

    void setCamTraseira(string ct);
    string getCamTraseira();

    void setConectividade(string co);
    string getConectividade();

    void setProcessador(string p);
    string getProcessador();

    void setMemoria(string m);
    string getMemoria();

    void setQuantidade(string q);
    string getQuantidade();

    virtual void imprimirInfo();
};

#endif
