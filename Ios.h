  #ifndef IOS_H
#define IOS_H

#include <iostream>
using namespace std;
#include <string>
#include "Telefone.h"

class Ios : public Telefone {
private:
    string faceID;
    string digital;
    string versaoios;

public:
    Ios(string type, string ma, string nt, string prc, string tt, string b, string mr, string cf, string ct, string co, string p, string m, string q, string fid, string d, string vi);

    void setFaceID(string fid);
    string getFaceID();

    void setDigital(string d);
    string getDigital();

    void setVersaoIos(string vi);
    string getVersaoIos();

    void imprimirInfo() override;
};

#endif
