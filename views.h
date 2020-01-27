#ifndef VIEWS_H_INCLUDED
#define VIEWS_H_INCLUDED
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

namespace views
{
    int saisieEntier(string msg)
    {
        string chaine;
        int x;
        cout << msg ; cin >> chaine;
        try
        {
            long nbL = strtol(chaine.c_str(), NULL, 10);
            x = (int)nbL;
            return x;
        }
        catch(exception e)
        {
            return 0;
        }
    }
    int menuPrincipal()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU PRINCIPAL \n\n" << endl;
        cout << "\n\t\t1-----------                 COMPTES \n" << endl;
        cout << "\t\t2-----------                 TRANSACTIONS \n" << endl;
        cout << "\t\t3-----------                 QUITTER \n" << endl;
        do
        {

            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 3);
        return choix;
    }
    int menuCompte()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU COMPTE \n\n" << endl;
        cout << "\n\t\t1-----------                 NEW COMPTE \n" << endl;
        cout << "\t\t2-----------                 LISTE DES COMPTES EPARGNE \n" << endl;
        cout << "\t\t3-----------                 LISTE DES COMPTES CHEQUE \n" << endl;
        cout << "\t\t4-----------                 RETOUR \n" << endl;
        cout << "\t\t5-----------                 QUITTER \n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 5);
        return choix;
    }
    int menuTransaction()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU TRANSACTION \n\n" << endl;
        cout << "\n\t\t1-----------                 NEW TRANSACTION \n" << endl;
        cout << "\t\t2-----------                 LISTE DES TRANSACTIONS \n" << endl;
        cout << "\t\t3-----------                 LISTE DES TRANSACTIONS POUR UN COMPTE \n" << endl;
        cout << "\t\t4-----------                 RETOUR \n" << endl;
        cout << "\t\t5-----------                 QUITTER \n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 5);
        return choix;
    }
};

#endif // VIEWS_H_INCLUDED
