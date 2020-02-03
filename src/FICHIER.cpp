#include "FICHIER.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<stdio.h>
#include <string>
#include <cstdlib>

using namespace modeles;
using namespace std;
string const nomCompte("fichier/comptes.txt");
string const nomTransaction("fichier/transactions.txt");
FICHIER::FICHIER()
{
    //ctor
    this->nomFC = nomCompte;
    this->nomFT = nomTransaction;
}

FICHIER::~FICHIER()
{
    //dtor
}

int FICHIER::addCompte(COMPTE* p)
{

    ofstream fluxCompte(nomFC.c_str(), ios::app);
    if(fluxCompte)
    {
        if(p->isCheque()==0)
        {
            EPARGNE * e = (dynamic_cast<EPARGNE*>(p));
            fluxCompte<<e->Getid()<<"|"<<e->Getnum()<<"|"<<e->Getsolde()<<"|"<<e->isCheque()<<"|"<<e->Gettaux()<<"|"<<e->Getdate()->Getjj()<<"|"<<e->Getdate()->Getmm()<<"|"<<e->Getdate()->Getaa()<<endl;
        }else
        {
            CHEQUE * ch = (dynamic_cast<CHEQUE*>(p));
            fluxCompte<<ch->Getid()<<"|"<<ch->Getnum()<<"|"<<ch->Getsolde()<<"|"<<ch->isCheque()<<"|"<<ch->Getinteret()<<endl;
        }
        return 1;
    }
    return 0;
}

vector<string> explode( const string &delimiter, const string &str)
{
    vector<string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0)
        return arr;//no change

    int i=0;
    int k=0;
    while( i<strleng )
    {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}

vector<COMPTE*> FICHIER::getAllComptes()
{
    vector<COMPTE*> vectCompte;
    ifstream fluxCompte(nomFC.c_str());
    if(fluxCompte)
    {
        string ligne;
        while(getline(fluxCompte,ligne))
        {
            vector<string> v = explode("|", ligne);
            stringstream geek(v[3]);
            int cheque;
            geek >> cheque;
            if(cheque==0)
            {
                EPARGNE * e = new EPARGNE();
                ///Conversion id
                stringstream geek1(v[0]);
                int id;
                geek1 >> id;
                e->Setid(id);
                //
                e->Setnum(v[1]);
                ///Conversion Solde
                stringstream geek2(v[2]);
                double solde;
                geek2 >> solde;
                e->Setsolde(solde);
                ///Conversion Taux
                stringstream geek3(v[4]);
                double taux;
                geek3 >> taux;
                e->Settaux(taux);
                ///Creation Date
                DATE * date = new DATE();
                ///Conversion Jour
                stringstream geek4(v[5]);
                int jj;
                geek4 >> jj;
                date->Setjj(jj);
                ///Conversion mois
                stringstream geek5(v[6]);
                int mm;
                geek5 >> mm;
                date->Setmm(mm);
                ///Conversion annee
                stringstream geek6(v[7]);
                int aa;
                geek6 >> aa;
                date->Setaa(aa);
                e->Setdate(date);

                vectCompte.push_back(e);
            }else
            {
                CHEQUE * ch = new CHEQUE();
                ///Conversion id
                stringstream geek1(v[0]);
                int id;
                geek1 >> id;
                ch->Setid(id);
                //
                ch->Setnum(v[1]);
                ///Conversion Solde
                stringstream geek2(v[2]);
                double solde;
                geek2 >> solde;
                ch->Setsolde(solde);
                ///Conversion Interet
                stringstream geek3(v[4]);
                double interet;
                geek3 >> interet;
                ch->Setinteret(interet);

               vectCompte.push_back(ch);
            }
        }
    }
    return vectCompte;
}

int FICHIER::addTransaction(TRANSACTION* t)
{
    ofstream fluxTr(nomFT.c_str(), ios::app);
    if(fluxTr)
    {
        fluxTr<<t->Getid()<<"|"<<t->Getmnt()<<"|"<<t->Gettype()<<"|"<<t->Getdate()->Getjj()<<"|"<<t->Getdate()->Getmm()<<"|"<<t->Getdate()->Getaa()<<endl;
        return 1;
    }
    return 0;
}

vector<TRANSACTION*> FICHIER::getAllTransactions()
{
    vector<TRANSACTION*> vectTr;
    ifstream fluxTr(nomFT.c_str());
    if(fluxTr)
    {
        string ligne;
        while(getline(fluxTr,ligne))
        {
            TRANSACTION * tr = new TRANSACTION();
            vector<string> v = explode("|", ligne);
            stringstream geek(v[0]);
            int id;
            geek >> id;
            tr->Setid(id);

            stringstream geek1(v[1]);
            int mnt;
            geek1 >> mnt;
            tr->Setmnt(mnt);

            stringstream geek2(v[2]);
            int type;
            geek2 >> type;
            tr->Settype(type);

           ///Creation Date
            DATE * date = new DATE();
            ///Conversion Jour
            stringstream geek3(v[3]);
            int jj;
            geek3 >> jj;
            date->Setjj(jj);
            ///Conversion mois
            stringstream geek4(v[4]);
            int mm;
            geek4 >> mm;
            date->Setmm(mm);
            ///Conversion annee
            stringstream geek5(v[5]);
            int aa;
            geek5 >> aa;
            date->Setaa(aa);
            tr->Setdate(date);

            vectTr.push_back(tr);
        }
    }
    return vectTr;
}
