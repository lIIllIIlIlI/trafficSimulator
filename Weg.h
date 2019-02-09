#ifndef WEG_H_
#define WEG_H_
#include "AktivesVO.h"

enum {
    Innerorts = 50;
    Landstaße = 100;
    Autobahn = -1;
};

class Weg : public AktivesVO {

    protected:
    double p_dLaenge;
    std::list<Fahrzeug> p_pFahrzeuge;
    double p_eLimit;

    public:
    virtual void vAbfertigung() override;
    virtual void vAusgabe() override;
    
}



#endif
