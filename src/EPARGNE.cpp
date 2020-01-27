#include "EPARGNE.h"
#include "COMPTE.h"
#include "DATE.h"
#include <ctime>
#include<sstream>

using namespace modeles;

EPARGNE::EPARGNE():COMPTE()
{
    //ctor
    dateFinB = new DATE();
}

EPARGNE::~EPARGNE()
{
    //dtor
}
string EPARGNE::toString()
{
    stringstream a;
    a << COMPTE::toString() << "\t\tTAUX          : " << taux << "\n" << "\t\tDATE FIN BL   : " << dateFinB->affiche() ;
    return a.str();
}

///retourne 0 si date1 > date2
int compareDate(DATE *date1, DATE *date2)
{
    if(date1->Getaa() > date2->Getaa())
    {
        return 0;
    }
    else
    {
        if(date1->Getaa() < date2->Getaa())
        {
            return 1;
        }
        else
        {
            if(date1->Getmm() > date2->Getmm())
            {
                return 0;
            }
            else
            {
                if(date1->Getmm() < date2->Getmm())
                {
                    return 1;
                }
                else
                {
                    if(date1->Getmm() > date2->Getmm())
                    {
                        return 0;
                    }
                    else
                    {
                        if(date1->Getjj() >= date2->Getjj())
                        {
                            return 0;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}

int EPARGNE::retirer(double mnt)
{
    DATE* today = new DATE();
    time_t actuel = time(0);
    int ok = 0;
    tm *ltm = localtime(&actuel);

    /* cout << "Nombre de sec depuis Janvier 1,1970:" << actuel << endl;
    // afficher divers member de la structure tm.
    cout << "Année" << 1900 + ltm->tm_year<<endl;
    cout << "Mois: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Jour: "<< 1 + ltm->tm_hour << " : ";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl; */

    today->Setaa(1900 + ltm->tm_year);
    today->Setmm(1 + ltm->tm_mon);
    today->Setjj(ltm->tm_mday);
    if(compareDate(dateFinB, today) == 0)
    {
        return 0;
    }
    else
    {
        if(solde >= mnt)
        {
            solde -= mnt;
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int EPARGNE::verser(double mnt)
{
    int valeur;
    valeur = mnt + (mnt * taux);
    solde += valeur;
    return 1;
}

int EPARGNE::virement(double mnt, COMPTE* cp)
{

}

