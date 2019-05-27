#ifndef DIASWSIS_H
#define DIASWSIS_H
#include "oxima.h"
#include "Xarths.h"
#include <vector>

class diaswsis : public oxima
{
    public:
        diaswsis();
        virtual ~diaswsis();
        void leitourgia(int, int);
        int getArEpid();
        void setArEpid(int);
    private:
        int arEpid;  // katagrafetai to poses fores exei epidiorthwsei
};

#endif // DIASWSIS_H

extern std::vector<diaswsis*> diaswstika;
extern std::vector<diaswsis*>::iterator diasIt;
