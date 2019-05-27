#ifndef ANALISIS_H
#define ANALISIS_H
#include "oxima.h"
#include "Xarths.h"
#include <vector>

class analisis : public oxima
{
    public:
        analisis();
        virtual ~analisis();
        void leitourgia(int, int); // leitourgia oximatos analisis: pairnei ta stoixeia apo thesi kai ta stelnei sti vasi an exei ftasei to megisto fortio
        double getMaxIr();
        double getMaxPal();
        double getMaxLeyk();
        float  getSynPos();

    private:
         double maxIr = 2.1;  // megisto fortio oximatos analisis gia iridio palladio kai leykoxryso
         double maxPal = 2.3;
         double maxLeyk = 2.4;
         float synPos;  // synoliki posotita pou synellekse to kathe oxima
};

#endif // ANALISIS_H

extern std::vector<analisis*> analitika;
extern std::vector<analisis*>::iterator analIt;
extern int aCounter;
