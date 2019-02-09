#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
using namespace std;


double dGlobaleZeit=0.0;


void vAufgabe_1(void);
void vAufgabe_1_deb(void);
void vAufgabe_2(void);
void vAufgabe_3(void);
void makeheader();


int main(int argc, char *argv[]) {
 // vAufgabe_1();
 // vAufgabe_2();
 // vAufgabe_3();
}
/*
void vAufgabe_1(){
    Fahrzeug BMW;
    BMW.vSetsName("BMW");
    BMW.vSetdMaxGeschwindigkeit(100.0);
    Fahrzeug Audi("Audi",100.0);
    Fahrzeug *VW = new Fahrzeug("VW");
    Fahrzeug *Porsche = new Fahrzeug;
    Porsche->vSetsName("Porsche");
    Porsche->vSetdMaxGeschwindigkeit(80.0);
    cout << BMW.sGetsName() << endl;
    cout << Audi.sGetsName() << endl;
    cout << VW->sGetsName() << endl;
    cout << Porsche->sGetsName() << endl;

    while(dGlobaleZeit <= 1.0){
        makeheader();
        BMW.vAusgabe(); 
        Audi.vAusgabe();
        VW->vAusgabe();
        Porsche->vAusgabe();
        BMW.vAbfertigung();
        Audi.vAbfertigung();
        VW->vAbfertigung();
        Porsche->vAbfertigung();
        dGlobaleZeit += 1.f/10.f;
        cout << "\n\n\n";
    }
//    cout << BMW < Audi;
}

void vAufgabe_2(){
   PKW *VW = new PKW("VW",100,8);
   Fahrrad *gruen = new Fahrrad("gruen", 25);
   PKW *BMW = new PKW ("BMW", 120, 12, 65);
   PKW *Mercedes = new PKW ("Mercedes", 20, 10, 50);
   PKW *Audi = new PKW("Audi", 100, 8, 60);
   while(dGlobaleZeit <= 1.0){
      *Mercedes = *BMW;
      makeheader();
      cout << *BMW << *Audi << *VW << *Mercedes << endl;
      cout << "\n\n\n" << endl;
      BMW->vAbfertigung();
      Audi->vAbfertigung();
      VW->vAbfertigung();
      Mercedes->vAbfertigung();
      dGlobaleZeit += 1.f/10.f;
      cout << "\n\n\n";
      cout << *gruen << endl;
      cout << *BMW << endl;
      PKW *Peugeot = new PKW(*BMW);
      cout << Peugeot << endl;
      cout << *BMW << endl;
      *BMW = *VW;
      cout << *BMW << endl;
      cout << " Ist BMW < Mercedes?" << endl;
      cout << (*BMW < *Mercedes) << endl;
   }
   if(*BMW < *Mercedes) cout<<"BMW<Mercedes";
   else cout << "Mercedes>BMW";
   *BMW = *Mercedes;
    PKW test(*Mercedes);
}

void vAufgabe_3(){
    makeheader();
    vector <Fahrzeug *> FahrzeugVector;
    PKW *VW = new PKW("VW",100,8);
    Fahrrad *gruen = new Fahrrad("gruen", 25);
    Fahrrad *blau = new Fahrrad ("blau", 20);
    Fahrrad *gelb = new Fahrrad ("gelb", 30);
    PKW *BMW = new PKW ("BMW", 120, 12, 65);
    PKW *Mercedes = new PKW ("Mercedes", 20, 10, 50);
    PKW *Audi = new PKW("Audi", 100, 8, 60);
    FahrzeugVector.push_back(VW);
    FahrzeugVector.push_back(gruen);
    FahrzeugVector.push_back(blau);
    FahrzeugVector.push_back(gelb);
    FahrzeugVector.push_back(BMW);
    FahrzeugVector.push_back(Mercedes);
    FahrzeugVector.push_back(Audi);
    vector <Fahrzeug*> :: iterator itr;


    while(dGlobaleZeit <= 1.0){
        makeheader();
        for (const auto& itr: FahrzeugVector){
            cout << *itr;
            cout << endl;
            itr->vAbfertigung();
        }
        cout << "Aktuelle globale Zeit:" << dGlobaleZeit << endl;
        dGlobaleZeit += 0.1;
    }
    
}
*/

void makeheader(){
    cout << left << setw(20) << "ID" <<setw(20) << "Name" << setw(20) << ":" << setw(20) << "MaxKmh" <<
    setw(20) << "Geschwindigkeit" << setw(20) << "Gesamtstrecke" << setw(20) << "Tankinhalt" << setw(20) << "Gesamtverbrauch" << endl;
    cout.fill('+');
    cout << setw(160) << "" << endl;
    cout.fill(' ');
}