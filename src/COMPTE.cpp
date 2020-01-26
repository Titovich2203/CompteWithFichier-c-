#include "COMPTE.h"
#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace modeles;
using namespace std;

unsigned int COMPTE::cpt = 0;

COMPTE::COMPTE()
{
    //ctor
    cpt++;
    id = cpt;
    num = genereNumCompte();
    solde = 0;
}

COMPTE::~COMPTE()
{
    //dtor
}

string COMPTE::toString()
{
    ostringstream a;
    a << "\t\tID            : " << id << "\n\t\tNUM           : " << num << "\n\t\tSOLDE         : " << solde << "\n" ;
    return a.str();
}

string COMPTE::genereNumCompte()
{
    ostringstream a;
    a.str("");
    a << "CP000" <<id;
    return a.str();
}

