#include "SERVICES.h"
#include<COMPTE.h>
#include<EPARGNE.h>
#include<CHEQUE.h>
#include<FICHIER.h>
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
    FICHIER *F = new FICHIER();
    do
    {
        system("cls");
        do
        {
            cin.ignore();
            cout << "\n\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU COMPTE " << endl;
            cout << "\t\t      EPARGNE (E) - CHEQUE (C)" << endl;
            cout << "\t\tVOTRE CHOIX : ";
            cin >> rep;
        }
        while(rep != 'E' && rep != 'C');
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
            cout << "\t\tTAUX D'INTERET DU COMPTE : " ;
            cin >> val;
        }
        while(val <= 0 || val >= 50);

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
        F->addCompte(cp);
        // ici on ajoute dans le fichier

        cout << "\n COMPTE CREE AVEC SUCCES !! \n " << endl;

        do
        {
            cin.ignore();
            cout << "\n\t\tUN AUTRE COMPTE ? [O/N] : ";
            cin >> rep;
        }
        while(rep != 'O' && rep != 'N' && rep != 'o' && rep != 'n');
    }
    while(rep == 'O' || rep == 'o');
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
    COMPTE *cp, *cp2;
    int choix, ok = 0;
    string num;
    char rep;
    FICHIER *F = new FICHIER();


    do
    {
        cin.ignore();
        cout << "\n\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU COMPTE " << endl;
        cout << "\t\t RETRAIT (R) - DEPOT (D) - VIREMENT (V)" << endl;
        cout << "\t\tVOTRE CHOIX : ";
        cin >> rep;
    }
    while(rep != 'R' && rep != 'V' && rep != 'D');

    cout << "\t\tSAISIR LE NUMERO DU COMPTE : " ;
    cin >> num;
    cp = this->searchCompte(num,(*comptes));
    if(cp != NULL)
    {
        double mnt;
        cout << "\t\tSAISIR LE MONTANT : " ;
        cin >> mnt;
        t->Setmnt(mnt);
        if(rep == 'R')
        {
            t->Settype(RETRAIT);
            if(cp->isCheque() == 0)
            {
                if((dynamic_cast<EPARGNE*>(cp))->retirer(t->Getmnt()) == 1)
                {
                    ok=1;
                }
            }
            else
            {
                if((dynamic_cast<CHEQUE*>(cp))->retirer(t->Getmnt()) == 1)
                {
                    ok=1;
                }
            }
        }
        else
        {
            if(rep == 'V')
            {
                t->Settype(VIREMENT);
                cout << "\t\tSAISIR LE NUMERO DU COMPTE DESTINATAIRE : " ;
                cin >> num;
                cp2 = this->searchCompte(num,(*comptes));
                if(cp2 == NULL)
                {
                    cout << "\t\tNUMERO DE COMPTE INVALIDE \n" << endl;
                }
                else
                {
                    if(cp->isCheque() == 0)
                    {
                        if((dynamic_cast<EPARGNE*>(cp))->virement(t->Getmnt(),cp2) == 1)
                        {
                            ok=1;
                        }
                    }
                    else
                    {
                        if((dynamic_cast<CHEQUE*>(cp))->virement(t->Getmnt(),cp2) == 1)
                        {
                            ok=1;
                        }
                    }
                }
            }
            else
            {
                t->Settype(VERSEMENT);
                if(cp->isCheque() == 0)
                {
                    (dynamic_cast<EPARGNE*>(cp))->verser(t->Getmnt());
                }
                else
                {
                    (dynamic_cast<CHEQUE*>(cp))->verser(t->Getmnt());
                }
                ok = 1;
            }
        }
        if(ok == 1)
        {
            cout << "\t\tTRANSACTION EFFECTUEE !! \n" << endl;
            vector<TRANSACTION*> ok = cp->GetTransactions();
            ok.push_back(t);
            cp->SetTransactions(ok);
            updateVector(comptes,cp);
            F->addTransaction(t,cp->Getnum());
            F->addAllCompte((*comptes));
        }
        else
        {
            cout << "\t\tTRANSACTION ECHOUEE !! \n" << endl;
        }
    }
    else
    {
        cout << "\t\tNUMERO DE COMPTE INVALIDE \n" << endl;
    }
}

void SERVICES::allTransaction(vector<COMPTE*> comptes)
{
    int i, j;
    cout << "\n\n\t\tLISTE TRANSACTIONS" << endl;
    cout << "\t\t=====================\n\n" << endl;
    for(i=0; i<comptes.size(); i++)
    {
        vector<TRANSACTION*> cpTrans = comptes[i]->GetTransactions();
        for(j=0; j<cpTrans.size(); j++)
        {
            cout << cpTrans[j]->toString() << endl;
            cout << "\t\t===========================================\n\n" << endl;
        }
    }
}

void SERVICES::transByCompte(vector<COMPTE*> comptes)
{
    int i;
    string num;
    COMPTE  *cp;
    cout << "\n\t\tSAISIR LE NUMERO DU COMPTE : " ;
    cin >> num;
    cp = this->searchCompte(num,comptes);
    if(cp == NULL)
    {
        cout << "\t\tNUMERO DE COMPTE INVALIDE \n" << endl;
    }
    else
    {
        cout << "\n\n\t\tLISTE TRANSACTIONS DU COMPTE" << endl;
        cout << "\t\t================================\n\n" << endl;
        vector<TRANSACTION*> cpTrans = cp->GetTransactions();
        for(i=0; i<cpTrans.size(); i++)
        {
            cout << cpTrans[i]->toString() << endl;
            cout << "\t\t===========================================\n\n" << endl;
        }
    }
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

void SERVICES::updateVector(vector<COMPTE*> *comptes, COMPTE * cp)
{
    int i, j;
    for(i=0; i<(*comptes).size(); i++)
    {
        if((*comptes)[i]->Getid() == cp->Getid())
        {
            //system("pause");
            //cout << cp->GetTransactions().at(0)->getTypestring() << endl ;
            (*comptes).at(i) = cp;
            //cout << (*comptes).at(i)->GetTransactions().at(0)->getTypestring() << endl ;
        }
    }
}

vector<COMPTE*> SERVICES::loadComptes()
{
    FICHIER *F = new FICHIER();
    int i, j, k;


    vector<TRANSACTION*> trans = F->getAllTransactions();
    vector<COMPTE*> comptes = F->getAllComptes();

    for(i=0; i<comptes.size(); i++)
    {
        vector<TRANSACTION*> comptTrans;
        comptTrans.clear();

        for(j=0; j<trans.size(); j++)
        {
            if(trans[j]->GetnumCompte() == comptes[i]->Getnum())
            {
                comptTrans.push_back(trans[j]);
            }
        }

        comptes[i]->SetTransactions(comptTrans);
    }

    return comptes;
}
