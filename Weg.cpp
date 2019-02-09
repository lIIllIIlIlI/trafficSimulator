#include "AktivesVO.h"
#include "Weg.h"
using namespace std;

Weg::Weg(): p_dLaenge(0), p_pFahrzeuge(NULL), p_eLimit(-1) {};

Weg::Weg(dLaenge, pFahrzeuge, eLimit): p_dLaenge(dLaenge), p_pFahrzeuge(pFahrzeuge),
				       p_eLimit(eLimit){};	 

Weg::vAbfertigung() override{
       	
}
