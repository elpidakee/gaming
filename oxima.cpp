#include "Xarths.h"
#include "oxima.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

oxima::oxima()
{
   hi = rand()%20;
   psi = rand()%20;
   setX(hi);
   setY(psi);
   setProsvasi(0.1);
   setIridio(0.0);
   setPalladio(0.0);
   setLeykoxrysos(0.0);
}
oxima::~oxima()
{
   cout << "To oxima aposyrthike." <<endl;
}
std::string oxima::getEidos(int xi, int yi)
{
   return Xarths::thesis[xi][yi];
}
void oxima::setEidos(int xi, int yi, string e)
{
    eidos = e;
    Xarths::thesis[xi][yi] = eidos;
}
void oxima::setTaxitita(int x) // orizetai me rand h taxitita tou oximatos apo 1 ews 20
{
    taxitita = x;
}
int oxima::getTaxitita()
{
    return taxitita;
}
void oxima::setIridio(double ir)
{
    iridio = ir;
}
double oxima::getIridio()
{
    return iridio;
}
void oxima::setPalladio(double pal)
{
    palladio = pal;
}
double oxima::getPalladio()
{
    return palladio;
}
void oxima::setLeykoxrysos(double ley)
{
    leykoxrysos = ley;
}
double oxima::getLeykoxrysos()
{
    return leykoxrysos;
}
void oxima::setKatastasi(bool k)
{
    katastasi = k;
}
bool oxima::getKatastasi()
{
    return katastasi;
}
int oxima::getAr_theseis()
{
    return ar_theseis;
}
void oxima::setAr_theseis(int art)
{
    ar_theseis = art;
}
int oxima::getAr_vlavwn()
{
    return ar_vlavwn;
}
void oxima::setAr_vlavwn(int arv)
{
    ar_vlavwn = arv;
}
void oxima::setX(int xValue)
{
    x = xValue;
}
int oxima::getX()
{
	return x;
}
void oxima::setY( int yValue )
{
	y = yValue;
}
int oxima::getY()
{
	return y;
}

void oxima::setProsvasi(float p)
{
    //prosvasi = p;
    srand (static_cast <unsigned> (time(0)));
    prosvasi = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
double oxima::getProsvasi()
{
    return prosvasi;
}
void oxima::vlavi(int x,int y,bool k)
{
    int pithanotita; // orizoume thn pithanotita na pathei vlavi to oxima
    pithanotita = Xarths::epikPros[x][y]*(1.0-getProsvasi()); // h vlavi isoutai me epikindynotitaprosvasis*(1-ikanotita prosvasis oximatos)
    if(pithanotita>=0.6)
    { katastasi = false;
      this->ar_vlavwn++;
      setAr_vlavwn(ar_vlavwn);
      setTaxitita(0);
    } // allazei h katastasi tou oximatos

}


void oxima::metakinisi()
{
    int gyroi15 = 0; // metritis o opoios otan ginei 15 kalei ton destructor gia na aposyrthei to oxima afou gia 15 gyrous emeine akinito logw vlavhs
    srand(time(0));
    taxitita = getTaxitita();
    x = getX();
    y = getY();
    int prosX = 1;  // topikes metavlites gia tis proswrines syntetagmenes tou oximatos
    int prosY = 1;
	int kinhsh;
	kinhsh = rand()%4; //exoume 4 kinhseis (panw, katw, deksia, aristera)
	if(getKatastasi() == true)
    {
	   if(taxitita == 1)
       {
		switch(kinhsh)
		{
			case 0: //kinhsh panw
				if(y==0) prosY=19; //elegxos an vriskomaste sta oria tou xarth
				else prosY--;
				break;
			case 1: //kinhsh katw
				if(y==19) prosY=0; //elegxos an vriskomaste sta oria tou xarth
				else prosY++;
				break;
			case 2: //kinhsh aristera
				if(x==0) prosX=19; //elegxos an vriskomaste sta oria tou xarth
				else prosX--;
				break;
			case 3: //kinhsh deksia
				if(x==19) prosX=0; //elegxos an vriskomaste sta oria tou xarth
				else prosX++;
				break;
		}
       }
       else if(taxitita >= 2)
       {
           switch(kinhsh)
		   {
			  case 0: //kinhsh panw
				if(y==0) prosY=18; //elegxos an vriskomaste sta oria tou xarth
				else prosY = y-2;
				break;
			  case 1: //kinhsh katw
				if(y==19) prosY=1; //elegxos an vriskomaste sta oria tou xarth
				else prosY = y+2;
				break;
			  case 2: //kinhsh aristera
				if(x==0) prosX=18; //elegxos an vriskomaste sta oria tou xarth
				else prosX = x-2;
				break;
			  case 3: //kinhsh deksia
				if(x==19) prosX = 1; //elegxos an vriskomaste sta oria tou xarth
				else prosX = x+2;
				break;
           }
       }
    if((Xarths::thesis[prosX][prosY]!="A") && (Xarths::thesis[prosX][prosY]!="D") && (Xarths::thesis[prosX][prosY]!="E")) // elegxei ean sthn kainouria thesi yparxei allo oxima. an yparxei de tha mpei sthn if
    //if(Xarths::thesis[prosX][prosY].empty())
    {
      if((prosX<=19) && (prosY<=19) && (Xarths::simaia[prosX][prosY] == false) && (prosX!=4 && prosY!=4)) // elegxei an ta nea x, y einai mesa sta oria tou xarth, ean den yparxei simaia kai ean oi nees syntetagmenes den peftoun panw sth vash(4,4)
      {
          setX(prosX);
          setY(prosY);
          if(getTaxitita() == 1) { ar_theseis ++;}
          if(getTaxitita() >= 2) { ar_theseis +=2;}
          Xarths::thesis[x][y] = getEidos(x,y);
      }
    }
	}
	gyroi15++;
	if(gyroi15 == 15)
    {
       setTaxitita(0);
       setX(4);
       setY(4);
       setKatastasi(false);
    }
}


void oxima::print()  // typwnei ta xaraktiristika kai tis kiniseis kathe oximatos
{
    cout << "Thesi:" << '[' << getX() << ", " << getY() << ']' << endl;
    if(getKatastasi()==true)
    {cout << "Katastasi: Energo" << endl;
     cout << "Taxitita:" << getTaxitita() << endl;
     cout << "Ikanotita Prosvasis Oximatos:" << prosvasi <<endl;}
    else
    {cout << "Katastasi: Exei vlavi" << endl;
     cout << "Taxitita = 0" <<endl;
     cout << "Ikanotita Prosvasis Oximatos:0" <<endl;}
    cout << "Exei metakinithei kata: " << getAr_theseis() << "theseis" << endl;
    cout << "Exei ypostei: " << getAr_vlavwn() << "vlaves" << endl;
    cout << endl;

}
void oxima::leitourgia()
{

}
