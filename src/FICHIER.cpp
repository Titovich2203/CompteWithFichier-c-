#include "FICHIER.h"
#include<iostream>
#include<fstream>

using namespace modeles;
using namespace std;

FICHIER::FICHIER()
{
    //ctor
    /*
    const string nameCompte("fichiers/comptes.txt");
    const string nameTrans("fichiers/transactions.txt");
    nomFC = nameCompte;
    nomFT = nameTrans;
    */
}

FICHIER::~FICHIER()
{
    //dtor
}

void FICHIER::addCompte(COMPTE* p)
{

}

void FICHIER::addTransaction(TRANSACTION* t)
{

}

vector<COMPTE*> FICHIER::getAllComptes()
{

}

vector<TRANSACTION*> FICHIER::getAllTransactions()
{

}
