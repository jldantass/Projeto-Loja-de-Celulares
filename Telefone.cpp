#include <iostream>
using namespace std;
#include <string>
#include "Crud.h"
#include "Telefone.h"

Telefone::Telefone(string type, string ma, string nt, string prc, string tt, string b, string mr, string cf, string ct, string co, string p, string m, string q) {
    tipo = type;
    marca = ma;
    nometel = nt;
    preco = prc;
    tamTela = tt;
    bateria = b;
    mram = mr;
    camFrontal = cf;
    camTraseira = ct;
    conectividade = co;
    processador = p;
    memoria = m;
    quantidade = q;
}

Telefone::~Telefone() { }

string Telefone::getTipo() {
  return tipo;
}

void Telefone::setMarca(string ma) {
    marca = ma;
}

string Telefone::getMarca() {
    return marca;
}

void Telefone::setNomeTel(string nt) {
    nometel = nt;
}

string Telefone::getNomeTel() {
  return nometel;
}

void Telefone::setPreco(string prc) {
    preco = prc;
}

string Telefone::getPreco() {
    return preco;
}

void Telefone::setTamTela(string tt) {
    tamTela = tt;
}

string Telefone::getTamTela() {
    return tamTela;
}

void Telefone::setBateria(string b) {
    bateria = b;
}

string Telefone::getBateria() {
    return bateria;
}

void Telefone::setMRam(string mr) {
    mram = mr;
}

string Telefone::getMRam() {
    return mram;
}

void Telefone::setCamFrontal(string cf) {
    camFrontal = cf;
}

string Telefone::getCamFrontal() {
    return camFrontal;
}

void Telefone::setCamTraseira(string ct) {
    camTraseira = ct;
}

string Telefone::getCamTraseira() {
    return camTraseira;
}

void Telefone::setConectividade(string co) {
    conectividade = co;
}

string Telefone::getConectividade() {
    return conectividade;
}

void Telefone::setProcessador(string p) {
    processador = p;
}

std::string Telefone::getProcessador() {
    return processador;
}

void Telefone::setMemoria(string m) {
    memoria = m;
}

string Telefone::getMemoria() {
    return memoria;
}

void Telefone::setQuantidade(string q) {
    quantidade = q;
}

string Telefone::getQuantidade() {
    return quantidade;
}


void Telefone::imprimirInfo() {
    cout << "*****************************************************" << endl;
    cout << "* Tipo: " << tipo <<  endl;
    cout << "* Marca: " << marca << endl;
    cout << "* Nome: " << nometel << endl;
    cout << "* Tamanho da tela: " << tamTela << endl;
    cout << "* Bateria: " << bateria << endl;
    cout << "* Memória RAM: " << mram << endl;
    cout << "* Câmera frontal: " << camFrontal << endl;
    cout << "* Câmera traseira: " << camTraseira << endl;
    cout << "* Conectividade: " << conectividade << endl;
    cout << "* Processador: " << processador << endl;
    cout << "* Memória interna: " << memoria << endl;
    cout << "* Preço: " << preco << endl;
    cout << "* Quantidade de aparelhos: " << quantidade << endl;
  }

