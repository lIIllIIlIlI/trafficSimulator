#ifndef PKW_H_
#define PKW_H_
#include <string>

class PKW: public Fahrzeug{
    public:
    
    private:
    double p_dVerbrauch;
    double p_dTankinhalt;
    double p_dTankvolumen;
    double p_dGesamtVerbrauch;

    public:
    PKW(std::string,double,double,double,double);
    PKW(std::string,double,double,double);
    PKW(std::string,double,double);
    PKW(PKW &);
    virtual ~PKW();
    double dGetVerbrauch();
    double dGetTankinhalt();
    double dGetTankvolumen();
    double dGetGesamtVerbrauch();
    virtual void vAusgabe() const;
    virtual std::ostream& ostreamAusgabe(std::ostream&) const override;
    virtual bool operator < (const PKW &) override;
    virtual void operator = (PKW &) override;
    virtual void vAbfertigung() override; 
    virtual double dTanken() override;
    virtual double dTanken(double) override;
    virtual double dGeschwindigkeit() override;

    private:
    double dVerbrauch();
};

#endif

