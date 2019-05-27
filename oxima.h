#ifndef OXIMA_H
#define OXIMA_H
#include <vector>
#include "Xarths.h"
#include <string>

class oxima
{
     public:
        oxima(); //arxikopoihsh metavlitwn taxitita,katastasi,ikanotita prosvashs, ar_thesewn, ar_vlavwn, x, y antistoixa
        virtual ~oxima();
        void setTaxitita(int);
        int getTaxitita();
        void setKatastasi(bool);
        bool getKatastasi();
        int getAr_theseis();
        void setAr_theseis(int );
        int getAr_vlavwn();
        void setAr_vlavwn(int);
        void setX(int);
        int getX();
        void setY(int);
        int getY();
        void setProsvasi(float);
        double getProsvasi();
        void vlavi(int, int, bool );        // synartisi pou deixnei thn pithanotita vlavis
        void metakinisi();    // synartisi metakinisisis
        virtual void leitourgia();
        void print();
        std::string getEidos(int, int);
        void setEidos(int ,int ,std::string);
        void setIridio(double);
        double getIridio();
        void setPalladio(double);
        double getPalladio();
        void setLeykoxrysos(double);
        double getLeykoxrysos();


     protected:
        int taxitita;
        bool katastasi;  // deixnei an exei h oxi vlavi analoga an einai true h false
        float prosvasi;    // ikanotita prosvasis oximatos-times apo 0.1 ews 1
        int ar_theseis;   // poses theseis metakinithike ap tin arxi tis eksomiosis
        int ar_vlavwn;      // poses vlaves exei ypostei apo tin arxi tis eksomiosis
        int hi;
        int psi;
        int x;        // h thesh x ston disdiastato kosmo
        int y;           // h thesh y ston disdiastato kosmo
        std::string eidos;          // to eidos tou oximatos. times: 'A' gia analisis, 'D' gia diaswsis kai 'E' gia ekserevnisis
        double iridio;    // h posotita iridiou, palladiou kai leykoxrysou pou kouvalaei kathe oxima
        double palladio;
        double leykoxrysos;
        int prosX;  // proswrino X kai proswrino Y(apo katw) einai oi proswrines syntetagmenes tou oximatos
        int prosY;   // praktika h prosX kai i prosY einai voithitikes metavlites
};

#endif // OXIMA_H
