#include "ekserevnisis.h"
#include "oxima.h"
#include <iostream>
#include "Xarths.h"
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

ekserevnisis::ekserevnisis()
{

  setTaxitita(1);
  //srand(time(0));
  setEidos(getX(), getY(), "E");
  SimKin = 0;     // simaia kindynou
  setAr_vlavwn(0);
  setAr_theseis(0);
  setKatastasi(true);
}
ekserevnisis::~ekserevnisis()
{
    // destructor oximatos ekserevnisis
}
void setSimKin(int x ,int y)
{
    Xarths::simaia[x][y] = true;
}

void ekserevnisis::leitourgia(int i, int j)
{
     if(Xarths::getEpikPros( i, j) >= 0.4)
      {
          //setSimKin(i, j);
          SimKin++;  // ayksisi tou metriti kathe fora pou topothetitai simaia
          cout << "Topothetithike simaia kindynou sth thesh:(" << i<<","<< j<<")" << endl;
      }
}

int ekserevnisis::getSimKin()
{
    return SimKin;
}

