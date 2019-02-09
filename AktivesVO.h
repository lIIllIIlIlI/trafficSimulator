#ifndef AKTIVESVO_H_
#define AKTIVESVO_H_
#include <string>
#include <iostream>

extern double dGlobaleZeit;

//    *************  Abstract class   ***************          
class AktivesVO{
    protected:
    int p_iID;
    static int p_iMaxID;
    std::string p_sName;
    double p_dZeit;
    
    protected:
    AktivesVO();
    AktivesVO(std::string);
    AktivesVO(AktivesVO &);
    virtual ~AktivesVO();

    public:
    int iGetvID() const;
    void vSetiID(int);
    std::string sGetvName() const;
    void vSetsName(std::string);
    double dGetvZeit() const;
    void vSetdZeit(double);
    
    virtual std::ostream& ostreamAusgabe(std::ostream&) const;
    virtual void vAbfertigung() = 0;
    virtual void vAusgabe();
    };

std::ostream& operator << (std::ostream &, const AktivesVO &cAV);
#endif 