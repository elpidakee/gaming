#include "diaswsis.h"
#include "oxima.h"
#include "Xarths.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;

diaswsis::diaswsis()
{

    arEpid = 0;
    setTaxitita(3);
    //srand(time(0));
    setEidos(getX(), getY(), "D");
    setAr_vlavwn(0);
    setAr_theseis(0);
    setKatastasi(true);
}
diaswsis::~diaswsis()
{
    //destructor oximatos diaswsis
}
void diaswsis::leitourgia(int x,int y)
{

   if(getKatastasi() == true)
   {
      if((Xarths::thesis[x][y-1]!="+") && (getKatastasi()==false))
      {
          ar_vlavwn++;
          setAr_vlavwn(ar_vlavwn);
          setKatastasi(true);
          setArEpid(arEpid++);
          y=y-1;  // allazei to y wste na epistrafoun oi nees syntetagmenes tou oximatos diaswsis
          setY(y);
          cout << "To oxima epidiorthothike." << endl;
      }
      if((Xarths::thesis[x-1][y]!="+") && (getX() == x-1) && (getY() == y))
      {
          setKatastasi(true);
          setArEpid(arEpid++);
          x = x-1;   // allazei to x wste na epistrafoun oi nees syntetagmenes tou oximatos diaswsis
          setX(x);
          cout << "To oxima epidiorthothike." << endl;
      }
      if((Xarths::thesis[x][y+1]!="+") && (getX() == x) && (getY() == y+1))
      {
          setKatastasi(true);
          setArEpid(arEpid++);
          y = y+1;   // allazei to y wste na epistrafoun oi nees syntetagmenes tou oximatos diaswsis
          setY(y);
          cout << "To oxima epidiorthothike." << endl;
      }
      if((Xarths::thesis[x+1][y]!="+") && (getX() == x+1) && (getY() == y))
      {
          setKatastasi(true);
          setArEpid(arEpid++);
          x = x+1;    // allazei to x wste na epistrafoun oi nees syntetagmenes tou oximatos diaswsis
          setX(x);
          cout << "To oxima epidiorthothike." << endl;
      }
   }
}

int diaswsis::getArEpid()
{
    return arEpid;
}
void diaswsis::setArEpid(int ar)
{
    arEpid = ar;
}


