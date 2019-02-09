#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "math.h"
using namespace std;

Fahrrad::Fahrrad(string sName,double dMaxGeschwindigkeit)
                :Fahrzeug(sName,dMaxGeschwindigkeit){
    Fahrzeug::vSetdGeschwindigkeit(dMaxGeschwindigkeit);
}

Fahrrad::Fahrrad(Fahrrad &revFahrrad):Fahrzeug(revFahrrad){
}

Fahrrad::~Fahrrad(){
};

double Fahrrad::dTanken() override{
    return 0.0;
};

double Fahrrad::dTanken(double dAuftanken) override{
    return 0.0;
};

double Fahrrad::dGeschwindigkeit() override{
    double Geschwindigkeit = this->dGetvMaxGeschwindigkeit() * (1- this->dGetvGesamtStrecke() / 200);
    if(Geschwindigkeit<12.0){Geschwindigkeit = 12.0;};
    this->vSetdGeschwindigkeit(Geschwindigkeit);
    this->vSetdMaxGeschwindigkeit(Geschwindigkeit);
    return Geschwindigkeit;
}

void Fahrrad::vAbfertigung() override{
    if(this->dGetvZeit() < dGlobaleZeit){ 
        p_dGesamtStrecke += (dGlobaleZeit - p_dZeit) * Fahrrad::dGeschwindigkeit();
        p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
        this->vSetdZeit(dGlobaleZeit);
    }
} 

bool Fahrrad::operator <(const Fahrrad &revFahrrad) override{
    if(this->dGetvGesamtStrecke() < revFahrrad.dGetvGesamtStrecke())return 1;
    return 0;
}

void Fahrrad::operator = (Fahrrad &revFahrrad) override{}

ostream& Fahrrad::ostreamAusgabe(ostream &output) const{
    Fahrzeug::ostreamAusgabe(output) << endl;
    return output;
};

