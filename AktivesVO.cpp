#include <string>
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"
using namespace std;
int AktivesVO::p_iMaxID = 0; 

AktivesVO::AktivesVO(){
    p_iMaxID++;
    p_iID = p_iMaxID;
    p_sName = "";
};

AktivesVO::AktivesVO(string sName){
    p_iMaxID++;
    p_iID = p_iMaxID;
    p_sName = sName;
};

AktivesVO::AktivesVO(AktivesVO &revAktivesVO){
    p_sName = revAktivesVO.p_sName;
};

AktivesVO::~AktivesVO(){};

ostream& AktivesVO::ostreamAusgabe(ostream &output) const{
    setiosflags(ios::fixed);
    output << setw(20) << p_iID << setw(20) << p_sName;
    return output;
};

void AktivesVO::vAusgabe(){
    setiosflags(ios::fixed);
    cout.precision(3);
    cout << setw(20) << p_iID <<setw(20) << p_sName << endl;
};

int AktivesVO::iGetvID() const{
    return p_iID;   
};

void AktivesVO::vSetiID(int ID){
    p_iID = ID;
};

std::string AktivesVO::sGetvName() const{
    return p_sName;
};

void AktivesVO::vSetsName(string Name){
    p_sName = Name;
};

double AktivesVO::dGetvZeit() const{
    return p_dZeit;
};

void AktivesVO::vSetdZeit(double Zeit){
    p_dZeit = Zeit; 
};

ostream& operator << (ostream &output,const AktivesVO & cAktivesVO){ 
    cAktivesVO.ostreamAusgabe(output);
    return output;
};



