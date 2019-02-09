#include <string>
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"
#include "Fahrzeug.h" 
using namespace std;

Fahrzeug::Fahrzeug() : AktivesVO(){
    vInitialisierung();
    p_dMaxGeschwindigkeit = 0;
};

Fahrzeug::Fahrzeug(string sName) : AktivesVO(sName) {
    vInitialisierung();
    p_dMaxGeschwindigkeit = 0;
};

Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) : AktivesVO(sName), 
                   p_dMaxGeschwindigkeit (dMaxGeschwindigkeit) {
    p_dGeschwindigkeit = dMaxGeschwindigkeit;
    vInitialisierung();
};

Fahrzeug::Fahrzeug(Fahrzeug &revFahrzeug): AktivesVO(revFahrzeug){
    p_dMaxGeschwindigkeit = revFahrzeug.p_dMaxGeschwindigkeit;
}

Fahrzeug::~Fahrzeug(){};

double Fahrzeug::dGetvGesamtStrecke() const{
    return p_dGesamtStrecke;
};

double Fahrzeug::dGetvGesamtZeit() const{
    return p_dGesamtStrecke;
};

double Fahrzeug::dGetvZeit() const{
    return p_dZeit;
};

double Fahrzeug::dGetvGeschwindigkeit() const{
    return p_dGeschwindigkeit;
}

void Fahrzeug::vSetdGeschwindigkeit(double dGeschwindigkeit){
    p_dGeschwindigkeit = dGeschwindigkeit;
}

void Fahrzeug::vSetdMaxGeschwindigkeit(double dGeschwindigkeit){
    p_dMaxGeschwindigkeit =  dGeschwindigkeit;
    p_dGeschwindigkeit = dGeschwindigkeit;
}

double Fahrzeug::dGetvMaxGeschwindigkeit() const{
    return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator < (const Fahrzeug &revFahrzeug){
    if(this->dGetvGesamtStrecke() < revFahrzeug.dGetvGesamtStrecke())return 1;
    return 0;
}

void Fahrzeug::operator = (Fahrzeug &revFahrzeug){
    revFahrzeug.p_sName = this -> p_sName;
    revFahrzeug.p_dMaxGeschwindigkeit = this -> p_dMaxGeschwindigkeit;
}

ostream& Fahrzeug::ostreamAusgabe(ostream &output) const{
    AktivesVO::ostreamAusgabe(output);
    setiosflags(ios::fixed);
    AktivesVO::ostreamAusgabe(output) << setw(20) << ":" << setw(20) << 
    p_dMaxGeschwindigkeit << setw(20) << p_dGeschwindigkeit << setw(20) << p_dGesamtStrecke;
    return output;
};
 
void Fahrzeug::vAusgabe() const{
    setiosflags(ios::fixed);
    cout.precision(3);
    cout << setw(20) << p_iID <<setw(20) << p_sName << setw(20) << ":" << setw(20) << 
    p_dMaxGeschwindigkeit << setw(20) << p_dGeschwindigkeit << setw(20) << p_dGesamtStrecke;
};
   
void Fahrzeug::vAbfertigung(){
    if(p_dZeit < dGlobaleZeit){ 
        p_dGesamtStrecke += (dGlobaleZeit - p_dZeit) * Fahrzeug::dGeschwindigkeit();
        p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
        p_dZeit = dGlobaleZeit;
    }
};

double Fahrzeug::dGeschwindigkeit(){
    return p_dMaxGeschwindigkeit;
};

double Fahrzeug::dTanken(){return 0.0;};

double Fahrzeug::dTanken(double dAuftanken){return 0.0;};

void Fahrzeug::vInitialisierung(){
    p_dGesamtStrecke = 0.0;
    p_dGesamtZeit = 0.0;
    p_dZeit = 0.0;
};

/*ostream& operator << (ostream &output,const Fahrzeug &cFahrzeug){ 
    cFahrzeug.ostreamAusgabe(output);
    return output;
}*/






