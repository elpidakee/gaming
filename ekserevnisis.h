#ifndef EKSEREVNISIS_H
#define EKSEREVNISIS_H

#include "oxima.h"
#include "Xarths.h"
#include <vector>

class ekserevnisis : public oxima
{
    public:
        ekserevnisis();
        virtual ~ekserevnisis();
        void leitourgia(int, int);  // elegxos epikindinotitas kai topothetisi shmaias se periptwsh pou i epikindinotita einai megalyteri tou 0.6
        int  getSimKin();
        void setSimKin(int, int);
    protected:
    private:
        int SimKin;  // metritis pou deixnei poses simaies exei topothetisei to oxima ekserevnisis
};

#endif // EKSEREVNISIS_H

extern std::vector<ekserevnisis*> ekserevnitika;
extern std::vector<ekserevnisis*>::iterator ekseIt;
extern int eCounter;
