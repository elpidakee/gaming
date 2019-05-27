#include "ekserevnisis.h"
#include "Xarths.h"
#include "oxima.h"
#include <iostream>
#include "analisis.h"
#include "diaswsis.h"
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <vector>

using namespace std;

std::vector<oxima*> oximata;
std::vector<oxima*>::iterator oximaIt;
std::vector<diaswsis*> diaswstika;
std::vector<diaswsis*>::iterator diasIt = diaswstika.begin();
std::vector<ekserevnisis*> ekserevnitika;
std::vector<ekserevnisis*>::iterator ekseIt = ekserevnitika.begin();
std::vector<analisis*> analitika;
std::vector<analisis*>::iterator analIt = analitika.begin();

int input, ox, ex, ey, allagi, vlav, dial, ar, plir, d; // metavlites tou signalhundler
int eCounter = 0, dCounter = 0, aCounter = 0, ekseNumber, diasNumber, analNumber; // eCounter deixnei poses theseis exei o pinakas twn antikeimenwn kai eNumber deikths tou pinaka

void signalHandler( int signum ) //synarthsh shmatos diakophs
{
	//int k, tmp, input, aeroNumber, pyroNumber, fotiaX, fotiaY; //Entolh xrhsth
	cout << "Interrupt signal (" << signum << ") received.\n";
	cout << "Dose Entolh : " << endl;
	//menou epilogwn
	cout << "1.Eisagogh oximatos"<<endl <<"2.Epeksergasia thesis edafous" <<endl << "3.Vlavh(eisagwgh h epidiorthwsi)" <<endl<< "4.Stoixeia oximatos" <<endl << "5.Stoixeia thesis edafous" <<endl << "6.Plirofories(oximatwn/diathesimwn thesewn)" <<endl<< "7.Termatismos ths prosomoiwshs" << endl << "8.Synexish prosomoiwshs" <<endl;
	cin >> input;
	while((input >=1) && (input <=7)) //oso o xrhsths dinei arithmous apo to 1 ews to 8..., sto 9 synexizei h prosomoiwsh
	{
		switch(input)
		{
			case 1:
				cout << "(1)Eisagwgh oximatos" << endl;
				cout << "Dwse: 1-gia oxima ekserevnisis // 2-gia oxima diaswsis // 3-gia oxima analisis" << endl;
				cin >> ox;
				cout<<endl;
				switch(ox)
				{
					case 1:
						cout << "(1) Eisagogh neou oximatos ekserevnisis" << endl;
                        if (ekserevnitika.size() == 10){
                        cout << endl << "Megistos arithmos oximatwn ekserevnisis"<< endl <<endl;
                        break;
                        }
                        ekserevnitika.push_back(new ekserevnisis());//prosthiki neou antikeimenou pyrosvestiko
                        break;
					case 2:
						cout << "(2) Eisagogh neou oximatos diaswsis" << endl;
                        if (diaswstika.size() == 10){
                        cout << endl << "Megistos arithmos oximatwn diaswsis"<<endl;
                        break;
                        }
                        diaswstika.push_back(new diaswsis());//prosthiki neou antikeimenou pyrosvestiko
                        break;
                    case 3:
                        cout << "(3) Eisagogh neou oximatos analisis" <<endl;
                        if (analitika.size() == 10){
                        cout << endl << "Megistos arithmos oximatwn analisis"<<endl;
                        break;
                        }
                        analitika.push_back(new analisis());//prosthiki neou oximatos analisis
                        break;
				}break;
			case 2:
				cout << "(2) Epeksergasia thesis edafous" << endl;
				cout << "Dwse syntetagmenes x,y(apo to 1 mexri to 20):" << endl;
				cout << "X=" ;
				cin >> ex ;
				cout << endl << "Y=" ;
				cin >> ey;
				cout<< endl << "Dialsekse ti apo ta parakatw thes na allakseis sthn sygkekrimeni thesi." <<endl<< "Dwse: 1-gia thn epikindinotita prosvasis // 2-gia thn simaia katastasis // 3-gia thn periektikotita iridiou // 4-gia thn periektikotita palladiou // 5-gia thn periektikotita leykoxrysou"<<endl;
				cin >> allagi;
				switch(allagi)
				{
                   case 1:
                       cout<<endl <<"Allagi epikindinotitas prosvasis" << endl;
                       cout <<"Dwse mia nea timh gia thn epikindynotita prosvasis(se dekadiki morfh):" <<endl;
                       cin >> Xarths::epikPros[ex][ey];
                       break;
                   case 2:
                       cout<< endl <<"Allagi ths simaias katastasis" << endl;
                       cout <<"Dwse mia nea timh gia thn shmaia katastashs:(true/false)" <<endl;
                       cin >> Xarths::simaia[ex][ey];
                       break;
                   case 3:
                       cout<<endl <<"Allagi ths periektikothtas iridiou" << endl;
                       cout <<"Dwse thn nea periektikotita iridiou(se dekadiki morfh):"<< endl;
                       cin >> Xarths::perIr[ex][ey];
                       cout << endl;
                       break;
                   case 4:
                       cout<<endl <<"Allagi ths periektikothtas palladiou" << endl;
                       cout <<"Dwse thn nea periektikotita palladiou(se dekadiki morfh):"<< endl;
                       cin >> Xarths::perPal[ex][ey];
                       cout << endl;
                       break;
                    case 5:
                       cout<<endl <<"Allagi ths periektikothtas leykoxrysou" << endl;
                       cout <<"Dwse thn nea periektikotita leykoxrysou(se dekadiki morfh):"<< endl;
                       cin >> Xarths::perLeyk[ex][ey];
                       cout << endl;
                       break;
                }break;

			case 3:
                cout << "(3) Vlavi(eisagwgh/epidiorthwsi" <<endl;
				cout << "Dwse 1-gia eisagwgh vlavhs, h 2-gia epidiorthwsi vlavhs" << endl;
				cin >> vlav;
				cout << endl;
				switch(vlav)
				{
                    case 1:
                        cout << "(1) Eisagwgh vlavhs se oxima" <<endl;
				        cout << "Dialekse oxima: 1-gia ekserevnisis // 2-gia diaswsis // 3-gia analisis" <<endl;
				        cin >> dial;
				        switch(dial)
				        {
					      case 1:
						     cout << "Dialekse oxima ekserevnisis: " << endl;
						     cin >> ekseNumber;
						     if(ekseNumber<0 || ekseNumber>=ekserevnitika.size())
                             {
							 cout << "Lanthasmenh Epilogh" << endl;
							 break;
						     }
						     else	ekserevnitika[ekseNumber]->setKatastasi(false); //allagh katastashs tou pyrosvestikou se vlavh
                             break;
                          case 2:
                             cout << "Dialekse oxima diaswsis: " << endl;
                             cin >> diasNumber;
                             if(diasNumber<0 || diasNumber>=diaswstika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> diasNumber;
                                 break;
                             }
                             else diaswstika[diasNumber]->setKatastasi(false);
                             break;
                          case 3:
                             cout << "Dialekse oxima analisis: " << endl;
                             cin >> analNumber;
                             if(analNumber<0 || analNumber>=analitika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> analNumber;
                                 break;
                             }
                             else analitika[analNumber]->setKatastasi(false);
                             break;
				        }break;
                    case 2:
                        cout << "(2) Epidiorthwsi vlavhs se oxima" <<endl;
				        cout << "Dialekse oxima: 1-gia ekserevnisis // 2-gia diaswsis // 3-gia analisis" <<endl;
				        cin >> d;
				        switch(d)
				        {
					      case 1:
						     cout << "Dialekse oxima ekserevnisis: " << endl;
						     cin >> ekseNumber;
						     if(ekseNumber<0 || ekseNumber>=ekserevnitika.size())
                             {
							 cout << "Lanthasmenh Epilogh" << endl;
							 break;
						     }
						     else	ekserevnitika[ekseNumber]->setKatastasi(true); //allagh katastashs tou pyrosvestikou se vlavh
                             break;
                          case 2:
                             cout << "Dialekse oxima diaswsis: " << endl;
                             cin >> diasNumber;
                             if(diasNumber<0 || diasNumber>=diaswstika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> diasNumber;
                                 break;
                             }
                             else diaswstika[diasNumber]->setKatastasi(true);
                             break;
                          case 3:
                             cout << "Dialekse oxima analisis: " << endl;
                             cin >> analNumber;
                             if(analNumber<0 || analNumber>=analitika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> analNumber;
                                 break;
                             }
                             else analitika[analNumber]->setKatastasi(true);
                             break;
				        }break;
				}break;
                case 4:
                         cout <<"(4) Stoixeia oximatos"<<endl;
                         cout <<"Dwse 1-gia ekserevnisis // 2-gia diaswsis // 3-gia analisis"<<endl;
                         cin>> ar;
                         switch(ar)
                         {
                         case 1:
                            cout<< "Dialekse oxima ekserevnisis:"<<endl;
                            cin>> ekseNumber;
                            if(ekseNumber<0 || ekseNumber>=ekserevnitika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> ekseNumber;
                                 break;
                             }
                             else ekserevnitika[ekseNumber]->print();
                             break;
                         case 2:
                            cout<< "Dialekse oxima diaswsis:"<<endl;
                            cin>> diasNumber;
                            if(diasNumber<0 || diasNumber>=diaswstika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> diasNumber;
                                 break;
                             }
                             else diaswstika[diasNumber]->print();
                             break;
                         case 3:
                            cout<< "Dialekse oxima analisis:"<<endl;
                            cin>> analNumber;
                            if(analNumber<0 || analNumber>=analitika.size())
                             {
                                 cout<< "Lanthasmeni epilogi. ksanaepelekse:"<<endl;
                                 cin >> analNumber;
                                 break;
                             }
                             else analitika[analNumber]->print();
                             break;
                         }break;
            case 5:
                        cout << "(5) Stoixeia thesis edafous" << endl;
				        cout << "Dwse syntetagmenes x,y(apo to 1 mexri to 20):" << endl;
				        cout << "X=";
				        cin >> ex;
                        cout<< endl << "Y=";
			         	cin >> ey;
			         	cout <<"H periektikotita iridiou gia thn thesi:"<< ex <<","<< ey <<"einai:"<<Xarths::getPerIr(ex, ey)<<endl;
			         	cout <<"H periektikotita palladiou gia thn thesi:"<< ex <<","<< ey <<"einai:"<<Xarths::getPerPal(ex, ey)<<endl;
                        cout <<"H periektikotita leykoxrysou gia thn thesi:"<< ex <<","<< ey <<"einai:"<<Xarths::getPerLeyk(ex, ey)<<endl;
                        cout <<"Sthn thesi:"<< ex <<","<< ey <<"yparxei to oxima:"<<Xarths::thesis[ex][ey]<<endl;
                        cout <<"H shmaia gia thn thesi:"<< ex <<","<< ey <<"einai:"<<Xarths::getSimaia(ex, ey)<<endl;
                        break;

            case 6:
				cout << "(6) Plirofories(oximatwn/diathesimwn thesewn)" << endl;
				cout <<"Dialekse: plirofories gia ta oximata h gia tis diathesimes theseis ?Dwse 1-gia ta oximata // 2-gia tis diathesimes theseis."<<endl;
				cin >> plir;
				cout<<endl;
				switch(plir)
				{
                   case 1:
                      cout << "Plirofories oximatwn."<< endl;
                        for(int k=0; k<ekserevnitika.size(); k++)
                        {
                            cout << "--- Ekserevnisis " << k << endl;
					        ekserevnitika[k]->print();
				        }
				        for(int k=0; k<diaswstika.size(); k++)
				        {
					        cout << "--- Diaswsis " << k << endl;
				        	diaswstika[k]->print();
				        }
				        for(int k=0; k<analitika.size(); k++)
				        {
					        cout << "--- Analisis " << k << endl;
				        	analitika[k]->print();
				        }
				   break;
				 // case 2   ????????
				   case 2:
                      cout<< "Plirofories diathesimwn thesewn:" <<endl;
                      for (int i=0; i<20; i++)
                      {
                        for(int j=0; j<20; j++)
                        {
						   if(Xarths::thesis[i][j].empty())
						   {
                             cout <<"H periektikotita iridiou sth thesi:"<< i<<","<<j<<"einai:"<< Xarths::getPerIr(i, j) <<endl;
                             cout <<"H periektikotita palladiou sth thesi:"<< i<<","<<j<<"einai:"<< Xarths::getPerPal(i, j) <<endl;
                             cout <<"H periektikotita leykoxrysou sth thesi:"<< i<<","<<j<<"einai:"<< Xarths::getPerLeyk(i, j) <<endl;
                             cout <<"H epikindynotita prosvasis sth thesi:"<< i<<","<< j<<"einai:"<<Xarths::getEpikPros(i, j)<<endl;
                             cout <<"H simaia katastasis sth thesi:"<< i<<","<< j <<"einai:"<<Xarths::getSimaia(i, j)<<endl;
					       }
					       cout << endl;
                        }
                      }
				   break;
				}break;
			case 7:
				cout << "TERMATISMOS..." << endl;
				exit(signum);	//termatismos tou programmatos
                break;
		}
		cout << "Dose Entolh : " << endl;
    	cout << "1.Eisagogh oximatos"<<endl <<"2.Epeksergasia thesis edafous" <<endl << "3.Vlavh(eisagwgh h epidiorthwsi)" <<endl<< "4.Stoixeia oximatos" <<endl << "5.Stoixeia thesis edafous" <<endl << "6.Plirofories(oximatwn/diathesimwn thesewn)" <<endl<< "7.Termatismos ths prosomoiwshs" << endl << "8.Synexish prosomoiwshs" <<endl;
	    cin >> input;
	}
}
int main()
{
   Xarths planet;

   ekserevnisis* eks1 = new ekserevnisis();
   ekserevnisis* eks2 = new ekserevnisis();
   ekserevnisis* eks3 = new ekserevnisis();
   ekserevnisis* eks4 = new ekserevnisis();
   diaswsis* dia1 = new diaswsis();
   diaswsis* dia2 = new diaswsis();
   diaswsis* dia3 = new diaswsis();
   diaswsis* dia4 = new diaswsis();
   analisis* ana1 = new analisis();
   analisis* ana2 = new analisis();
   analisis* ana3 = new analisis();
   analisis* ana4 = new analisis();
   ekserevnitika.reserve(8);
   diaswstika.reserve(8);
   analitika.reserve(8);
   ekserevnitika.push_back(eks1); // ekxwrisi twn antikeimenwn stous vectors
   ekserevnitika.push_back(eks2);
   ekserevnitika.push_back(eks3);
   ekserevnitika.push_back(eks4);
   diaswstika.push_back(dia1);
   diaswstika.push_back(dia2);
   diaswstika.push_back(dia3);
   diaswstika.push_back(dia4);
   analitika.push_back(ana1);
   analitika.push_back(ana2);
   analitika.push_back(ana3);
   analitika.push_back(ana4);

   signal(SIGINT, signalHandler); // synarthshs shmatos diakophs. kaleitai apton xrhsth patwntas ctrl+c

   int ola;          // metavliti h opoia ginetai 1 an ola ta oximata einai xalasmena h an ta apothemata sth vash
   int xalasmena = 0;    // ftasoun to megisto orio kai tote teleiwnei h prosomoiwsh
   int synolo;

   cout << "-------Ksekiname!!!!--------" << endl << endl << endl;
   cout << "______Gia na deite to menu epilogwn pathste Ctrl-c.______" << endl << endl;
   Sleep(20);
   do
   {
       ola = 0;
       cout << "--------Neos gyros--------" << endl << endl;
       Sleep(50);
       planet.typwseThesis();
       for(int i=0; i<diaswstika.size(); i++)
       {
         diaswstika[i]->metakinisi();  // kinisi gia kathe oxima diaswsis
         diaswstika[i]->print();
       }
       for(int i=0; i<ekserevnitika.size(); i++)
       {
         ekserevnitika[i]->metakinisi();  // kinisi gia kathe oxima ekserevnisis
       }
       for(int i=0; i<analitika.size(); i++)
       {
         analitika[i]->metakinisi();   // kinisi gia kathe oxima analisis
       }
       planet.typwseThesis();

       for(int i=0; i<ekserevnitika.size(); i++)
       {
          if(ekserevnitika[i]->getKatastasi() == false) // tsekarei an h katastasi tou oximatos ekserevnisis einai false ki an nai
          {                                             // tote vriskei to 1o oxima diaswsis pou einai energo kai to stelnei na ftiaksei to ekserevnisis
              for(int j=0; j<diaswstika.size(); j++)
              {
                 if(diaswstika[j]->getKatastasi() == true)
                 {
                    diaswstika[j]->leitourgia(ekserevnitika[i]->getX(), ekserevnitika[i]->getY());
                    break;
                 }
              }
          }
       }

       for(int i=0; i<diaswstika.size(); i++)
       {
          if(diaswstika[i]->getKatastasi() == false) // tsekarei an h katastasi tou oximatos diaswsis einai false ki an nai
          {                                             // tote vriskei to 1o oxima diaswsis pou einai energo kai to stelnei na ftiaksei to xalasmeno diaswsis
              for(int j=0; j<diaswstika.size(); j++)
              {
                 if(diaswstika[j]->getKatastasi() == true)
                 {
                    diaswstika[j]->leitourgia(diaswstika[j]->getX(), diaswstika[j]->getY());
                    break;
                 }
              }
          }
       }

       for(int i=0; i<analitika.size(); i++)
       {
          if(analitika[i]->getKatastasi() == false) // tsekarei an h katastasi tou oximatos analisis einai false ki an nai
          {                                             // tote vriskei to 1o oxima diaswsis pou einai energo kai to stelnei na ftiaksei to eanalisis
              for(int j=0; j<diaswstika.size(); j++)
              {
                 if(diaswstika[j]->getKatastasi() == true)
                 {
                    diaswstika[j]->leitourgia(analitika[i]->getX(), analitika[i]->getY());
                    break;
                 }
              }
          }
       }
       for(int i=0; i<ekserevnitika.size(); i++)
       {

           ekserevnitika[i]->leitourgia(ekserevnitika[i]->getX(), ekserevnitika[i]->getY());
       }

       for(int i=0; i<diaswstika.size(); i++)
       {
           diaswstika[i]->leitourgia(diaswstika[i]->getX(), diaswstika[i]->getY());
       }
       for(int i=0; i<analitika.size(); i++)
       {
           analitika[i]->leitourgia(analitika[i]->getX(), analitika[i]->getY());
       }
       for(int z=0; z<ekserevnitika.size(); z++) // typwnontai ta stoixeia kathe ekserevnitikou oximatos
       {
           cout << "To " <<z+1<<"o oxima ekserevnisis exei ta parakatw xaraktiristika se ayton ton gyro:" <<endl;
           ekserevnitika[z]->print();
       }
       for(int z=0; z<diaswstika.size(); z++) // typwnontai ta stoixeia kathe oximatos diaswsis
       {
           cout << "To " <<z+1<<"o oxima diaswshs exei ta parakatw xaraktiristika se ayton ton gyro:" <<endl;
           diaswstika[z]->print();
       }
       for(int z=0; z<analitika.size(); z++)  // typwnontai ta stoixeia kathe oximatos analisis
       {
           cout << "To " <<z+1<<"o oxima analisis exei ta parakatw xaraktiristika se ayton ton gyro:" <<endl;
           analitika[z]->print();
       }
       for(int k=0; k<ekserevnitika.size(); k++)
       {
           if(ekserevnitika[k]->getKatastasi()==false)
           {
               xalasmena++;
           }
       }
       for(int k=0; k<diaswstika.size(); k++)
       {
           if(diaswstika[k]->getKatastasi() == false)
           {
               xalasmena++;
           }
       }
       for(int k=0; k<analitika.size(); k++)
       {
           if(analitika[k]->getKatastasi()==false)
           {
               xalasmena++;
           }
       }
       synolo = diaswstika.size()+ekserevnitika.size()+analitika.size(); // synolo -- to synolo olwn twn oxhmatwn
       if(xalasmena == synolo) // an ola ta oxhmata xalasoun termatizei h prosomoiwsh
       {
           ola = 1;
           cout << "Dystyxws ola ta oximata xalasane." << endl;
           cout << "---------------------------------" << endl;
           cout << "---------  GAME OVER  -----------" << endl;
           cout << "---------------------------------" << endl;
       }
       if((Xarths::perLeyk[4][4] >= 2.0)&&(Xarths::perIr[4][4] >= 1.8)&&(Xarths::perPal[4][4] >= 1.9))// an ta apothemata sth vash ftasoun to megisto orio
       {                                                                            // h prosomoiwsh termatizei epityxws
           ola = 1;
           cout << "Sygxaritiria ta apothemata sth vash eftasan to megisto orio." << endl;
           cout << "---------H prosomoiwsh oloklirwthike me epityxia.-----------" << endl;
           cout << "------------------------------------------------------------" << endl;

       }
    Sleep(1600);
   }while(ola == 1);
  return 0;
}
