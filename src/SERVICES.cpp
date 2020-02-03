#include "SERVICES.h"
#include<COMPTE.h>
#include<EPARGNE.h>
#include<CHEQUE.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>

using namespace std;
using namespace modeles;
using namespace services;

SERVICES::SERVICES()
{
    //ctor
}

SERVICES::~SERVICES()
{
    //dtor
}
void SERVICES::newCompte(vector<COMPTE*> *comptes)
{
    COMPTE *cp;
    char rep;
    double val;
    do
    {
        system("cls");
        do
        {
            cin.ignore();
            cout << "\n\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU COMPTE " << endl;
            cout << "\t\t      EPARGNE (E) - CHEQUE (C)" << endl;
            cout << "\t\tVOTRE CHOIX : "; cin >> rep;
        }while(rep != 'E' && rep != 'C');
        if(rep == 'E')
        {
            cp = new EPARGNE();
        }
        if(rep == 'C')
        {
            cp = new CHEQUE();
        }

        //AFFICHAGE DES DONNEES DE COMPTE (ID, NUM, SOLDE)
        cout << "\n\n\t\tID            : " << cp->Getid() << "\n\t\tNUM           : " << cp->Getnum() << "\n\t\tSOLDE         : " << cp->Getsolde() << "\n" << endl ;
        //AFFICHAGE DES DONNEES DE COMPTE (ID, NUM, SOLDE)
        do
        {
            cout << "\t\tTAUX D'INTERET DU COMPTE : " ; cin >> val;
        }while(val <= 0);

        if(rep == 'E')
        {
            (dynamic_cast<EPARGNE*>(cp))->Settaux(val);
            cout << "\n\t\tDATE DE FIN DE BLOCAGE \n" << endl;
            (dynamic_cast<EPARGNE*>(cp))->Getdate()->saisie();

        }
        if(rep == 'C')
        {
            (dynamic_cast<CHEQUE*>(cp))->Setinteret(val);
        }


        (*comptes).push_back(cp);
        // ici on ajoute dans le fichier

        cout << "\n COMPTE CREE AVEC SUCCES !! \n " << endl;

        do
        {
            cin.ignore();
            cout << "\n\t\tUN AUTRE COMPTE ? [O/N] : "; cin >> rep;
        }while(rep != 'O' && rep != 'N' && rep != 'o' && rep != 'n');
    }while(rep == 'O' || rep == 'o');
}

void SERVICES::listCompteEpargne(vector<COMPTE*> comptes)
{
    cout << "\n\n\t\tLISTE COMPTES EPARGNE" << endl;
    cout << "\t\t=====================\n\n" << endl;
    for(int i=0; i<comptes.size(); i++)
    {
        if(comptes[i]->isCheque() == 0)
        {

            cout << comptes[i]->toString() << endl;
            cout << "\t\t===========================================\n\n" << endl;
        }
    }
}

void SERVICES::listCompteCheque(vector<COMPTE*> comptes)
{
    cout << "\n\n\t\tLISTE COMPTES CHEQUE" << endl;
    cout << "\t\t=====================\n\n" << endl;
    for(int i=0; i<comptes.size(); i++)
    {
        if(comptes[i]->isCheque() == 1)
        {

            cout << comptes[i]->toString() << endl;
            cout << "\t\t===========================================\n\n" << endl;
        }
    }
}

void SERVICES::newTransaction(vector<COMPTE*> *comptes)
{
    TRANSACTION *t = new TRANSACTION();
    COMPTE *cp;
    int choix;
    string num;
    char rep;

     do
        {
            cin.ignore();
            cout << "\n\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU COMPTE " << endl;
            cout << "\t\t      RETRAIT (R) - VERSEMENT (V)" << endl;
            cout << "\t\tVOTRE CHOIX : "; cin >> rep;
        }while(rep != 'R' && rep != 'V');

     cout << "\t\tSAISIR LE NUMERO DU COMPTE" << endl;
     cin >> num;
    cp = this->searchCompte(num,(*comptes));
    if(cp != NULL)
    {
        cout << "\t\tSAISIR LE MONTANT A RETIRER" << endl;
        double mnt;
        cin >> mnt;
        t->Setmnt(mnt);
        if(rep == 'R')
        {
            if(cp->isCheque() == 0)
            {
                (dynamic_cast<EPARGNE*>(cp))->retirer(t->Getmnt());
            }
            else
            {
                (dynamic_cast<CHEQUE*>(cp))->retirer(t->Getmnt());
            }
        }else{
            if(cp->isCheque() == 0)
            {
                (dynamic_cast<EPARGNE*>(cp))->verser(t->Getmnt());
            }
            else
            {
                (dynamic_cast<CHEQUE*>(cp))->verser(t->Getmnt());
            }
        }
    }
}

void SERVICES::allTransaction(vector<COMPTE*> comptes)
{

}

void SERVICES::transByCompte(vector<COMPTE*> comptes)
{

}

COMPTE* SERVICES::searchCompte(string num, vector<COMPTE*> comptes)
{
    for(int i=0; i<comptes.size(); i++)
    {
        if(comptes[i]->Getnum()==num)
        {
            return comptes[i];
        }
    }
    return NULL;
}
