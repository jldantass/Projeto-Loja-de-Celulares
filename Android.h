#ifndef ANDROID_H
#define ANDROID_H

#include <iostream>
using namespace std;
#include <string>
#include "Telefone.h"

class Android : public Telefone {
private:
    string digitaland;
    string versaoand;

public:
    Android(string type, string ma, string nt, string prc, string tt, string b, string mr, string cf, string ct, string co, string p, string m, string q, string da, string va);

    void setDigital(string da);
    string getDigital();

    void setVersaoAnd(string va);
    string getVersaoAnd();

    void imprimirInfo() override;
};

#endif
