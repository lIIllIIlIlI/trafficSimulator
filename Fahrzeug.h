#define FAHRZEUG_H_
#ifndef FAHRZEUG_H_
#include <string>
#include <iostream>
extern double dGlobaleZeit;
class AktivesVO;

class Fahrzeug : public AktivesVO{
    protected: 
    double p_dGesamtStrecke;
    double p_dGesamtZeit;
    double p_dGeschwindigkeit;
    double p_dMaxGeschwindigkeit;

    public:
    Fahrzeug();
    Fahrzeug(std::string);
    Fahrzeug(std::string, double);
    Fahrzeug(Fahrzeug &);
    virtual ~Fahrzeug();
    double dGetvGesamtStrecke() const;
    double dGetvGesamtZeit() const;
    double dGetvZeit() const;
    double dGetvGeschwindigkeit() const;
    void vSetdGeschwindigkeit(double);
    void vSetdMaxGeschwindigkeit(double);
    double dGetvMaxGeschwindigkeit() const;
    virtual bool operator < (const Fahrzeug &);
    virtual void operator = (Fahrzeug &);
    virtual std::ostream& ostreamAusgabe(std::ostream&) const;
    virtual void vAusgabe() const;
    virtual void vAbfertigung();
    virtual double dTanken();
    virtual double dTanken(double);
    virtual double dGeschwindigkeit();

    private:
    void vInitialisierung();
};

// std::ostream& operator << (std::ostream &, const Fahrzeug &);
#endif

