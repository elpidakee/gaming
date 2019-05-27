#ifndef XARTHS_H
#define XARTHS_H
#include "oxima.h"
#include <string>
class Xarths
{
    public:
        Xarths();
        virtual ~Xarths();
        float kreation(int);  // synartisi tyxaias arxikopoihshs twn stoixeiwn tou planiti
        static void typwseThesis();
        void setX(int);
        int getX();
        void setY(int);
        int getY();
        void setPerPal(int i, int j,float x);
        static float getPerPal(int i,int j);
        void setPerIr(int i, int j,float x);
        static float getPerIr(int i,int j);
        void setPerLeyk(int i, int j,float x);
        static float getPerLeyk(int i,int j);
        static double getEpikPros(int i,int j);
        static bool getSimaia(int i,int j);
        void setSimaia(int i, int j,bool x);
        static double epikPros[20][20];  // epikindinotita prosvasis
        static bool simaia[20][20];  // simaia kindynou pou deixnei gia false an mia thesi einai epikindini wste na apofeyxthei
        static std::string thesis[20][20]; // deixnei gia kathe shmeio tou xarti an yparxei oxima kai poio einai ayto
        static float perPal[20][20]; // periektikotita palladiou
        static float perIr[20][20];  // periektikotita iridiou
        static float perLeyk[20][20]; //periektikotita leykoxrisou
        float maxPerIr = 4.8; // megisth posothta iridiou
        float maxPerPal = 4.9;   // megisth posotita palladiou
        float maxPerLeyk = 5.0;  // megisth posothta leykoxrysou
    private:
        int x;  // ta x kai y deixnoun tis syntetagmenes tou shmeiou/keliou sto xarth
        int y;
        int z;
};
#endif // XARTHS_H
