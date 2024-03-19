#include "Android.h"
#include <iostream>
using namespace std;
#include <string>

Android::Android(string type, string ma, string nt, string prc, string tt, string b, string mr, string cf, string ct, string co, string p, string m, string q, string da, string va)
    : Telefone(type, ma, nt, prc, tt, b, mr, cf, ct, co, p, m, q) {
      digitaland = da;
      versaoand = va;
    }

void Android::setDigital(string d) {
    digitaland = d;
}

string Android::getDigital() {
    return digitaland;
}

void Android::setVersaoAnd(string va) {
    versaoand = va;
}

string Android::getVersaoAnd() {
    return versaoand;
}

void Android::imprimirInfo() {
    Telefone::imprimirInfo();
    cout << "* Digital: " << digitaland << endl;
    cout << "* Versão Android: " << versaoand << endl;
    cout << "*****************************************************" << endl;
    cout << "\n";
}
