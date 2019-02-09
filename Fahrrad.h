#ifndef FAHRRAD_H_
#define FAHRRAD_H_
#include <string>

class Fahrrad: public Fahrzeug{
    
    public:
    Fahrrad(std::string, double);
    Fahrrad(Fahrrad &);
    virtual ~Fahrrad();
    virtual bool operator < (const Fahrrad &) override;
    virtual void operator = (Fahrrad &) override;
    virtual std::ostream& ostreamAusgabe(std::ostream&) const override;
    virtual double dTanken() override;
    virtual double dTanken(double) override;
    virtual double dGeschwindigkeit() override;
    virtual void vAbfertigung() override;
};

#endif
