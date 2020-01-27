#include "TRANSACTION.h"
#include<iostream>
#include<ctime>
#include<DATE.h>

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

}
