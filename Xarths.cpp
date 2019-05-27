#include "Xarths.h"
#include "oxima.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

double Xarths::epikPros[20][20];  // th simaia, thn periektikothta kai tis periektikotites twn stoixeiwn ta exw dhlwsei static kai ta xw valei global
bool Xarths::simaia[20][20];      // wste na mporoun na xrhsimopoihthoun ki apo mh syggenikes klaseis
std::string Xarths::thesis[20][20];
float Xarths::perPal[20][20]; // periektikotita palladiou
float Xarths::perIr[20][20];  // periektikotita iridiou
float Xarths::perLeyk[20][20]; //periektikotita leykoxrisou

Xarths::Xarths()
{
  for(int i = 0; i <= 19; i++)
    {
        for(int j = 0; j <= 19; j++)
          {
            //srand(time(0));

            perLeyk[i][j] = kreation(0);   // kaleitai h synartisi kreation h opoia analoga me to z vazei mia timi
            perIr[i][j] = kreation(0);    // stis periektikotites kai sthn epikindinotita gia kathe ena simeio tou xarti
            perPal[i][j] = kreation(0);
            epikPros[i][j] = kreation(1);
            simaia[i][j] = false;
            thesis[i][j] = "+";
           // cout << thesis[i][j] << " ";
        }
    //     cout<<endl;
    }
    thesis[4][4] = "V";  //  sti thesi (x,y)=(4,4) einai topothetimeni h VASH
    perLeyk[4][4] = 0.1;   // oi periektikotites palladiou, iridiou kai leykoxrysou arxikopoiountai ws 0.1 sth vash
    perIr[4][4] = 0.1;
    perPal[4][4] = 0.1;
    epikPros[4][4] = 0.1; // h epikindinotita prosvasis sth vasi thewreitai 0.1

}
float Xarths::kreation(int zi)
{
    //srand(time(0));
    if(zi == 0)
    {
        return (rand()%3)/10;
    }
    else if(zi == 1)
    {
        return (rand()%10)/10;
    }
}
void Xarths::typwseThesis()  // typwne to oxima pou vrisketai se kathe thesi, ean vrisketai kapoio
{
     for(int i=0; i<20; i++)
     {
       for(int j=0; j<20; j++)
       {
         cout << thesis[i][j] << " ";
       }
     cout<<endl;
     }

}

Xarths::~Xarths()
{
    // destructor shmeiou/keliou
}

void Xarths::setX( int xValue )
{
	x = xValue;
}
int Xarths::getX()
{
	return x;
}
void Xarths::setY( int yValue )
{
	y = yValue;
}
int Xarths::getY()
{
	return y;
}

void Xarths::setPerPal(int i, int j,float x)
{
    perPal[i][j] = x;  // i,j einai deixnoun tis syntetagmenes tou keliou kai x h periektikothta se palladio. antistoixa gia iridio kai leykoxryso kai simaia
}
float Xarths::getPerPal(int i, int j)
{
    return perPal[i][j];
}
void Xarths::setPerIr(int i, int j,float x)
{
    perIr[i][j] = x;
}
float Xarths::getPerIr(int i, int j)
{
    return perIr[i][j];
}
void Xarths::setPerLeyk(int i, int j,float x)
{
    perLeyk[i][j] = x;
}
float Xarths::getPerLeyk(int i, int j)
{
    return perLeyk[i][j];
}

double Xarths::getEpikPros(int i, int j)
{
    return epikPros[i][j];
}
void Xarths::setSimaia(int i, int j,bool x)
{
    simaia[i][j] = x;
}
bool Xarths::getSimaia(int i, int j)
{
    return simaia[i][j];
}
