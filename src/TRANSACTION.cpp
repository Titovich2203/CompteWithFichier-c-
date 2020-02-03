#include "TRANSACTION.h"
#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
#include<DATE.h>

using namespace std;
using namespace modeles;

unsigned int TRANSACTION::cpt = 0;

TRANSACTION::TRANSACTION()
{
    //ctor
    cpt++;
    id = cpt;
    date = new DATE();

    //DATE ACTUELLE

    time_t actuel = time(0);
    int ok = 0;
    tm *ltm = localtime(&actuel);
    date->Setaa(1900 + ltm->tm_year);
    date->Setmm(1 + ltm->tm_mon);
    date->Setjj(ltm->tm_mday);
}

TRANSACTION::~TRANSACTION()
{
    //dtor
}
string TRANSACTION::toString()
{
    stringstream a;
    a << "\t\tID            : " << id << "\n" << "\t\tDATE          : " << date->affiche() << "\n" << "\t\tMNT           : " << mnt << "\n" << "\t\tTYPE          : " << getTypestring() << "\n" ;
    return a.str();
}

string TRANSACTION::getTypestring()
{
    if(type == VERSEMENT) return "VERSEMENT";
    if(type == RETRAIT) return "RETRAIT";
    if(type == VIREMENT) return "VIREMENT";
    return "";
}
