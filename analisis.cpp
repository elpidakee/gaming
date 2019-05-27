#include "analisis.h"
#include "oxima.h"
#include "Xarths.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

analisis::analisis()
{
    //vazw rand() gia x, y gia na m dhmiourgithoun sthn idia thesi
    setTaxitita(2);
    //srand(time(0));
    //setEidos(getX(), getY(), "A");
    Xarths::thesis[getX()][getY()] = "A";
    synPos = 0.0;  // arxikopoihsh ths synolikis posotitas pou exei sylleksei synolika kathe oxima
    setAr_vlavwn(0);
    setAr_theseis(0);
    setKatastasi(true);
}

analisis::~analisis()
{
    //  destructor oximatos analisis
}

double analisis::getMaxIr()
{
    return maxIr;
}

double analisis::getMaxPal()
{
    return maxPal;
}

double analisis::getMaxLeyk()
{
    return maxLeyk;
}

float analisis::getSynPos()
{
      return synPos;
}

void analisis::leitourgia(int x, int y)
{
    if(Xarths::epikPros[x][y] >= 0.4)
        {

        if(getIridio() < maxIr)
        {
            setIridio(Xarths::perIr[x][y]);
            Xarths::perIr[x][y] = 0 ;// adeiazei h thesi apo iridio
            synPos += Xarths::perIr[x][y];
            cout << "To oxima analisis ekane eksoriksi" << endl;
        }
        else if(getIridio() >= maxIr)
        {
            setX(4);  // ean exei ftasei th megisti posotita iridiou pigainei sti vasi
            setY(4);
            Xarths::perIr[4][4] += maxIr;
            Xarths::perIr[x][y] = 0 ;// adeiazei h thesi apo iridio
            synPos += maxIr;
            cout << "To oxima analisis ekane eksoriksi kai phge sth vash." <<endl;
        }
        if(getPalladio() < maxPal)
        {
            setPalladio(Xarths::perPal[x][y]);
            Xarths::perPal[x][y] = 0; // adeiazei h thesi apo palladio
            synPos += Xarths::perIr[x][y];
            cout << "To oxima analisis ekane eksoriksi" << endl;
        }
        else if(getPalladio() >= maxPal)
        {
            setX(4);   // ean exei ftasei th megisti posotita palladiou pigainei sti vasi
            setY(4);
            Xarths::perPal[4][4] += maxPal;
            Xarths::perPal[x][y] = 0; // adeiazei h thesi apo palladio
            synPos += maxPal;
            cout << "To oxima analisis ekane eksoriksi kai phge sth vash." <<endl;
        }
        if(getLeykoxrysos() < maxLeyk)
        {
            setLeykoxrysos(Xarths::perLeyk[x][y]);
            Xarths::perLeyk[x][y] = 0; // adeiazei h thesi apo leykoxryso
            synPos += Xarths::perLeyk[x][y];
            cout << "To oxima analisis ekane eksoriksi" << endl;
        }
        else if(getLeykoxrysos() >= maxLeyk)
        {
            setX(4);    // ean exei ftasei th megisti posotita leykoxrysou pigainei sti vasi
            setY(4);
            Xarths::perLeyk[4][4] += maxLeyk;
            Xarths::perLeyk[x][y] = 0 ;// adeiazei h thesi apo leykoxryso
            synPos += maxLeyk;
            cout << "To oxima analisis ekane eksoriksi kai phge sth vash." <<endl;
        }
    }
}
