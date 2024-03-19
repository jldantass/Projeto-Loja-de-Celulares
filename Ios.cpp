#include "Ios.h"
#include <iostream>
using namespace std;
#include <string>

Ios::Ios(string type, string ma, string nt, string prc, string tt, string b, string mr, string cf, string ct, string co, string p, string m, string q, string fid, string d, string vi) : Telefone(type, ma, nt, prc, tt, b, mr, cf, ct, co, p, m, q) {
      faceID = fid;
      digital = d;
      versaoios = vi;
    }

void Ios::setFaceID(string fid) {
    faceID = fid;
}

string Ios::getFaceID() {
    return faceID;
}

void Ios::setDigital(string d) {
    digital = d;
}

string Ios::getDigital() {
    return digital;
}

void Ios::setVersaoIos(string vi) {
    versaoios = vi;
}

string Ios::getVersaoIos() {
    return versaoios;
}

void Ios::imprimirInfo() {
    Telefone::imprimirInfo();
    cout << "* FaceID: " << faceID << endl;
    cout << "* Digital: " << digital << endl;
    cout << "* Versão iOS: " << versaoios << endl;
    cout << "*****************************************************" << endl;
    cout << "\n";
}
