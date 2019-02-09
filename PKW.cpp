#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
    :Fahrzeug(sName,dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen){
    p_dTankinhalt=p_dTankvolumen/2.0;
    p_dGesamtVerbrauch = 0.0;
    Fahrzeug::vSetdGeschwindigkeit(dMaxGeschwindigkeit);
};

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch)
    :Fahrzeug(sName,dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch){
    p_dTankvolumen = 55;
    p_dTankinhalt = p_dTankvolumen/2.0;
    p_dGesamtVerbrauch = 0.0;
};

PKW::PKW(PKW &revPKW):Fahrzeug(revPKW){
    this -> p_dVerbrauch = revPKW.p_dVerbrauch;
    this -> p_dTankvolumen = revPKW.p_dTankvolumen;
}

PKW::~PKW(){};

double PKW::dGetVerbrauch(){
    return p_dVerbrauch;
}

double PKW::dGetTankinhalt(){
    return p_dTankinhalt;
}

double PKW::dGetTankvolumen(){
    return p_dTankvolumen;
}

double PKW::dGetGesamtVerbrauch(){
    return p_dGesamtVerbrauch;
}

void PKW::vAusgabe() const override{
    Fahrzeug::vAusgabe();
    cout << setw(16) << p_dTankinhalt << setw(16) << p_dGesamtVerbrauch << endl;
}

ostream& PKW::ostreamAusgabe(ostream &output) const override{
    Fahrzeug::ostreamAusgabe(output) << setw(12) << p_dTankinhalt
    << setw(16) << p_dGesamtVerbrauch << endl;
    return output;
};

bool PKW::operator <(const PKW &revPKW) override{
    if(this->dGetvGesamtStrecke() < revPKW.dGetvGesamtStrecke())return 1;
    return 0;
}

void PKW::operator = (PKW &revPKW) override{
    revPKW.p_dVerbrauch = this -> p_dVerbrauch;
    revPKW.p_dTankvolumen = this -> p_dTankvolumen;
}

void PKW::vAbfertigung() override{
    if(dGetvZeit() < dGlobaleZeit){ 
        p_dGesamtStrecke += (dGlobaleZeit - p_dZeit) * PKW::dGeschwindigkeit();
        p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
        p_dGesamtVerbrauch += (((dGlobaleZeit - p_dZeit) * PKW::dGeschwindigkeit()) / 100.0) * p_dVerbrauch;
        p_dTankinhalt = p_dTankinhalt - (((dGlobaleZeit - p_dZeit) * PKW::dGeschwindigkeit()) / 100.0) * p_dVerbrauch;
        if(p_dTankinhalt<0.0)p_dTankinhalt = 0.0;
        vSetdZeit(dGlobaleZeit);
    } 
};

double PKW::dTanken() override{
    p_dTankinhalt=p_dTankvolumen;
    return p_dTankinhalt;
};

double PKW::dTanken(double dAuftanken) override{
    p_dTankinhalt=p_dTankvolumen + dAuftanken;
    if(p_dTankinhalt > p_dTankvolumen) p_dTankinhalt = p_dTankvolumen;
    return p_dTankinhalt;
};

double PKW::dGeschwindigkeit() override{
    return p_dMaxGeschwindigkeit;
};
