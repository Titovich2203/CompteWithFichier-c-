#include "CHEQUE.h"
#include "COMPTE.h"
#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace modeles;
using namespace std;

CHEQUE::CHEQUE():COMPTE()
{
    //ctor
}

CHEQUE::~CHEQUE()
{
    //dtor
}

string CHEQUE::toString()
{
    stringstream a;
    a << COMPTE::toString() << "\t\tTAUX          : " << interet << "\n" ;
    return a.str();
}

int CHEQUE::retirer(double mnt)
{
    int valeur;
    valeur = mnt + (mnt * interet);
    if(solde >= valeur)
    {
        solde -= valeur;
        return 1;
    }
    else
    {
        return 0;
    }
}

int CHEQUE::verser(double mnt)
{
    int valeur;
    valeur = mnt - (mnt * interet);
    solde += valeur;
    return 1;
}

int CHEQUE::virement(double mnt, COMPTE* cp)
{

}
